//----------------------------------------------------------------------------------------------------------------------
/// @file Boid.cpp
/// @brief a series of classes used to define the properties and charctertistic of individual boid
//----------------------------------------------------------------------------------------------------------------------

#include "Boid.h"
#include "BoidManager.h"
//#include "Predator.h"
#include <ngl/Vector.h>
#include <ngl/ShaderLib.h>
#include <iostream>
#include <ngl/VAOPrimitives.h>

//----------------------------------------------------------------------------------------------------------------------
Boid::Boid(
           const ngl::Vector &_pos,
           const ngl::Vector &_vel,
           ngl::Obj *_mesh
          )

{
  //Boid movement properties
  m_pos=_pos;
  m_mesh=_mesh;
  m_vel=_vel;
  m_acc=m_acc;
  m_mass=10;
  m_maxF=1.5;
  m_maxS=1;

  //Boid rotational properties
  x_rot=x_rot;
  y_rot=y_rot;
  z_rot=z_rot;

  //Boid target. Only used when Center function is called
  m_tar=m_tar;

  //Boid angle distances
  m_sep = 8.0;
  m_coh = 40.0;
  m_ali = 8.0;

}

void Boid::loadMatricesToShader(
                                     ngl::TransformStack &_tx,
                                     ngl::Camera *_cam
                                   ) const
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();

  ngl::Matrix MV;
  ngl::Matrix MVP;
  ngl::Mat3x3 normalMatrix;
  ngl::Matrix M;
  M=_tx.getCurrentTransform().getMatrix();
  MV=_tx.getCurrAndGlobal().getMatrix() * _cam->getViewMatrix();
  MVP=MV * _cam->getProjectionMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMatrix("MV",MV);
  shader->setShaderParamFromMatrix("MVP",MVP);
  shader->setShaderParamFromMat3x3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMatrix("M",M);

}

void Boid::loadMatricesToColourShader(
                                      ngl::TransformStack &_tx,
                                      ngl::Camera *_cam
                                      ) const
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Colour"]->use();
  ngl::Matrix MV;
  ngl::Matrix MVP;

  MV= _tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
  MVP=MV*_cam->getProjectionMatrix() ;
  shader->setShaderParamFromMatrix("MVP",MVP);

}
//----------------------------------------------------------------------------------------------------------------------

void Boid::draw( ngl::TransformStack &_tx,
                 ngl::Camera *_cam,
                 const std::string &_shader1,
                 const std::string &_shader2)
{
  //First we take an instance of the shader manager

  //shader->setShaderParam4f(_shader, 0, 0, 0, 0.5);
  _tx.pushTransform();
  {
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    //Set shader as active
    (*shader)[_shader2]->use();

    m_rayStart = m_pos;
    m_rayEnd = (m_vel*10)+m_pos;

    ngl::VertexArrayObject *vao= ngl::VertexArrayObject::createVOA(GL_LINES);
    vao->bind();
    ngl::Vec3 points[2];
    points[0]=m_rayStart.toVec3();
    points[1]=m_rayEnd.toVec3();
    vao->setData(2*sizeof(ngl::Vec3),points[0].m_x);
    vao->setVertexAttributePointer(0,3,GL_FLOAT,sizeof(ngl::Vec3),0);
    vao->setNumIndices(2);
    loadMatricesToColourShader(_tx, _cam);
    vao->draw();
    vao->removeVOA();
  }
  _tx.popTransform();

  _tx.pushTransform();
  {
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    //Set shader as active
    (*shader)[_shader1]->use();
    //Set the position for the Boid
   // _transformStack.getCurrentTransform().setPosition(m_pos);
    //Set the rotation of the Boid

      float deg = 180/3.141592;





      m_Yrot = atan2(m_vel.m_x, m_vel.m_z) * deg;
      //m_Yrot = atan2(-m_vel.m_z, m_vel.m_x) * deg;

      m_Zrot = asin(m_vel.m_y / m_vel.length())* deg;

      //m_Zrot = asin(j) ;
      //m_Zrot = m_Zrot * 57.324840764;

      //std::cout<<"vel Y = "<< j<<std::endl;
      //std::cout<<"y rot = "<< m_Yrot<<std::endl;
      //std::cout<<"z rot = "<< m_Zrot<<std::endl;
      //std::cout<<"length = "<< m_vel.length()<<std::endl;
      //m_Yrot-90


    _tx.setRotation(0,m_Yrot,0);

    //Load the shader
   // _transformStack.loadGlobalAndCurrentMatrixToShader("Phong","ModelMatrix");
    //apply the mesh
    _tx.getCurrentTransform().setPosition(m_pos);
   // _transformStack.setScale(m_radius,m_radius,m_radius);
    loadMatricesToShader(_tx,_cam);

    //ngl::Matrix MVP=_tx.getCurrAndGlobal().getMatrix() * _cam->getVPMatrix();
    //shader->setShaderParamFromMatrix("MVP",MVP);


    m_mesh->draw();
  }

  _tx.popTransform();
}
//----------------------------------------------------------------------------------------------------------------------

