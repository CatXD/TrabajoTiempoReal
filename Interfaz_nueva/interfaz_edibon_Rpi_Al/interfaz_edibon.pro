#-------------------------------------------------
#
# Project created by QtCreator 2020-01-23T21:18:26
#
#-------------------------------------------------

QT       += core gui widgets
QT       += statemachine
QT       += core


greaterThan(QT_MAJOR_VERSION, 4): QT +=  printsupport

TARGET = interfaz_edibon
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    controladormotor.cpp \
    main.cpp \
    placafisica.cpp \
    recta.cpp \
    recta3trozos.cpp \
    regulador.cpp \
    sm_trabajo.cpp \
    interfaz.cpp \
    qcustomplot.cpp


HEADERS += \
    controladormotor.h \
    placafisica.h \
    recta.h \
    recta3trozos.h \
    regulador.h \
    sm_trabajo.h \
    interfaz.h \
    qcustomplot.h \
    valores_iniciales.h

FORMS += \
    interfaz.ui

LIBS += -lpthread


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

