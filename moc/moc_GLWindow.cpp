/****************************************************************************
** Meta object code from reading C++ file 'GLWindow.h'
**
** Created: Tue Mar 20 19:06:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      41,   38,    9,    9, 0x0a,
      57,   38,    9,    9, 0x0a,
      77,   38,    9,    9, 0x0a,
      97,   38,    9,    9, 0x0a,
     116,   38,    9,    9, 0x0a,
     135,   38,    9,    9, 0x0a,
     154,    9,    9,    9, 0x0a,
     167,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWindow[] = {
    "GLWindow\0\0_mode\0toggleWireframe(bool)\0"
    "_m\0setMass(double)\0setMaxSpeed(double)\0"
    "setMaxForce(double)\0setSepDist(double)\0"
    "setCohDist(double)\0setAliDist(double)\0"
    "removeBoid()\0addBoid()\0"
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
        case 1: setMass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setMaxForce((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: setSepDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: setCohDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: setAliDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: removeBoid(); break;
        case 8: addBoid(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
