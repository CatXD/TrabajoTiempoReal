#ifndef SM_TRABAJO_H
#define SM_TRABAJO_H

#include "interfaz.h"
#include "ui_interfaz.h"
#include  <QObject>
#include <QStateMachine>
#include <QHistoryState>
#include <QFinalState>
#include <time.h>
#include <QEventTransition>
#include "Transicion_Parar.h"
#include "Transicion_Reanudar.h"
//#include <wiringPi.h>

#define PWM 23
#define PARAR 0
#define REANUDAR 2
#define LED 3


class SM_trabajo : public QObject
{
    Q_OBJECT
public:
    QStateMachine *MachineControl;
    Interfaz *w;
    ControladorMotor *motor;
    SM_trabajo (Interfaz *w,QObject *parent=nullptr);
private:
    QState *ON;
    QState *Control_Pos;
    QState *Control_Vel;
    QState *OFF;
    QHistoryState *ONh;
    QFinalState *Estado_Final;
    //transiciones
    Transicion_Parar *TRAN_PARAR;
    Transicion_Reanudar *TRAN_REANUDAR;

public:
    void suma(struct timespec&, struct timespec&);

public slots:
    void FuncionControlPos();
    void FuncionControlVel();
    //void ControlParado();
};


#endif // SM_TRABAJO_H
