#ifndef SM_TRABAJO_H
#define SM_TRABAJO_H

#include "interfaz.h"
#include  <QObject>
#include <QStateMachine>
#include <QHistoryState>
#include <QFinalState>
//#include <QEvent>
//#include <wiringPi.h>

#define PWM 23
#define PARAR 0
#define REANUDAR 2
#define LED 3


//NECESITAREMOS 2 INSTANCIAS DEL REGULADOR reg_pos, reg_vel
Regulador reg_pos(CONTROL_POSKP,CONTROL_POSKI,CONTROL_POSKD,Tms);
Regulador reg_vel(CONTROL_VELKP,CONTROL_VELKI,CONTROL_VELKD,Tms);

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
    QState *ControlVel;
    QState *OFF;
    QHistoryState *ONh;
    QFinalState *Estado_Final;

public slots:
    /*void s11Entrar();
    void s11Salir();
    void s12Entrar();
    void s12Salir();
    void s13Entrar();
    void s13Salir();
    void s2Entrar();
    void s2Salir();*/
};


#endif // SM_TRABAJO_H
