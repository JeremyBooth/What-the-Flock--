#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GLWindow.h"

/// @file MainWindow.h
/// @brief The class to contains the ui elements of the program
/// @author Jeremy Booth
/// @version 1.0
/// @date 31/3/11
/// Revision History :
/// Initial Version 31/3/11
/// @class MainWindow
/// @brief This is the main window ui.

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *m_ui;
    /// @brief our openGL widget
    GLWindow *m_gl;
};

#endif // MAINWINDOW_H
