#include "BoidManager.h"
#include <iostream>
#include <ngl/Random.h>
#include <QFile>

BoidManager::BoidManager(
        int _numBoids,
        int _numPredators
        )
{
    m_frame = 0;
    m_numBoids=_numBoids;
    m_numPredators=_numPredators;
    m_mesh=new ngl::Obj("models/boid.obj");
    //create it as a VAO
    m_mesh->createVAO(GL_STATIC_DRAW);

    ngl::Random *rng=ngl::Random::instance();
    rng->setSeed(time(NULL));

    ngl::Vector pos;
    ngl::Vector vel;
    for(int i=0; i<m_numBoids; ++i)
    {
        // add a rock to the vector container
        pos=rng->getRandomPoint(80,80,80);
        vel=rng->getRandomPoint(3,3,3);
        m_boids.push_back(Boid(pos,vel, m_mesh));
        //m_predators.push_back(Boid(pos,vel,m_mesh));
        //now we move the next X position

    }

    //create a new ouput object
    m_outFile = new std::ofstream();
    //open the file called Boids.out
    m_outFile->open("Boids.out");
    //check to see if the file is open
    if(m_outFile->is_open()!=true)
    {
      std::cout<<"error opening file";
      exit(EXIT_FAILURE);

    }
    //write the number of boids in the file
    *m_outFile<<"NumBoids "<<_numBoids<<"\n";



    for(int i=0; i<m_numPredators; ++i)
    {
      pos=rng->getRandomPoint(80,80,80);
      vel=rng->getRandomPoint(3,3,3);
      m_predators.push_back(Predator(pos,vel,m_mesh));

    }

}
void BoidManager::update()
{

  *m_outFile<<"Frame "<<m_frame<<"\n";
  for(int i=0; i<m_numBoids; ++i)
  {
      m_boids[i].update(m_boids);
      *m_outFile<<"B"<<i<<" "<<m_boids[i].getPos().m_x
                        <<" "<<m_boids[i].getPos().m_y
                        <<" "<<m_boids[i].getPos().m_z
                        <<"\n";
  }
  ++m_frame;
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::draw(ngl::TransformStack &_tx, ngl::Camera *_cam,
                       const std::string &_shader1, const std::string &_shader2)
{
  /*In this function i draw the boids*/
    for(int i=0; i<m_numBoids; ++i)
    {

        m_boids[i].draw(_tx, _cam, _shader1, _shader2);
    }

    for(int i=0; i<m_numPredators; ++i)
    {
      //std::cout<<m_numPredators<<std::endl;
      m_predators[i].update(m_boids);
      m_predators[i].draw(_tx, _cam, _shader1);
      //std::cout<<m_predators.size()<<std::endl;
    }

}


//----------------------------------------------------------------------------------------------------------------------
std::vector <Boid> BoidManager::getList()
{
  return m_boids;
}


//----------------------------------------------------------------------------------------------------------------------
void BoidManager::removeBoid()
{
  /*In this function i remove a boid from the end of the array but if there is only one in the array then i can't
    remove any more.*/

  std::vector<Boid>::iterator end=m_boids.end();
  if(--m_numBoids==0)
  {
    m_numBoids=1;
  }
  else
  {
    m_boids.erase(end-1,end);
  }

}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::addBoid()
{
  /*In this function i add a boid to the end of the array, i give it the mesh and shader.*/

  ngl::Random *rng=ngl::Random::instance();
  m_mesh->createVAO(GL_STATIC_DRAW);


  ngl::Vector pos;
  ngl::Vector vel;
  pos=rng->getRandomPoint();
  vel=rng->getRandomPoint();
  // add the spheres to the end of the particle list
  m_boids.push_back(Boid(pos,vel, m_mesh));
  ++m_numBoids;
  //std::cout<<m_numBoids;
  //int new_numBoids;
  //m_numBoids = new_numBoids;
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setMass(double m_mass)
{
  /*In this function i update the mass of the boids with the new user input.*/

    m_mass=m_mass;
    for(int i=0; i<m_numBoids; ++i)
    {
    m_boids[i].m_mass = m_mass;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setMaxForce(double m_maxF)
{
  /*In this function i update the max force of the boids with the new user input.*/

    m_maxF = m_maxF;
    for(int i=0; i<m_numBoids; ++i)
    {
        m_boids[i].m_maxF = m_maxF;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setMaxSpeed(double m_maxS)
{
  /*In this function i update the max speed of the boids with the new user input.*/

    m_maxS = m_maxS;
    for(int i=0; i<m_numBoids; ++i)
    {
        m_boids[i].m_maxS = m_maxS;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setSepDist(double m_sep)
{
  /*In this function i update the seperation distance of the boids with the new user input.*/

    m_sep = m_sep;
    for(int i=0; i<m_numBoids; ++i)
    {
        m_boids[i].m_sep = m_sep;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setCohDist(double m_coh)
{
  /*In this function i update the cohesion distance of the boids with the new user input.*/

    m_coh = m_coh;
    for(int i=0; i<m_numBoids; ++i)
    {
        m_boids[i].m_coh = m_coh;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void BoidManager::setAliDist(double m_ali)
{
  /*In this function i update the alignment distance of the boids with the new user input.*/

    m_ali = m_ali;
    for(int i=0; i<m_numBoids; ++i)
    {
        m_boids[i].m_ali = m_ali;
    }
}

//----------------------------------------------------------------------------------------------------------------------
/*void BoidManager::addPredator()
{
  m_mesh=new ngl::Obj("models/boid.obj");
  ngl::Random *rng=ngl::Random::instance();
  m_mesh->createVBO(GL_STATIC_DRAW);


  ngl::Vector pos;
  ngl::Vector vel;
  pos=rng->getRandomPoint();
  vel=rng->getRandomPoint();
  // add the spheres to the end of the particle list
  Predator(pos,vel, m_mesh);
  //++m_numBoids;
  //std::cout<<m_numBoids;
  //int new_numBoids;
  //m_numBoids = new_numBoids;
}*/
ngl::Vector BoidManager::getBoids()
{

  for(int i=0; i<m_numBoids; ++i)
  {
    std::cout<<m_boids[i].m_pos<<std::endl;
    return m_boids[i].m_pos;
  }
}

ngl::Vector BoidManager::getPredators()
{

  for(int i=0; i<m_numPredators; ++i)
  {
    std::cout<<m_predators[i].m_pos<<std::endl;
    return m_predators[i].m_pos;
  }
}



