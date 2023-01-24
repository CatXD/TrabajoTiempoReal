#ifndef SM_TRABAJO_H
#define SM_TRABAJO_H

#include "interfaz.h"
#include "ui_interfaz.h"
#include  <QObject>
#include <QStateMachine>
#include <QHistoryState>
#include <QFinalState>
#include <time.h>
//#include <QEvent>
//#include <wiringPi.h>

#define PWM 23
#define PARAR 0
#define REANUDAR 2
#define LED 3


class SM_trabajo : public QObject
{
    Q_OBJECT
public:
    Interfaz *w;
    SM_trabajo (Interfaz *w,QObject *parent=nullptr);
private:
    QStateMachine *MachineControl;
    QState *ON;
    QState *Control_Pos;
    QState *Control_Vel;
    QState *OFF;
    QHistoryState *ONh;
    QFinalState *Estado_Final;

public:
    void suma(struct timespec&, struct timespec&);

public slots:
    /*void ControlPosicion();
    void ControlVelocidad();
    void ControlParado();*/
};


#endif // SM_TRABAJO_H
