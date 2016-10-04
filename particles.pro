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
    temporalparticle.cpp \
    renderable.cpp \
    renderer.cpp \
    glwidget.cpp \
    helper.cpp \
    qwidgetrenderer.cpp \
    particlecollection.cpp

HEADERS += \
    particle.h \
    temporalparticle.h \
    renderable.h \
    renderer.h \
    glwidget.h \
    helper.h \
    qwidgetrenderer.h \
    vec3.h \
    particlecollection.h