#include "GLWindow.h"
#include <boost/foreach.hpp>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "ngl/Light.h"
#include "ngl/Transformation.h"
#include <ngl/TransformStack.h>
#include "ngl/Material.h"
#include "ngl/NGLInit.h"
#include "ngl/Obj.h"
#include "ngl/VAOPrimitives.h"
#include "ngl/ShaderLib.h"
#include "ngl/Util.h"
#include "ngl/Util.h"
#include "ngl/BezierCurve.h"
#include <ctime>
#include "Boid.h"
#include "BoidManager.h"
#include <ngl/Random.h>


//----------------------------------------------------------------------------------------------------------------------
GLWindow::GLWindow(
                   QWidget *_parent
                  ) :
                    QGLWidget(_parent)
{
  // set this widget to have the initial keyboard focus
  setFocus();
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
  this->resize(_parent->size());
  // set wireframe mode off as default
  m_wireframe=false;
  m_mass = 18.0;
  m_sep = 8.0;
  m_coh = 40.0;
  m_ali = 8.0;
  m_numboids = 40;
  m_numpredators = 1;
  // Now set the initial GLWindow attributes to default values
  // Roate is false
  m_rotate=false;
  // mouse rotation values set to 0
  m_spinXFace=0;
  m_spinYFace=0;
  //m_origX=0;
  //m_origY=0;
        // now we start a timer and assign it to the m_animationTimer variable
        // this will be triggered at an interval of every 20ms
        // to stop this timer we call killTimer(m_animationTimer) we can have
        // multiple timers but each must have it's own ID
        m_animationTimer=startTimer(20);
        m_goalTimer=startTimer(20);
        m_animate=false;
        //m_bbox = new ngl::BBox(ngl::Vector(0,0,0),100,100,100);
}

//----------------------------------------------------------------------------------------------------------------------
GLWindow::~GLWindow()
{
        // call the static NGLQuit method to close down
        // NGL and tidy up any shaders textures etc
        // first get an instance of the NGLInit singleton
        ngl::NGLInit *ngl = ngl::NGLInit::instance();
        // then call the quit method
        ngl->NGLQuit();
}

