#ifndef _BOID_H_
#define _BOID_H_

#include <ngl/Camera.h>
#include <ngl/Vector.h>
#include <ngl/Obj.h>
#include <ngl/TransformStack.h>
//#include "BoidManager.h"
//#include "Predator.h"


/// @file Boid.h
/// @brief The class that contains the charactertistics of each seperate boid
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class Boid
/// @brief boids properties and drawing
///
class Boid
{
public:
 /// @brief ctor
 /// @param _pos the position of the rock
 /// @brief _vel the velocity of the rock
 /// @param _fname the name of mesh to load
 Boid(
       const ngl::Vector &_pos,
       const ngl::Vector &_vel,
       ngl::Obj *_mesh
       );

//~Boid();

 void loadMatricesToShader(
                            ngl::TransformStack &_tx,
                            ngl::Camera *_cam
                          )const;


 void loadMatricesToColourShader(
                                 ngl::TransformStack &_tx,
                                 ngl::Camera *_cam
                               )const;

 /// @brief draw method
 /// @brief pass in the TransformStack defined in GLWindow for the shader
 void draw( ngl::TransformStack &_tx, ngl::Camera *_cam,
            const std::string &_shader1, const std::string &_shader2);

/// @brief update method
/// @brief Update all the boids each frame/simulation step.
 void update(std::vector <Boid> m_boids);

 /// @brief get position method
 /// @brief returns all the positions of the boids.
 inline ngl::Vector getPos()const{return m_pos;}


//--------------------THE THREE RULES--------------------------------------------------------------

/// @brief Seperation function that keeps the boids away from each other
ngl::Vector Seperation(std::vector <Boid> m_boids);

/// @brief Cohesion function that keeps there average position to the center of the flock
ngl::Vector Cohesion(std::vector <Boid> m_boids);

/// @brief Alignment function that aligns the velocities of nerby flockmates
ngl::Vector Alignment(std::vector <Boid> m_boids);

//------------------------------------------------------------------------------------------------

//ngl::Vector Flee(std::vector <Predator> m_predators);

//ngl::Vector Hunt(std::vector <Boid> m_boids);

/// @brief when we press colour the target changes
ngl::Vector m_tar;

/*/// @brief draw method
/// @brief pass in the TransformStack for the shader (should have all the tx needed)
ngl::Vector BoundingBox(std::vector <Boid> m_boids);*/

/// @brief the seperation affect distance
double m_sep;

/// @brief the seperation affect distance
double m_coh;

/// @brief the seperation affect distance
double m_ali;

//float m_mass;
/// @brief float for the maximum force of the boid
double m_maxF;

/// @brief float for the maximum speed of the boid
double m_maxS;

/// @brief float for the maximum speed of the boid
double m_mass;

/// @brief the position of the Rock
ngl::Vector m_pos;
/// @brief the velocity of the boid
ngl::Vector m_vel;
/// @brief the acceleration of the boid
ngl::Vector m_acc;

private :

float m_Yrot;

float m_Zrot;
/// @brief The x rotation of the boids
float x_rot;

/// @brief The y rotation of the boids
float y_rot;

/// @brief The z rotation of the boids
float z_rot;

/// @brief The start position of the ray
ngl::Vector m_rayStart;

/// @brief The end position of the ray
ngl::Vector m_rayEnd;

/// @brief a pointer to the mesh to be drawn
ngl::Obj *m_mesh;


};

#endif
#ifndef _BOID_H_
#define _BOID_H_

#include <ngl/Camera.h>
#include <ngl/Vector.h>
#include <ngl/Obj.h>
#include <ngl/TransformStack.h>
//#include "BoidManager.h"
//#include "Predator.h"


/// @file Boid.h
/// @brief The class that contains the charactertistics of each seperate boid
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class Boid
/// @brief boids properties and drawing
///
class Boid
{
public:
 /// @brief ctor
 /// @param _pos the position of the rock
 /// @brief _vel the velocity of the rock
 /// @param _fname the name of mesh to load
 Boid(
       const ngl::Vector &_pos,
       const ngl::Vector &_vel,
       ngl::Obj *_mesh
       );

//~Boid();

 void loadMatricesToShader(
                            ngl::TransformStack &_tx,
                            ngl::Camera *_cam
                          )const;


 void loadMatricesToColourShader(
                                 ngl::TransformStack &_tx,
                                 ngl::Camera *_cam
                               )const;

 /// @brief draw method
 /// @brief pass in the TransformStack defined in GLWindow for the shader
 void draw( ngl::TransformStack &_tx, ngl::Camera *_cam,
            const std::string &_shader1, const std::string &_shader2);

/// @brief update method
/// @brief Update all the boids each frame/simulation step.
 void update(std::vector <Boid> m_boids);

