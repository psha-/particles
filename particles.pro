#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T23:33:45
#
#-------------------------------------------------

QT       += widgets

TARGET = particles
CONFIG   += console
CONFIG   -= app_bundle
CONFIG  += c++11

TEMPLATE = app

SOURCES += main.cpp \
    particle.cpp \
    renderer.cpp \
    glwidget.cpp \
    qwidgetrenderer.cpp \
    painthelper.cpp \
    explosionparticle.cpp \
    rectangle.cpp \
    boundable.cpp \
    explosion.cpp \
    renderable.cpp \
    environment.cpp \
    interestingenvironment.cpp \
    fluidenvironment.cpp

HEADERS += \
    particle.h \
    renderable.h \
    renderer.h \
    glwidget.h \
    qwidgetrenderer.h \
    vec3.h \
    particlecollection.h \
    painthelper.h \
    explosionparticle.h \
    particlesource.h \
    quadtree.h \
    quadtreenode.h \
    boundable.h \
    rectangle.h \
    quadrant.h \
    explosion.h \
    environment.h \
    interestingenvironment.h \
    fluidenvironment.h

DISTFILES += \
    CMakeLists.txt \
    TestCases
