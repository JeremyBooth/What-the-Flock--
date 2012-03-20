#ifndef _LATTICE_H_
#define _LATTICE_H_

#include "ngl/Camera.h"
#include "ngl/Vector.h"
#include "ngl/Obj.h"
#include "ngl/TransformStack.h"


/// @file Lattice.h
/// @brief The class that contains the charactertistics of the lattice bin
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class Lattice
/// @brief Defines the parameters of the lattice bin


class Lattice

{

public:


/// @brief ctor
/// @brief
Lattice(
        int _length
        );

void loadMatricesToShader(
                           ngl::TransformStack &_tx,
                           ngl::Camera *_cam
                         )const;

/// @brief method to draw Scene
/// @brief the transform stack, pointer to Camera, and pointer to shader
void draw( ngl::TransformStack &_tx,
           ngl::Camera *_cam,
           const std::string &_shader);



private:

   int m_length;
   ngl::BBox *m_bbox;
};

#endif
