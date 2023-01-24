TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
    adcspi.cpp \
    recta.cpp \
    testcom.cpp

HEADERS += \
    adcspi.h \
    recta.h \
    testcom.h
    /usr/include/wiringPi.h
    /usr/include/wiringPiSpi.h

LIBS += -lwiringPi
