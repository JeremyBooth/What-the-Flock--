/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Mar 21 16:22:44 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainwindowgridlayout;
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QCheckBox *m_wireframe;
    QPushButton *m_addBoid;
    QPushButton *m_removeBoid;
    QCheckBox *m_animate;
    QSpacerItem *horizontalSpacer;
    QGroupBox *s_transGB;
    QGridLayout *gridLayout;
    QLabel *m_MassLabel;
    QDoubleSpinBox *m_mass;
    QDoubleSpinBox *m_speed;
    QLabel *m_MaxSpeedLabel;
    QDoubleSpinBox *m_force;
    QLabel *m_MaxForceLabel;
    QDoubleSpinBox *m_seperation;
    QDoubleSpinBox *m_cohesion;
    QDoubleSpinBox *m_alignment;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s_mainwindowgridlayout = new QGridLayout(centralwidget);
        s_mainwindowgridlayout->setObjectName(QString::fromUtf8("s_mainwindowgridlayout"));
        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QString::fromUtf8("s_drawGB"));
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

        m_animate = new QCheckBox(s_drawGB);
        m_animate->setObjectName(QString::fromUtf8("m_animate"));

        gridLayout_2->addWidget(m_animate, 3, 0, 1, 1);


        s_mainwindowgridlayout->addWidget(s_drawGB, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainwindowgridlayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        s_transGB = new QGroupBox(centralwidget);
        s_transGB->setObjectName(QString::fromUtf8("s_transGB"));
        s_transGB->setAutoFillBackground(false);
        gridLayout = new QGridLayout(s_transGB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_MassLabel = new QLabel(s_transGB);
        m_MassLabel->setObjectName(QString::fromUtf8("m_MassLabel"));

        gridLayout->addWidget(m_MassLabel, 0, 1, 1, 1);

        m_mass = new QDoubleSpinBox(s_transGB);
        m_mass->setObjectName(QString::fromUtf8("m_mass"));
        m_mass->setMinimum(18);
        m_mass->setMaximum(30);

        gridLayout->addWidget(m_mass, 0, 2, 1, 1);

        m_speed = new QDoubleSpinBox(s_transGB);
        m_speed->setObjectName(QString::fromUtf8("m_speed"));
        m_speed->setMinimum(0.1);

        gridLayout->addWidget(m_speed, 1, 2, 1, 1);

        m_MaxSpeedLabel = new QLabel(s_transGB);
        m_MaxSpeedLabel->setObjectName(QString::fromUtf8("m_MaxSpeedLabel"));

        gridLayout->addWidget(m_MaxSpeedLabel, 1, 1, 1, 1);

        m_force = new QDoubleSpinBox(s_transGB);
        m_force->setObjectName(QString::fromUtf8("m_force"));
        m_force->setMinimum(0.1);

        gridLayout->addWidget(m_force, 2, 2, 1, 1);

        m_MaxForceLabel = new QLabel(s_transGB);
        m_MaxForceLabel->setObjectName(QString::fromUtf8("m_MaxForceLabel"));

        gridLayout->addWidget(m_MaxForceLabel, 2, 1, 1, 1);

        m_seperation = new QDoubleSpinBox(s_transGB);
        m_seperation->setObjectName(QString::fromUtf8("m_seperation"));
        m_seperation->setValue(8);

        gridLayout->addWidget(m_seperation, 3, 2, 1, 1);

        m_cohesion = new QDoubleSpinBox(s_transGB);
        m_cohesion->setObjectName(QString::fromUtf8("m_cohesion"));
        m_cohesion->setValue(40);

        gridLayout->addWidget(m_cohesion, 4, 2, 1, 1);

        m_alignment = new QDoubleSpinBox(s_transGB);
        m_alignment->setObjectName(QString::fromUtf8("m_alignment"));
        m_alignment->setValue(8);

        gridLayout->addWidget(m_alignment, 5, 2, 1, 1);

        label = new QLabel(s_transGB);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        label_2 = new QLabel(s_transGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        label_3 = new QLabel(s_transGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);


        s_mainwindowgridlayout->addWidget(s_transGB, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
        s_drawGB->setTitle(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        m_wireframe->setText(QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8));
        m_addBoid->setText(QApplication::translate("MainWindow", "Add Boid", 0, QApplication::UnicodeUTF8));
        m_removeBoid->setText(QApplication::translate("MainWindow", "Remove Boid", 0, QApplication::UnicodeUTF8));
        m_animate->setText(QApplication::translate("MainWindow", "Play/Pause", 0, QApplication::UnicodeUTF8));
        s_transGB->setTitle(QString());
        m_MassLabel->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        m_MaxSpeedLabel->setText(QApplication::translate("MainWindow", "Max Speed", 0, QApplication::UnicodeUTF8));
        m_MaxForceLabel->setText(QApplication::translate("MainWindow", "Max Force", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Seperation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Cohesion", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Alignment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
