#ifndef _PREDATOR_H_
#define _PREDATOR_H_
#include <ngl/Vector.h>
#include <ngl/Obj.h>
#include <ngl/TransformStack.h>
#include "Boid.h"

#include <vector>

/// @file Predator.h
/// @brief The class that contains the charactertistics of the predator boid
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class Predator
/// @brief Predator properties and drawing
///
class Predator
{
public:
 /// @brief ctor
 /// @param _pos the position of the rock
 /// @brief _vel the velocity of the rock
 /// @param _fname the name of mesh to load
 Predator(
       const ngl::Vector &_pos,
       const ngl::Vector &_vel,
       ngl::Obj *_mesh
       );

 void loadMatricesToShader(
                            ngl::TransformStack &_tx,
                            ngl::Camera *_cam
                          )const;

 /// @brief draw method
 /// @brief pass in the TransformStack defined in GLWindow for the shader
 void draw( ngl::TransformStack &_transformStack, ngl::Camera *_cam,
            const std::string &_shader);

/// @brief update method
/// @brief Update all the boids each frame/simulation step.
 void update(std::vector <Boid> m_boids);

/// @brief center function to make the boids flock to the center
ngl::Vector Track(std::vector <Boid> m_boids);


/// @brief draw method
/// @brief pass in the TransformStack for the shader (should have all the tx needed)
ngl::Vector BoundingBox();
double m_mass;

std::vector <Boid> *m_boids;

/// @brief the position of the predator
ngl::Vector m_pos;

private :
/// @brief the position of the predator
//ngl::Vector m_pos;
/// @brief the velocity of the predator
ngl::Vector m_vel;
/// @brief the acceleration of the boid
ngl::Vector m_acc;



//float m_mass;
/// @brief float for the maximum force of the boid
float m_maxF;

/// @brief float for the maximum speed of the boid
float m_maxS;

/// @brief The x rotation of the boids
float x_rot;

/// @brief The y rotation of the boids
float y_rot;

/// @brief The z rotation of the boids
float z_rot;

//ngl::Vector m_tar;
/// @brief the seperation affect distance
float m_sep;

/// @brief the seperation affect distance
float m_coh;

/// @brief the seperation affect distance
float m_ali;


/// @brief a pointer to the mesh to be drawn
ngl::Obj *m_mesh;

};

#endif*/
