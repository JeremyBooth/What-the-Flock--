#ifndef __GL_WINDOW_H__
#define __GL_WINDOW_H__
#include <ngl/BBox.h>
#include <ngl/Text.h>
#include <QString>
#include "ngl/Camera.h"
#include "ngl/Colour.h"
#include "ngl/SpotLight.h"
#include "ngl/TransformStack.h"
#include "ngl/Obj.h"
#include "ngl/BezierCurve.h"
#include "BoidManager.h"
#include "Scene.h"
#include "Lattice.h"
#include "Goal.h"
// must be included after our stuff becuase GLEW needs to be first
#include <QtOpenGL>

/// @file GLWindow.h
/// @brief Qt GL window class for the flocking scene
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/10
/// @class GLWindow
/// @brief The main glwindow widget and all drawing elements are
/// put in this file

class GLWindow : public QGLWidget
{

Q_OBJECT
public :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor for GLWindow
  /// @param [in] parent the parent window to create the GL context in
  //----------------------------------------------------------------------------------------------------------------------
  GLWindow(
           QWidget *_parent
          );
  //----------------------------------------------------------------------------------------------------------------------
        /// @brief dtor add any code here to tidy up
  //----------------------------------------------------------------------------------------------------------------------
  ~GLWindow();

  //----------------------------------------------------------------------------------------------------------------------
/// @brief toggle the Animation of the boids called from main window
  //----------------------------------------------------------------------------------------------------------------------
//inline void toggleBoidAnimation(){m_animateBoids^=true;}
//----------------------------------------------------------------------------------------------------------------------
/// @brief toggle the Animation of the goal called from main window
//----------------------------------------------------------------------------------------------------------------------
//inline void toggleGoalAnimation(){m_animateGoal^=true;}



  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method called from main window for keyPress
  //----------------------------------------------------------------------------------------------------------------------
  void keyPress(
                                                           QKeyEvent *_event
                                                   );




  //----------------------------------------------------------------------------------------------------------------------
        /// @brief processKey passed from the main window class
        /// @param *_event a pointer to the QKeyEvent passed from main window
        /// class
  //----------------------------------------------------------------------------------------------------------------------
        void processKey(
                                                                         QKeyEvent *_event
                                                                        );
    public slots:
        /// @brief a slot to toggle wireframe mode
        /// @param [in] _mode the mode passed from toggle button
        void toggleWireframe(
                             bool _mode
                             );

        /// @brief a slot to toggle wireframe mode
        /// @param [in] _mode the mode passed from toggle button
        void toggleBoidAnimation(
                             bool _mode
                             );

        /// @brief a slot to toggle wireframe mode
        /// @param [in] _mode the mode passed from toggle button
        void toggleGoalAnimation(
                             bool _mode
                             );

        void toggleRecord(
                             bool _mode
                             );


        /// @brief a slot to change the mass of the boid
        /// @param [in] _m the mode passed from corresponding spin box
        void setMass(
                     double _m
                     );

        /// @brief a slot to change the Maximum speed value
        /// @param [in] _m the mode passed from corresponding spin box
        void setMaxSpeed(
                         double _m
                         );

        /// @brief a slot to change the Maximum force value
        /// @param [in] _m the mode passed from corresponding spin box
        void setMaxForce(
                         double _m
                         );

        /// @brief a slot change spin box value for the seperation distance
        /// @param [in] _m the mode passed from corresponding spin box
        void setSepDist(
                         double _m
                         );

        /// @brief a slot change spin box value for the cohesion distance
        /// @param [in] _m the mode passed from corresponding spin box
        void setCohDist(
                         double _m
                         );

        /// @brief a slot change spin box value for the alignment distance
        /// @param [in] _m the mode passed from corresponding spin box
        void setAliDist(
                         double _m
                         );

        /// @brief a slot change slider value for the goal influence
        /// @param [in] _m the mode passed from corresponding slider
        void setGoalInf(
                        int _m
                       );

        /// @brief a slot to remove a boid from the m_boids array when the button is pressed
        void removeBoid();

        /// @brief a slot to add a boid from the m_boids array when the button is pressed
        void addBoid();

        /// @brief a slot to reset goals back to beginning of curve
        void resetGoals();


private :

  /// @brief the number of curves
  //-----------------------------------------------------------------------------------------------------------------------
  int m_numGoals;