void Boid::update(std::vector <Boid> m_boids)
{
  //first I declare the acceleration. This means that the acceleration is (0,0,0) each update
  //float acc=acc*0;
  //declare the empty steering force and steering direction vectors
  ngl::Vector steering_direction(0,0,0);
  ngl::Vector steering_force(0,0,0);

  //ngl::Vector center(this->Center(m_boids));
  ngl::Vector sep(this->Seperation(m_boids));
  ngl::Vector coh(this->Cohesion(m_boids));
  ngl::Vector ali(this->Alignment(m_boids));

  //ngl::Vector fle(this->Flee(m_boids));

  //Here i apply weightings to the steering forces to give priority to the more influencial ones.
  //fle = fle*100;
  sep = sep*1.8;
  coh = coh*1;
  ali = ali*1;

  /*std::cout<< " sep = ";
  std::cout<<  sep <<std::endl;
  std::cout<< " coh = ";
  std::cout<< coh<<std::endl;*/


  //Add the different forces to the steering direction vector
  //steering_direction = steering_direction + fle;
  steering_direction = steering_direction + sep;
  steering_direction = steering_direction + coh;
  steering_direction = steering_direction + ali;


  //Here i produce a steering force by truncating the steering direction by the Maximum force
  //First we find the magnitude of the steering force
  float k = steering_direction.length();
  //Then i create a new vector to store the normalized steering vector
  ngl::Vector nsteer(0,0,0);
  nsteer = steering_direction;
  nsteer.normalize();

  //If the Mag of the steering force > the maximum F then K is changed to the maximum force
  if ( k > m_maxF )
  {
    k = m_maxF;
  }

  //steering force is equal to its normalized vector multiplied by the magnitude
  steering_force=nsteer*k;

  //Accleration is calculated
  m_acc=steering_force/m_mass;

  //Here i truncate the (velocity + accerlation) by the Maximum speed to produce a new Velocity
  //First i add the vel and accleration
  m_vel=m_vel+m_acc;

  //Get the magnitude of the velocity
  float l = m_vel.length();

  //Then i create a new vector to store the normalized velocity
  ngl::Vector nvec(0,0,0);
  nvec = m_vel;
  nvec.normalize();

  //If the Mag of the velocity > the maximum speed then K is changed to the maximum maximum speed
  if ( l > m_maxS )
  {
    l = m_maxS;
  }

  //The new velocity is equal to its normalized vector multiplied by the magnitude
  m_vel = nvec*l;

  //add the new velocity to the old position to get the new postion
  m_pos=m_pos+m_vel;



  //This keeps the flock inside the bounding box
  if (m_pos[0] > 50)   {m_pos[0] = -50;}
  if (m_pos[0] < -50)  {m_pos[0] = 50;}
  if (m_pos[1] > 50)   {m_pos[1] = -50;}
  if (m_pos[1] < -50)  {m_pos[1] = 50;}
  if (m_pos[2] > 50)   {m_pos[2] = -50;}
  if (m_pos[2] < -50)  {m_pos[2] = 50;}

 /*float deg = 180/3.14;

 //z_rot y_rot
  //atan2(m_vel.m_x, m_vel.m_z) * 57.2957795
  //m_Yrot = atan2(m_vel.m_x, m_vel.m_z) * deg;

  //m_Zrot = asin(((m_vel.m_y)/(m_vel.length()))) * deg;

  //Calculation of the Rotations of the objects
  x_rot = m_vel.length();
  x_rot = asin(m_vel[1]/m_vel.length());
  z_rot = atan2(m_vel[0],m_vel[2]);

  //float deg = 180/3.14;

  x_rot = x_rot* deg;
  z_rot = z_rot* deg; */


  //Wipe the acceleration
  m_acc=m_acc*0;
}

