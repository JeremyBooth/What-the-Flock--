#include "Goal.h"
#include <iostream>
#include <ngl/Random.h>
#include <ngl/ShaderLib.h>
#include <ngl/TransformStack.h>


Goal::Goal(ngl::BezierCurve *_path)
{

    m_mesh=new ngl::Obj("models/goal.obj");
    //create it as a VAO
    m_mesh->createVAO(GL_STATIC_DRAW);

    m_path=*_path;
    m_step=0.001;
    m_pos=m_path.getPointOnCurve(0.5);

    //std::cout<<m_pos<<std::endl;
    m_curvePoint = 0.000;


}

void Goal::loadMatricesToShader(ngl::TransformStack &_tx, ngl::Camera *_cam) const

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
    //std::cout<<"SHADER!!!!";

}

void Goal::draw( ngl::TransformStack &_tx,
             ngl::Camera *_cam,
             const std::string &_shader)
{

    //First we take an instance of the shader manager
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    //Set shader as active
    (*shader)[_shader]->use();
    shader->setShaderParam4f(_shader, 1, 0, 0, 0.5);
    //glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    _tx.pushTransform();
    {
      _tx.getCurrentTransform().setPosition(m_pos);

      loadMatricesToShader(_tx,_cam);

      ngl::Matrix MVP=_tx.getCurrAndGlobal().getMatrix() * _cam->getVPMatrix();
      shader->setShaderParamFromMatrix("MVP",MVP);

      m_mesh->draw();

    }
    _tx.popTransform();
    std::cout<<"DRAW!!!";
}


void Goal::updatePosition()
{
    m_curvePoint+=m_step;
    m_pos= m_path.getPointOnCurve(m_curvePoint);
    std::cout<<m_pos;
}