  /// @brief flag to indicate if boid animation is active or not
  //----------------------------------------------------------------------------------------------------------------------
  bool m_animateBoids;

  /// @brief flag to indicate if goal animation is active or not
  //----------------------------------------------------------------------------------------------------------------------
  bool m_animateGoal;

  /// @brief flag to indicate if recording or not
  //----------------------------------------------------------------------------------------------------------------------
  bool m_record;


  /// @brief m_wireframe mode
  //----------------------------------------------------------------------------------------------------------------------
   bool m_wireframe;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mass data
  //----------------------------------------------------------------------------------------------------------------------
  double m_mass;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief max speed data
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxS;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief max force data
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxF;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief cohesion distance data
  //----------------------------------------------------------------------------------------------------------------------
  double m_coh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief seperation distance data
  //----------------------------------------------------------------------------------------------------------------------
  double m_sep;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief alignment distance data
  //----------------------------------------------------------------------------------------------------------------------
  double m_ali;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief  goal influence value
  //----------------------------------------------------------------------------------------------------------------------
  double m_goalInf;




  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a timer triggered by the startTimer call in the ctor
  //----------------------------------------------------------------------------------------------------------------------
  int m_animationTimer;


  /// @brief a timer triggered by the startTimer call in the ctor
  //----------------------------------------------------------------------------------------------------------------------
  int m_goalTimer;



  ngl::Text *m_text;

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the x rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinXFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the y rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinYFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool m_rotate;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origY;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the model position for mouse movement
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vector m_modelPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the increment for the wheel zoom
  //----------------------------------------------------------------------------------------------------------------------
  const static float ZOOM=5;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Our Camera
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Camera *m_cam;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our transform stack for drawing the boids
  //----------------------------------------------------------------------------------------------------------------------
  ngl::TransformStack m_transformStack;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the manager for the boids
  //----------------------------------------------------------------------------------------------------------------------
  BoidManager *m_flock;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief light for the scene
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Light *m_light;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the manager for the predator
  //----------------------------------------------------------------------------------------------------------------------
  //BoidManager *m_predator;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the scene object
  //----------------------------------------------------------------------------------------------------------------------
  Scene *m_scene;
  //----------------------------------------------------------------------------------------------------------------------
  Lattice *m_lattice;
  //----------------------------------------------------------------------------------------------------------------------
  //Goal *m_goal;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a vector array of curves to draw
  std::vector<ngl::BezierCurve *>m_curves;

  /// @brief a vector array of Goals
  std::vector <Goal *> m_goals;

  int m_numboids;

  int m_numpredators;

protected:
/*
  void loadMatricesToShader(
                             ngl::TransformStack &_tx
                            );
  void loadMatricesToColourShader(
                                   ngl::TransformStack &_tx
                                 );

*/

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief  The following methods must be implimented in the sub class
  /// this is called when the window is created
  //----------------------------------------------------------------------------------------------------------------------
  void initializeGL();

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is called whenever the window is re-sized
  /// @param[in] _w the width of the resized window
  /// @param[in] _h the height of the resized window
  //----------------------------------------------------------------------------------------------------------------------
  void resizeGL(
                const int _w,
                const int _h
               );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is the main gl drawing routine which is called whenever the window needs to
  /// be re-drawn
  //----------------------------------------------------------------------------------------------------------------------
  void paintGL();

private :

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief This is the bounding box to contain the flock
  //----------------------------------------------------------------------------------------------------------------------
  ngl::BBox *m_bbox;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called every time a mouse is moved
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseMoveEvent (
                       QMouseEvent * _event
                      );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is pressed
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mousePressEvent (
                        QMouseEvent *_event
                       );

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is released
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseReleaseEvent (
                          QMouseEvent *_event
                         );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the timer event triggered from the timers
  /// @param _even the event of the timer triggered by Qt
  //----------------------------------------------------------------------------------------------------------------------
  void timerEvent(
                  QTimerEvent *_event
                 );

  //----------------------------------------------------------------------------------------------------------------------
   /// @brief this method is called everytime the mouse wheel is moved
   /// inherited from QObject and overridden here.
   /// @param _event the Qt Event structure
   //----------------------------------------------------------------------------------------------------------------------
   void wheelEvent(
                     QWheelEvent *_event
                  );


  void loadCurves();

};

#endif
