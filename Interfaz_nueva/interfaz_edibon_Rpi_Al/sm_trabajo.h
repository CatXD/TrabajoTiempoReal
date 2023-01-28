#ifndef SM_TRABAJO_H
#define SM_TRABAJO_H

#include "interfaz.h"
#include "ui_interfaz.h"
#include  <QObject>
#include <QStateMachine>
#include <QHistoryState>
#include <QFinalState>
#include <time.h>
#include "definicion_pines.h"


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


signals:
    void PARAR_signal(void);
    void REANUDAR_signal(void);


};


#endif // SM_TRABAJO_H