//----------------------------------------------------------------------------------------------------------------------
// This virtual function is called once before the first call to paintGL() or resizeGL(),
//and then once whenever the widget has been assigned a new QGLContext.
// This function should set up any required OpenGL context rendering flags, defining display lists, etc.
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
        // basically we do our main OpenGL setup here
        // set the clear colour in this case to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        // enable depth testing for drawing
        glEnable(GL_DEPTH_TEST);

        // before we can start any advanced OpenGL under windows or linux we need to
        // load in the extensions using GLEW mac will ignore this so it works for all
        // platforms, to do this we use the NGLInit class
        ngl::NGLInit *Init = ngl::NGLInit::instance();
        Init->initGlew();
        // Now we will create a basic Camera from the graphics library
        // This is a static camera so it only needs to be set once
        // First create Values for the camera position
        ngl::Vector From(0,0,-200);
        ngl::Vector To(0,0,0);
        ngl::Vector Up(0,1,0);
        // now we instantiate our camera
        m_cam= new ngl::Camera(From,To,Up,ngl::PERSPECTIVE);
        // set the shape using FOV 45 Aspect Ratio based on Width and Height
        // The final two are near and far clipping planes of 0.5 and 150
        m_cam->setShape(45,(float)1024/768,0.5,150,ngl::PERSPECTIVE);
        // now to load the shader and set the values
        // grab an instance of shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();


  shader->createShaderProgram("Phong");

   shader->attachShader("PhongVertex",ngl::VERTEX);
   shader->attachShader("PhongFragment",ngl::FRAGMENT);
   shader->loadShaderSource("PhongVertex","shaders/Phong.vs");
   shader->loadShaderSource("PhongFragment","shaders/Phong.fs");

   shader->compileShader("PhongVertex");
   shader->compileShader("PhongFragment");
   shader->attachShaderToProgram("Phong","PhongVertex");
   shader->attachShaderToProgram("Phong","PhongFragment");

   shader->bindAttribute("Phong",0,"inVert");

   shader->bindAttribute("Phong",1,"inUV");

   shader->bindAttribute("Phong",2,"inNormal");


   // now we have associated this data we can link the shader
   shader->linkProgramObject("Phong");
   // and make it active ready to load values
   (*shader)["Phong"]->use();
   shader->setShaderParam1i("Normalize",1);

   // now pass the modelView and projection values to the shader
   // the shader will use the currently active material and light0 so set them
   ngl::Material m(ngl::GOLD);
   m.loadToShader("material");

   m_light = new ngl::Light(ngl::Vector(2,2,2),ngl::Colour(1,1,1,1),ngl::Colour(1,1,1,1),ngl::POINTLIGHT);
   // now create our light this is done after the camera so we can pass the
   // transpose of the projection matrix to the light to do correct eye space
   // transformations
   ngl::Matrix iv=m_cam->getProjectionMatrix();
   iv.transpose();
   m_light->setTransform(iv);
   m_light->setAttenuation(1,0,0);
   m_light->enable();
   // load these values to the shader as well
   m_light->loadToShader("light");

   /// now for the colour shader
   shader->createShaderProgram("Colour");

   shader->attachShader("ColourVertex",ngl::VERTEX);
   shader->attachShader("ColourFragment",ngl::FRAGMENT);
   shader->loadShaderSource("ColourVertex","shaders/Colour.vs");
   shader->loadShaderSource("ColourFragment","shaders/Colour.fs");

   shader->compileShader("ColourVertex");
   shader->compileShader("ColourFragment");
   shader->attachShaderToProgram("Colour","ColourVertex");
   shader->attachShaderToProgram("Colour","ColourFragment");
   // bind our attributes for the vertex shader
   shader->bindAttribute("Colour",0,"inVert");


   // link the shader no attributes are bound
   shader->linkProgramObject("Colour");
   (*shader)["Colour"]->use();
   shader->setShaderParam4f("Colour",1,0,0,1);
   glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces

 /*
        // load a frag and vert shaders
        shader->loadShader("Blinn","shaders/Vertex.vs","shaders/Fragment.fs");
        // set this as the active shader
        shader->useShader("Blinn");
        // now pass the modelView and projection values to the shader
  shader->setShaderParamFromMatrix("Blinn","ViewMatrix",m_cam->getModelView());
  //shader->setShaderParamFromMatrix("Blinn","projectionMatrix",m_cam->getProjection());
        shader->loadShader("Colour","shaders/Colour.vs","shaders/Colour.fs");

                        // set this as the active shader
                  shader->useShader("Colour");
                        shader->setShaderParamFromMatrix("Colour","ViewMatrix",m_cam->getModelView());
                  //shader->setShaderParamFromMatrix("Colour","projectionMatrix",m_cam->getProjection());

                        shader->setShaderParam4f("Colour","Colour",1,1,1,1);*/

        m_flock = new BoidManager(m_numboids,m_numpredators);

      //  m_bbox = new ngl::BBox(ngl::Vector(0,0,0),100,100,100);

        m_lattice = new Lattice(100);

        m_scene = new Scene();

        loadCurves();

        //creates a goal for each curve imported from maya
        BOOST_FOREACH(ngl::BezierCurve *c, m_curves)
        {
            Goal *goal = new Goal(c);
            m_goals.push_back(goal);
            //std::cout<<m_goal.getPos()<<std::endl;

        }


}
//loads the curve from the curve file
void GLWindow::loadCurves()
{
  QFile file("curves/l.curve");
   QString line;
   int index=-1;
   if ( file.open(QIODevice::ReadOnly ) )
   {
     // file opened successfully
     QTextStream t( &file );        // use a text stream
     // until end of file...
     while ( !t.atEnd())
     {

       line = t.readLine();
       //std::cout<<"line "<<line.toStdString()<<"\n";
       QStringList lines=line.split(" ");
       if(lines[0]=="Curve")
       {
         std::cout<<"got curve \n";
         ngl::BezierCurve *curve=new ngl::BezierCurve();
         m_curves.push_back(curve);



         ++index;
       }
       else if(lines[0]=="P")
       {
         std::cout<<"adding at index"<<index<<"\n";
         std::cout<<"p "<<lines[1].toFloat()<<" "<<lines[2].toFloat()<<" "<<lines[3].toFloat()<<"\n";
         m_curves[index]->addPoint(lines[1].toFloat(),lines[2].toFloat(),lines[3].toFloat());
       }
       // line of text excluding '\n'
     }
     // Close the file
     file.close();
   }
   std::cout<<"done file read\n";
   BOOST_FOREACH(ngl::BezierCurve *p, m_curves)
   {
     p->setLOD(200);
     p->createKnots();
     p->createVAO();
   }
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget has been resized.
// The new size is passed in width and height.
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::resizeGL(
                        int _w,
                        int _h
                       )
{
  glViewport(0,0,_w,_h);
  m_cam->setShape(45,(float)_w/_h,0.5,150,ngl::PERSPECTIVE);
}
  /*ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Blinn"]->use();

  shader->setShaderParamFromMatrix("Blinn","projectionMatrix",m_cam->getProjection());
  (*shader)["Colour"]->use();
          shader->setShaderParamFromMatrix("Colour","projectionMatrix",m_cam->getProjection());*/
void GLWindow::loadMatricesToShader(
                                     ngl::TransformStack &_tx
                                   )
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Phong"]->use();

  ngl::Matrix MV;
  ngl::Matrix MVP;
  ngl::Mat3x3 normalMatrix;
  ngl::Matrix M;
  M=_tx.getCurrentTransform().getMatrix();
  MV=_tx.getCurrAndGlobal().getMatrix() * m_cam->getViewMatrix();
  MVP=MV * m_cam->getProjectionMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMatrix("MV",MV);
  shader->setShaderParamFromMatrix("MVP",MVP);
  shader->setShaderParamFromMat3x3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMatrix("M",M);
}

