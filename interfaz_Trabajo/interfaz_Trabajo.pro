#-------------------------------------------------
#
# Project created by QtCreator 2020-01-23T21:18:26
#
#-------------------------------------------------

QT       += core gui widgets charts
QT += statemachine

greaterThan(QT_MAJOR_VERSION, 4): QT +=  printsupport

TARGET = interaz_Trabajo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    controladormotor.cpp \
    evento_externo.cpp \
    main.cpp \
    interfaz.cpp \
    regulador.cpp \
    sm_trabajo.cpp\
    recta.cpp \
    recta3trozos.cpp


HEADERS += \
    controladormotor.h \
    evento_externo.h \
    interfaz.h \
    regulador.h \
    sm_trabajo.h \
    valores_iniciales.h\
    recta.h \
    recta3trozos.h

FORMS += \
    interfaz.ui

#LIBS += -lwiringPi


