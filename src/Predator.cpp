//----------------------------------------------------------------------------------------------------------------------
/// @file Boid.cpp
/// @brief a series of classes used to define the properties and charctertistic of individual boid
//----------------------------------------------------------------------------------------------------------------------

#include "Predator.h"
#include <ngl/Vector.h>
#include <ngl/ShaderLib.h>
#include <iostream>

//----------------------------------------------------------------------------------------------------------------------
Predator::Predator(
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

}

void Predator::loadMatricesToShader(
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

//----------------------------------------------------------------------------------------------------------------------

void Predator::draw( ngl::TransformStack &_transformStack,
                 ngl::Camera *_cam,
                 const std::string &_shader)
{
  //First we take an instance of the shader manager
  ngl::ShaderLib *shader = ngl::ShaderLib::instance();
  //Set shader as active
  (*shader)[_shader]->use();

  _transformStack.pushTransform();
  {
    //Set the position for the Boid
   // _transformStack.getCurrentTransform().setPosition(m_pos);
    //Set the rotation of the Boid
     shader->setShaderParam4f(_shader,0,1,0,1);
    _transformStack.setRotation(0,z_rot-90,x_rot);
    _transformStack.setScale(4,4,4);
    _transformStack.getCurrentTransform().setPosition(m_pos);



    loadMatricesToShader(_transformStack,_cam);




    m_mesh->draw();

  }

  _transformStack.popTransform();
}

void Predator::update(std::vector <Boid> m_boids)
{
  //first I declare the acceleration. This means that the acceleration is (0,0,0) each update
  float acc=acc*0;
  //declare the empty steering force and steering direction vectors
  ngl::Vector steering_direction(0,0,0);
  ngl::Vector steering_force(0,0,0);

  ngl::Vector track(this->Track(m_boids));

  track = track*1.8;

  steering_direction = steering_direction + track;


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




  //Calculation of the Rotations of the objects
  x_rot = m_vel.length();
  x_rot = asin(m_vel[1]/x_rot);
  z_rot = atan2(m_vel[0],m_vel[2]);

  float deg = 180/3.14;

  x_rot = x_rot* deg;
  z_rot = z_rot* deg;


  //Wipe the acceleration
  m_acc=m_acc*0;
}

ngl::Vector Predator::Track(std::vector <Boid> m_boids)
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
    //std::cout<<m_boids[i].m_pos<<std::endl;
    ngl::Vector m(0,0,0);
    ngl::Vector p(0,0,0);
    p = m_boids[i].m_pos;
    m =m_boids[i].m_pos - m_pos;
    l = m.length();
    if ((0.0 < l) && (l < 5.0))
    {
      avg +=  p;
      count++;

    }


  }
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


