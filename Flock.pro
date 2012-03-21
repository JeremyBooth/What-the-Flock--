QT+=opengl \
    gui \
    core


INCLUDEPATH+=/usr/local/
INCLUDEPATH+=include \
           +=ui
OBJECTS_DIR=obj/
MOC_DIR=moc/
TARGET=Flock
DESTDIR =./
CONFIG += console
CONFIG -= app_bundle
UI_HEADERS_DIR=ui
SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/GLWindow.cpp \
    src/Boid.cpp \
    src/BoidManager.cpp \
    src/Predator.cpp \
    src/Scene.cpp \
    src/Lattice.cpp \
    src/Export.cpp \
    src/Goal.cpp

HEADERS += \
    include/MainWindow.h \
    include/GLWindow.h \
    include/Boid.h \
    include/BoidManager.h \
    include/Predator.h \
    include/Scene.h \
    include/Lattice.h \
    include/Export.h

OTHER_FILES+= shaders/Fragment.fs \
              shaders/Vertex.vs \
              shaders/Colour.fs \
              shaders/Colour.vs \
              shaders/Phong.fs  \
              shaders/Phong.vs

FORMS += \
    ui/MainWindow.ui

DEFINES+=USING_QT_CREATOR

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

# define the _DEBUG flag for the graphics lib
DEFINES +=NGL_DEBUG

LIBS += -L/usr/local/lib
# add the ngl lib
LIBS +=  -L/$(HOME)/NGL/lib -l NGL

# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-g++ {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-g++-64 {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
DEPENDPATH+=include
# if we are on a mac define DARWIN
macx:DEFINES += DARWIN

# this is where to look for includes
INCLUDEPATH += $$(HOME)/NGL/include/

win32: {
        DEFINES+=USING_GLEW
        INCLUDEPATH+=-I c:/boost_1_44_0
        INCLUDEPATH+= -I C:/NGL/Support/glew
        LIBS+= -L C:/NGL/lib
        LIBS+= -lmingw32
}

