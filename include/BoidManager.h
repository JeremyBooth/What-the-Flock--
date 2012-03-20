#ifndef _BOIDMANAGER_H_
#define _BOIDMANAGER_H_

#include "Boid.h"
#include "Predator.h"
#include <vector>
#include <ngl/TransformStack.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <fstream>

/// @file BoidManager.h
/// @brief The class to contain and draw the boids
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class BoidManager
/// @brief This draws and updates the flock of boids, also there are ui connections to the boids
///
class BoidManager
{
public:
    /// @brief ctor
    /// @param _numBoids the number of Boids
    BoidManager(
            int _numBoids,
            int _numPredators
            );

    /// @brief dtor
     ~BoidManager();

     void update();

    /// @brief method to draw Boids
    /// @brief the transform stack
    void draw( ngl::TransformStack &_tx,
               ngl::Camera *_cam,
               const std::string &_shader1,
               const std::string &_shader2);

    ngl::Vector getBoids();
    ngl::Vector getPredators();

    /// @brief Sets the mass of the boids
    /// @param[in] the new mass
    void setMass(double m_mass);

    /// @brief sets the maximum speed of the boids
    /// @param[in] the new maximum Speed
    void setMaxSpeed(double m_maxS);

    /// @brief sets the maximum force of th boids
    /// @param[in] the new maximum force
    void setMaxForce(double m_maxF);

    /// @brief sets the seperation distance
    /// @param[in] the new seperation distance
    void setSepDist(double m_sep);

    /// @brief sets the cohesion distance
    /// @param[in] the new cohesion distance
    void setCohDist(double m_coh);

    /// @brief sets the alignment distance
    /// @param[in] the new alignment distance
    void setAliDist(double m_ali);

    /// @brief adds a boid to the m_boids array
    void addBoid();

    /// @brief removes a boid from the m_boids array
    void removeBoid();
    //void addPredator();
    //std::vector <Boid> m_boids;
    std::vector <Boid> getList();






private:
    /// @brief our container of boids
    std::vector <Boid> m_boids;

    /// @brief our container of boids
    std::vector <Predator> m_predators;

    /// @brief number of boids
    int m_numBoids;

    /// @brief number of Predators
    int m_numPredators;

    /// @brief the active boids
    int m_activeBoid;
    int m_count;

    int m_centre;
    unsigned int m_frame;
    //std::ofstream *m_outFile;

    std::ofstream *m_outFile;
    //QString *text;

    /// @brief the mesh to be passed to the boid
    ngl::Obj *m_mesh;
};

#endif