void GLWindow::loadMatricesToColourShader(
                                           ngl::TransformStack &_tx
                                         )
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Colour"]->use();
  ngl::Matrix MV;
  ngl::Matrix MVP;

  MV= _tx.getCurrAndGlobal().getMatrix() * m_cam->getViewMatrix();
  MVP=MV * m_cam->getProjectionMatrix();
  shader->setShaderParamFromMatrix("MVP",MVP);

}


//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if(m_wireframe == true)
  {
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  }
  else
  {
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  }

 // build our transform stack
  ngl::Transformation trans;
  // set the mouse rotation
  trans.setRotation(m_spinXFace,m_spinYFace,0);
  // set this in the TX stack
  m_transformStack.setGlobal(trans);

  // now load these values to the shader

  loadMatricesToColourShader(m_transformStack);
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Colour"]->use();
  shader->setShaderParam4f("Colour",1,0,0,1);

  loadMatricesToShader(m_transformStack);
  //ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Phong"]->use();
  //loadMatricesToShader(m_transformStack);

  //ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  //(*shader)["Colour"]->use();

  //shader->use("Phong");

  m_flock->draw(m_transformStack,  m_cam, "Phong","Colour");

  //m_goals->draw(m_transformStack, m_cam, "Colour");

  BOOST_FOREACH(Goal *goal, m_goals)
  {
      goal->draw(m_transformStack, m_cam, "Phong");
     // m_goals.push_back(goal);
      //std::cout<<m_goal.getPos()<<std::endl;

  }



 // (*shader)["Colour"]->use();

  // get the VBO instance and draw the built in teapot
 //ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
 // draw
 //loadMatricesToColourShader(m_transformStack);

 shader->setShaderParam4f("Colour",0,0,1,1);
 m_lattice->draw(m_transformStack, m_cam, "Colour");

 //m_bbox->draw();
  /*m_transformStack.loadGlobalAndCurrentMatrixToShader("Colour","ModelMatrix");

  m_bbox->draw();

  m_transformStack.loadGlobalAndCurrentMatrixToShader("Blinn","ModelMatrix");
  shader->setShaderParamFromMatrix("Blinn","ModelMatrix",m_transformStack.getCurrAndGlobal().getMatrix());
  (*shader)["Blinn"]->use();*/

   /*m_flock->draw(m_transformStack,  m_cam,
                  "Phong");*/
 //shader->setShaderParam4f("Colour",1,0,0,1);
 //shader->setShaderParam2f("Colour", 1,0);

 //DRAWS CURVE
 BOOST_FOREACH(ngl::BezierCurve *c, m_curves)
 {
 shader->setShaderParam4f("Colour",1,1,1,1);
 c->draw();

 /*   DRAWS POINTS/LINES OF CURVE
 glPointSize(4);
 shader->setShaderParam4f("Colour",0,1,0,1);
 c->drawControlPoints();

 glPointSize(1);
 shader->setShaderParam4f("Colour",1,0,0,1);
 c->drawHull();
*/

 m_scene->draw(m_transformStack, m_cam, "Colour");
 }

}

