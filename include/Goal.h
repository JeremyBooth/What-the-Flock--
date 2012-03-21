#ifndef _GOAL_H_
#define _GOAL_H_

#include <ngl/Camera.h>
#include <ngl/Vector.h>
#include <ngl/Obj.h>
#include <ngl/TransformStack.h>
#include <ngl/BezierCurve.h>
#include <ngl/VAOPrimitives.h>



///
class Goal
{
public:
 /// @brief ctor
 /// @param _pos the position of the rock

 Goal(ngl::BezierCurve *_path);

 void loadMatricesToShader(ngl::TransformStack &_tx, ngl::Camera *_cam) const;

 void draw( ngl::TransformStack &_tx,
              ngl::Camera *_cam,
              const std::string &_sha);

 /// @brief method to get Goal position
 ngl::Vector getPos(){return m_pos;}

 void updatePosition();



private:

    /// @brief mesh to be passed to our scene
    ngl::Obj *m_mesh;

    /// @brief the position of the Rock
    ngl::Vector m_pos;


    float m_curvePoint;

    float m_step;

    ngl::BezierCurve m_path;



 };

 #endif
