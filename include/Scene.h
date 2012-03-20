#ifndef __SCENE_H__
#define __SCENE_H__


#include "ngl/Camera.h"
#include "ngl/Colour.h"
#include "ngl/SpotLight.h"
#include "ngl/TransformStack.h"
#include "ngl/Obj.h"
#include "ngl/NCCAPointBake.h"
// must be included after our stuff becuase GLEW needs to be first
#include <QtOpenGL>

class Scene
{
public:

    /// @brief ctor
    Scene();

    /// @brief Load the matrixes to the shader
    /// @param Transform stack and pointer to the Camera
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

    /// @brief mesh to be passed to our scene
    ngl::Obj *m_mesh;





};

#endif