//----------------------------------------------------------------------------------------------------------------------
ngl::Vector Boid::Seperation(std::vector <Boid> m_boids)
{
  /*In this function I take in the array of all the boids and calculate a seperation distance from each of the boids in
    a nearby area then i add a gradient so the closer the boid is the higher the opposite force.*/

  ngl::Vector Sum(0,0,0);


  for(int i=0; i<m_boids.size(); ++i)
  {
    ngl::Vector m(0,0,0);



    m =m_boids[i].m_pos - m_pos;

    float l = m.length();

    //This if statement defines the affect distance of the nearby flockmates
    if ((0.0 < l) && (l < m_sep))
    {

      //Here i set a gradient so there is more of a repulsion the closer the boids get
      m.normalize();
      l=m_sep/l;
      l -= 1;
      ngl::Vector s;
      s = m*-l;
      Sum +=s;

    }

  };

  return Sum;
}

//----------------------------------------------------------------------------------------------------------------------
ngl::Vector Boid::Cohesion(std::vector <Boid> m_boids)
{
  /*In this function I take in the array of all the boids and calculate a cohesion distance so each boid ia attracted to
    the center of the flock. I add a gradient so the further the boid is from the average poosition the less attraction
    its has.*/

  float count;
  float l;

  //Declare empty vectors
  ngl::Vector avg(0,0,0);
  ngl::Vector s(0,0,0);

  //In this for and if i calculate the sum up the postions of all the boids in the specified cohesion area
  for(int i=0; i<m_boids.size(); ++i)
  {
    ngl::Vector m(0,0,0);
    ngl::Vector p(0,0,0);
    p = m_boids[i].m_pos;
    m =m_boids[i].m_pos - m_pos;
    l = m.length();
    if ((0.0 < l) && (l < m_coh))
    {
      avg +=  p;
      count++;

    }


  };
  //calculate the average
  avg=avg/count;

  //Calculate the gradient weighting to apply
  ngl::Vector j(0,0,0);
  j = avg - m_pos;

  l = j.length();
  j.normalize();

  l = m_coh/l;
  l += 1;
  s = j*+l;

  return s;

}

//----------------------------------------------------------------------------------------------------------------------
ngl::Vector Boid::Alignment(std::vector <Boid> m_boids)

/*In this function I take in the array of all the boids and calculate the alignment distance so each boid aligns its
  velocity with nearby flockmates. I take the average of all the nearby flockmates velocity and subtract the boids
  velocity to give an overall steering force.*/

{

  float count;
  ngl::Vector avg(0,0,0);

  for(int i=0; i<m_boids.size(); ++i)
  {
    ngl::Vector m(0,0,0);

    m =m_boids[i].m_pos - m_pos;

    float l = m.length();
    if ((0.0 < l) && (l < m_ali))
    {
      //calculate the velocity of nearby boids
      avg +=  m_boids[i].m_vel;
      count++;
    }
  };
  //get average of nearby boids
  avg=avg/count;
  ngl::Vector m(0,0,0);
  m = avg - m_vel;
  return m;
}
//----------------------------------------------------------------------------------------------------------------------

/*ngl::Vector Boid::Flee(std::vector <Predator> m_predators)
{
  ngl::Vector m(0,0,0);
  ngl::Vector s;

    for(int i = 0; i<m_predators.size(); ++i)
    {
      m = m_predators[i].m_pos - m_pos;
      std::cout<<m_predators[i].m_pos<<std::endl;

      float l = m.length();
      if ((0.0 < l) && (l < 15.0))
        {
          m.normalize();
          l=15.0/l;
          l -= 1;
    //ngl::Vector s;
          s = m*-l;
        }

  }

  return s;
}
  //std::cout<<m_predators[1].m_pos<<std::endl;
  //std::cout<<m_boids[1].m_pos<<std::endl;


ngl::Vector Boid::Hunt(std::vector <Boid> m_boids)
{
  std::cout<<

}*/

//Boid::~Boid();