//----------------------------------------------------------------------------------------------------------------------
// this virtual function is called when the mouse is moved
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseMoveEvent (
                               QMouseEvent * _event
                              )
{
  // note the method buttons() is the button state when event was called
  // this is different from button() which is used to check which button was
  // pressed when the mousePress/Release event is generated
  if(m_rotate && _event->buttons() == Qt::LeftButton)
  {
    m_spinYFace = ( m_spinYFace + (_event->x() - m_origX) ) % 360 ;
    m_spinXFace = ( m_spinXFace + (_event->y() - m_origY) ) % 360 ;
    m_origX = _event->x();
    m_origY = _event->y();
  }
  // re-draw GL
  updateGL();
}


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mousePressEvent (
                                QMouseEvent * _event
                               )
{
  // this method is called when the mouse button is pressed in this case we
  // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
  if(_event->button() == Qt::LeftButton)
  {
    m_origX = _event->x();
    m_origY = _event->y();
    m_rotate =true;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseReleaseEvent (
                                  QMouseEvent * _event
                                 )
{
  // this event is called when the mouse button is released
  // we then set Rotate to false
  if (_event->button() == Qt::LeftButton)
  {
    m_rotate=false;
  }
}


//----------------------------------------------------------------------------------------------------------------------
// this overloaded method is called every time the timers trigger
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::wheelEvent(QWheelEvent *_event)
{

  // check the diff of the wheel position (0 means no change)
  if(_event->delta() > 0)
  {
    m_modelPos.m_z+=ZOOM;
  }
  else if(_event->delta() <0 )
  {
    m_modelPos.m_z-=ZOOM;
  }
  updateGL();
}


//----------------------------------------------------------------------------------------------------------------------
// this overloaded method is called every time the timers trigger
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::timerEvent(
                          QTimerEvent *_event
                         )
{
        // the usual process is to check the event timerID and compare it to
        // any timers we have started with startTimer
        if (_event->timerId() == m_animationTimer)
        {
            if (m_animate !=true)
            {
                    return;
            }

            m_flock->update(m_goals[0]->getPos());
            updateGL();
        }
        if (_event->timerId() == m_goalTimer)
        {
            if (m_animate !=true)
            {
                    return;
            }

            BOOST_FOREACH(Goal *goal, m_goals)
            {
                goal->updatePosition();
            }
            updateGL();
        }


}



void GLWindow::keyPress(QKeyEvent *_event)
{

  switch (_event->key())
  {
                case  Qt::Key_Space : m_animate^=true; break;
      std::cout<<"space"<<std::endl;

        }

}



//----------------------------------------------------------------------------------------------------------------------
// in this case this method is called from the MainWindow class and passed
// the key event from that, if we didn't need to process the events in main
// window we could just overload this as the keyPressEvent and only process here.
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::processKey(
                                                                                                         QKeyEvent *_event
                                                                                                        )
{
// typically we use a switch on _event->key() and look for the keys being pressed
switch (_event->key())
{

        default : {  break; }
}
// here we update once the key has been pressed this may not be the most efficient way of doing
// things depending upon the application being developed.
updateGL();

}

//----------------------------------------------------------------------------------------------------------------------
// in this case this method is called from the MainWindow class and passed
// the key event from that, if we didn't need to process the events in main
// window we could just overload this as the keyPressEvent and only process here.
//---------------------------------------------------------------------------------------------------------------------
void GLWindow::toggleWireframe(
                     bool _mode
                     )

{
    m_wireframe =_mode;

    updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// in this case this method is called from the MainWindow class and passed
// the key event from that, if we didn't need to process the events in main
// window we could just overload this as the keyPressEvent and only process here.
//---------------------------------------------------------------------------------------------------------------------
void GLWindow::toggleAnimation(
                     bool _mode
                     )

{
    m_animate =_mode;

    updateGL();
}



//----------------------------------------------------------------------------------------------------------------------
// Here the new mass can be passed into the boids
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::setMass(
                        double _m
                        )

{
  m_mass=_m;
  m_flock->setMass(_m);
  updateGL();
}


//----------------------------------------------------------------------------------------------------------------------
// Here the new maximum force can be passed into the boids
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::setMaxForce(
                        double _m
                        )

{
  m_maxF=_m;
  m_flock->setMaxForce(_m);
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here the new maximum speed can be passed into the boids
//-----------------------------------------------------------------------------------------------------------------------
void GLWindow::setMaxSpeed(
                        double _m
                        )

{
  m_maxS=_m;
  m_flock->setMaxSpeed(_m);
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here the new Seperation distance can be passed into the boids
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::setSepDist(
                        double _m
                        )

{
  m_sep=_m;
  m_flock->setSepDist(_m);
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here the new Cohesion distance can be passed into the boids
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::setCohDist(
                        double _m
                        )

{
  m_coh=_m;
  m_flock->setCohDist(_m);
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here the new Alignment distance can be passed into the boids
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::setAliDist(
                        double _m
                        )

{
  m_ali=_m;
  m_flock->setAliDist(_m);
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here this calls the remove boid funtion, this removes one boids from the end of the vector
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::removeBoid()
{
 m_flock->removeBoid();
 updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
// Here this calls the add boid function, this adds one boid to the end of the vector
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::addBoid()
{
 m_flock->addBoid();
 updateGL();
}
