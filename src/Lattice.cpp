//----------------------------------------------------------------------------------------------------------------------
/// @file Lattice.cpp
/// @brief a series of classes used to define the properties and charctertistic of individual boid
//----------------------------------------------------------------------------------------------------------------------

#include "Lattice.h"
#include <iostream>
#include <ngl/ShaderLib.h>

//----------------------------------------------------------------------------------------------------------------------


Lattice::Lattice(
                int _length

                )


{
    m_length = _length;
    m_bbox = new ngl::BBox(ngl::Vector(0,0,0),m_length,m_length,m_length);


}

void Lattice::loadMatricesToColourShader(
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

void Lattice::draw( ngl::TransformStack &_tx,
             ngl::Camera *_cam,
             const std::string &_shader)
{

    //First we take an instance of the shader manager
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    //Set shader as active
    (*shader)[_shader]->use();
    shader->setShaderParam4f(_shader, 0, 1, 1, 1);

    //m_bbox = new ngl::BBox(ngl::Vector(0,0,0),100,100,100);

    loadMatricesToColourShader(_tx,_cam);

    ngl::Matrix MVP=_tx.getCurrAndGlobal().getMatrix() * _cam->getVPMatrix();
    shader->setShaderParamFromMatrix("MVP",MVP);

    m_bbox->draw();


    //std::cout<<"DRAW!!!";

}