 /// @brief get position method
 /// @brief returns all the positions of the boids.
 inline ngl::Vector getPos()const{return m_pos;}


//--------------------THE THREE RULES--------------------------------------------------------------

/// @brief Seperation function that keeps the boids away from each other
ngl::Vector Seperation(std::vector <Boid> m_boids);

/// @brief Cohesion function that keeps there average position to the center of the flock
ngl::Vector Cohesion(std::vector <Boid> m_boids);

/// @brief Alignment function that aligns the velocities of nerby flockmates
ngl::Vector Alignment(std::vector <Boid> m_boids);

//------------------------------------------------------------------------------------------------

//ngl::Vector Flee(std::vector <Predator> m_predators);

//ngl::Vector Hunt(std::vector <Boid> m_boids);

/// @brief when we press colour the target changes
ngl::Vector m_tar;

/*/// @brief draw method
/// @brief pass in the TransformStack for the shader (should have all the tx needed)
ngl::Vector BoundingBox(std::vector <Boid> m_boids);*/

/// @brief the seperation affect distance
double m_sep;

/// @brief the seperation affect distance
double m_coh;

/// @brief the seperation affect distance
double m_ali;

//float m_mass;
/// @brief float for the maximum force of the boid
double m_maxF;

/// @brief float for the maximum speed of the boid
double m_maxS;

/// @brief float for the maximum speed of the boid
double m_mass;

/// @brief the position of the Rock
ngl::Vector m_pos;
/// @brief the velocity of the boid
ngl::Vector m_vel;
/// @brief the acceleration of the boid
ngl::Vector m_acc;

private :

float m_Yrot;

float m_Zrot;
/// @brief The x rotation of the boids
float x_rot;

/// @brief The y rotation of the boids
float y_rot;

/// @brief The z rotation of the boids
float z_rot;

/// @brief The start position of the ray
ngl::Vector m_rayStart;

/// @brief The end position of the ray
ngl::Vector m_rayEnd;

/// @brief a pointer to the mesh to be drawn
ngl::Obj *m_mesh;


};

#endif
#ifndef _BOID_H_
#define _BOID_H_

#include <ngl/Camera.h>
#include <ngl/Vector.h>
#include <ngl/Obj.h>
#include <ngl/TransformStack.h>
//#include "BoidManager.h"
//#include "Predator.h"


/// @file Boid.h
/// @brief The class that contains the charactertistics of each seperate boid
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class Boid
/// @brief boids properties and drawing
///
class Boid
{
public:
 /// @brief ctor
 /// @param _pos the position of the rock
 /// @brief _vel the velocity of the rock
 /// @param _fname the name of mesh to load
 Boid(
       const ngl::Vector &_pos,
       const ngl::Vector &_vel,
       ngl::Obj *_mesh
       );

//~Boid();

 void loadMatricesToShader(
                            ngl::TransformStack &_tx,
                            ngl::Camera *_cam
                          )const;


 void loadMatricesToColourShader(
                                 ngl::TransformStack &_tx,
                                 ngl::Camera *_cam
                               )const;

 /// @brief draw method
 /// @brief pass in the TransformStack defined in GLWindow for the shader
 void draw( ngl::TransformStack &_tx, ngl::Camera *_cam,
            const std::string &_shader1, const std::string &_shader2);

/// @brief update method
/// @brief Update all the boids each frame/simulation step.
 void update(std::vector <Boid> m_boids);

 /// @brief get position method
 /// @brief returns all the positions of the boids.
 inline ngl::Vector getPos()const{return m_pos;}


//--------------------THE THREE RULES--------------------------------------------------------------

/// @brief Seperation function that keeps the boids away from each other
ngl::Vector Seperation(std::vector <Boid> m_boids);

/// @brief Cohesion function that keeps there average position to the center of the flock
ngl::Vector Cohesion(std::vector <Boid> m_boids);

/// @brief Alignment function that aligns the velocities of nerby flockmates
ngl::Vector Alignment(std::vector <Boid> m_boids);

//------------------------------------------------------------------------------------------------

//ngl::Vector Flee(std::vector <Predator> m_predators);

//ngl::Vector Hunt(std::vector <Boid> m_boids);

/// @brief when we press colour the target changes
ngl::Vector m_tar;

/*/// @brief draw method
/// @brief pass in the TransformStack for the shader (should have all the tx needed)
ngl::Vector BoundingBox(std::vector <Boid> m_boids);*/

/// @brief the seperation affect distance
double m_sep;

/// @brief the seperation affect distance
double m_coh;

/// @brief the seperation affect distance
double m_ali;

//float m_mass;
/// @brief float for the maximum force of the boid
double m_maxF;

/// @brief float for the maximum speed of the boid
double m_maxS;

/// @brief float for the maximum speed of the boid
double m_mass;

/// @brief the position of the Rock
ngl::Vector m_pos;
/// @brief the velocity of the boid
ngl::Vector m_vel;
/// @brief the acceleration of the boid
ngl::Vector m_acc;

private :

float m_Yrot;

float m_Zrot;
/// @brief The x rotation of the boids
float x_rot;

/// @brief The y rotation of the boids
float y_rot;

/// @brief The z rotation of the boids
float z_rot;

/// @brief The start position of the ray
ngl::Vector m_rayStart;

/// @brief The end position of the ray
ngl::Vector m_rayEnd;

/// @brief a pointer to the mesh to be drawn
ngl::Obj *m_mesh;


};

#endif
