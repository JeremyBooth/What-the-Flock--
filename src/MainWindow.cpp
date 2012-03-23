#include "include/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl=new GLWindow(this);
    m_ui->s_mainwindowgridlayout->addWidget(m_gl,0,0,2,1);
    connect(m_ui->m_wireframe,SIGNAL(toggled(bool)),m_gl,SLOT(toggleWireframe(bool)));
    connect(m_ui->m_animateBoids ,SIGNAL(toggled(bool)),m_gl,SLOT(toggleBoidAnimation(bool)));
    connect(m_ui->m_animateGoal ,SIGNAL(toggled(bool)),m_gl,SLOT(toggleGoalAnimation(bool)));
    connect(m_ui->m_mass,SIGNAL(valueChanged(double)),m_gl,SLOT(setMass(double)));
    connect(m_ui->m_speed,SIGNAL(valueChanged(double)),m_gl,SLOT(setMaxSpeed(double)));
    connect(m_ui->m_force,SIGNAL(valueChanged(double)),m_gl,SLOT(setMaxForce(double)));
    connect(m_ui->m_seperation,SIGNAL(valueChanged(double)),m_gl,SLOT(setSepDist(double)));
    connect(m_ui->m_cohesion,SIGNAL(valueChanged(double)),m_gl,SLOT(setCohDist(double)));
    connect(m_ui->m_alignment,SIGNAL(valueChanged(double)),m_gl,SLOT(setAliDist(double)));
    connect(m_ui->m_addBoid,SIGNAL(pressed()),m_gl,SLOT(addBoid()));
    connect(m_ui->m_removeBoid,SIGNAL(pressed()),m_gl,SLOT(removeBoid()));

    connect(m_ui->m_goalInfluence,SIGNAL(sliderMoved(int)),m_gl,SLOT(setGoalInf(int)));
    connect(m_ui->m_resetGoals,SIGNAL(pressed()),m_gl,SLOT(resetGoals()));

    connect(m_ui->m_record ,SIGNAL(toggled(bool)),m_gl,SLOT(toggleRecord(bool)));

}

MainWindow::~MainWindow()
{
    delete m_ui;
}
