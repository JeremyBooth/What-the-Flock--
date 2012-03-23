/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Fri Mar 23 11:54:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainwindowgridlayout;
    QGroupBox *s_transGB;
    QGridLayout *gridLayout;
    QLabel *m_MassLabel;
    QLabel *m_MaxSpeedLabel;
    QDoubleSpinBox *m_force;
    QLabel *m_MaxForceLabel;
    QDoubleSpinBox *m_seperation;
    QDoubleSpinBox *m_cohesion;
    QDoubleSpinBox *m_alignment;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *m_speed;
    QDoubleSpinBox *m_mass;
    QLabel *label_4;
    QSlider *m_goalInfluence;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_animateBoids;
    QCheckBox *m_animateGoal;
    QPushButton *m_resetGoals;
    QPushButton *m_record;
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QCheckBox *m_wireframe;
    QPushButton *m_addBoid;
    QPushButton *m_removeBoid;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 457);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s_mainwindowgridlayout = new QGridLayout(centralwidget);
        s_mainwindowgridlayout->setObjectName(QString::fromUtf8("s_mainwindowgridlayout"));
        s_transGB = new QGroupBox(centralwidget);
        s_transGB->setObjectName(QString::fromUtf8("s_transGB"));
        s_transGB->setMaximumSize(QSize(300, 300));
        s_transGB->setAutoFillBackground(false);
        gridLayout = new QGridLayout(s_transGB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_MassLabel = new QLabel(s_transGB);
        m_MassLabel->setObjectName(QString::fromUtf8("m_MassLabel"));

        gridLayout->addWidget(m_MassLabel, 1, 1, 1, 1);

        m_MaxSpeedLabel = new QLabel(s_transGB);
        m_MaxSpeedLabel->setObjectName(QString::fromUtf8("m_MaxSpeedLabel"));

        gridLayout->addWidget(m_MaxSpeedLabel, 3, 1, 1, 1);

        m_force = new QDoubleSpinBox(s_transGB);
        m_force->setObjectName(QString::fromUtf8("m_force"));
        m_force->setMinimum(0.1);

        gridLayout->addWidget(m_force, 4, 4, 1, 1);

        m_MaxForceLabel = new QLabel(s_transGB);
        m_MaxForceLabel->setObjectName(QString::fromUtf8("m_MaxForceLabel"));

        gridLayout->addWidget(m_MaxForceLabel, 4, 1, 1, 1);

        m_seperation = new QDoubleSpinBox(s_transGB);
        m_seperation->setObjectName(QString::fromUtf8("m_seperation"));
        m_seperation->setValue(8);

        gridLayout->addWidget(m_seperation, 5, 4, 1, 1);

        m_cohesion = new QDoubleSpinBox(s_transGB);
        m_cohesion->setObjectName(QString::fromUtf8("m_cohesion"));
        m_cohesion->setValue(40);

        gridLayout->addWidget(m_cohesion, 6, 4, 1, 1);

        m_alignment = new QDoubleSpinBox(s_transGB);
        m_alignment->setObjectName(QString::fromUtf8("m_alignment"));
        m_alignment->setValue(8);

        gridLayout->addWidget(m_alignment, 7, 4, 1, 1);

        label = new QLabel(s_transGB);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 1, 1, 1);

        label_2 = new QLabel(s_transGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 1, 1, 1);

        label_3 = new QLabel(s_transGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 1, 1, 1);

        m_speed = new QDoubleSpinBox(s_transGB);
        m_speed->setObjectName(QString::fromUtf8("m_speed"));
        m_speed->setMinimum(0.3);
        m_speed->setSingleStep(0.001);

        gridLayout->addWidget(m_speed, 3, 4, 1, 1);

        m_mass = new QDoubleSpinBox(s_transGB);
        m_mass->setObjectName(QString::fromUtf8("m_mass"));
        m_mass->setMinimum(18);
        m_mass->setMaximum(30);
        m_mass->setSingleStep(0.001);
        m_mass->setValue(18);

        gridLayout->addWidget(m_mass, 1, 4, 1, 1);

        label_4 = new QLabel(s_transGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 8, 1, 1, 1);

        m_goalInfluence = new QSlider(s_transGB);
        m_goalInfluence->setObjectName(QString::fromUtf8("m_goalInfluence"));
        m_goalInfluence->setMinimum(0);
        m_goalInfluence->setMaximum(200);
        m_goalInfluence->setSingleStep(1);
        m_goalInfluence->setPageStep(10);
        m_goalInfluence->setValue(0);
        m_goalInfluence->setSliderPosition(0);
        m_goalInfluence->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(m_goalInfluence, 8, 4, 1, 1);


        s_mainwindowgridlayout->addWidget(s_transGB, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainwindowgridlayout->addItem(horizontalSpacer, 0, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 20);
        m_animateBoids = new QCheckBox(centralwidget);
        m_animateBoids->setObjectName(QString::fromUtf8("m_animateBoids"));
        m_animateBoids->setChecked(true);

        horizontalLayout->addWidget(m_animateBoids);

        m_animateGoal = new QCheckBox(centralwidget);
        m_animateGoal->setObjectName(QString::fromUtf8("m_animateGoal"));

        horizontalLayout->addWidget(m_animateGoal);

        m_resetGoals = new QPushButton(centralwidget);
        m_resetGoals->setObjectName(QString::fromUtf8("m_resetGoals"));
        m_resetGoals->setCheckable(false);

        horizontalLayout->addWidget(m_resetGoals);

        m_record = new QPushButton(centralwidget);
        m_record->setObjectName(QString::fromUtf8("m_record"));
        m_record->setCheckable(true);

        horizontalLayout->addWidget(m_record);


        s_mainwindowgridlayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QString::fromUtf8("s_drawGB"));
        s_drawGB->setMaximumSize(QSize(300, 300));
        gridLayout_2 = new QGridLayout(s_drawGB);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_wireframe = new QCheckBox(s_drawGB);
        m_wireframe->setObjectName(QString::fromUtf8("m_wireframe"));

        gridLayout_2->addWidget(m_wireframe, 2, 0, 1, 1);

        m_addBoid = new QPushButton(s_drawGB);
        m_addBoid->setObjectName(QString::fromUtf8("m_addBoid"));

        gridLayout_2->addWidget(m_addBoid, 0, 0, 1, 1);

        m_removeBoid = new QPushButton(s_drawGB);
        m_removeBoid->setObjectName(QString::fromUtf8("m_removeBoid"));

        gridLayout_2->addWidget(m_removeBoid, 1, 0, 1, 1);


        s_mainwindowgridlayout->addWidget(s_drawGB, 1, 2, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Flocking System", 0, QApplication::UnicodeUTF8));
        s_transGB->setTitle(QString());
        m_MassLabel->setText(QApplication::translate("MainWindow", "Mass \342\230\242", 0, QApplication::UnicodeUTF8));
        m_MaxSpeedLabel->setText(QApplication::translate("MainWindow", "Max Speed \342\236\263", 0, QApplication::UnicodeUTF8));
        m_MaxForceLabel->setText(QApplication::translate("MainWindow", "Max Force \342\225\204", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Seperation \342\234\226 ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Cohesion  \342\235\244 ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Alignment \342\206\227", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Goal Influence", 0, QApplication::UnicodeUTF8));
        m_animateBoids->setText(QApplication::translate("MainWindow", "Animate Boids", 0, QApplication::UnicodeUTF8));
        m_animateGoal->setText(QApplication::translate("MainWindow", "Animate Goals", 0, QApplication::UnicodeUTF8));
        m_resetGoals->setText(QApplication::translate("MainWindow", "\342\227\204 ResetGoals", 0, QApplication::UnicodeUTF8));
        m_record->setText(QApplication::translate("MainWindow", "\342\227\217", 0, QApplication::UnicodeUTF8));
        s_drawGB->setTitle(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        m_wireframe->setText(QApplication::translate("MainWindow", "Wireframe \342\226\246", 0, QApplication::UnicodeUTF8));
        m_addBoid->setText(QApplication::translate("MainWindow", "Add Boid \342\234\232", 0, QApplication::UnicodeUTF8));
        m_removeBoid->setText(QApplication::translate("MainWindow", "Remove Boid \342\230\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
