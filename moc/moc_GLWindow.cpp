/****************************************************************************
** Meta object code from reading C++ file 'GLWindow.h'
**
** Created: Fri Mar 23 11:59:32 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      38,   10,    9,    9, 0x0a,
      64,   10,    9,    9, 0x0a,
      90,   10,    9,    9, 0x0a,
     112,  109,    9,    9, 0x0a,
     128,  109,    9,    9, 0x0a,
     148,  109,    9,    9, 0x0a,
     168,  109,    9,    9, 0x0a,
     187,  109,    9,    9, 0x0a,
     206,  109,    9,    9, 0x0a,
     225,  109,    9,    9, 0x0a,
     241,    9,    9,    9, 0x0a,
     254,    9,    9,    9, 0x0a,
     264,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWindow[] = {
    "GLWindow\0\0_mode\0toggleWireframe(bool)\0"
    "toggleBoidAnimation(bool)\0"
    "toggleGoalAnimation(bool)\0toggleRecord(bool)\0"
    "_m\0setMass(double)\0setMaxSpeed(double)\0"
    "setMaxForce(double)\0setSepDist(double)\0"
    "setCohDist(double)\0setAliDist(double)\0"
    "setGoalInf(int)\0removeBoid()\0addBoid()\0"
    "resetGoals()\0"
};

const QMetaObject GLWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWindow,
      qt_meta_data_GLWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWindow))
        return static_cast<void*>(const_cast< GLWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: toggleWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: toggleBoidAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: toggleGoalAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: toggleRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setMass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: setMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: setMaxForce((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: setSepDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setCohDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: setAliDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setGoalInf((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: removeBoid(); break;
        case 12: addBoid(); break;
        case 13: resetGoals(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
