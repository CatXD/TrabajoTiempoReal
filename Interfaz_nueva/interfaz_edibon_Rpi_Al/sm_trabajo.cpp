#include "sm_trabajo.h"
#include <iostream>
using namespace std;

//se puede hacer utilizando como plantilla el
//estados_jerarquicos_alumnos.zip

SM_trabajo::SM_trabajo(Interfaz *wpt, QObject *parent)    : QObject(parent)
{
    w=wpt;
    MachineControl = new QStateMachine();
    ON=new QState(MachineControl);
    Control_Pos=new QState(ON);
    Control_Vel=new QState(ON);
    OFF=new QState(MachineControl);
    ONh=new QHistoryState(ON);
    Estado_Final = new QFinalState(MachineControl);
    motor = w->getControlMotor();////////////////////////////////

    //transicciones
    ON->addTransition(w->ui->botonParar,SIGNAL(clicked()),OFF);
    ON->addTransition(this,SIGNAL(PARAR_signal()),OFF);
    OFF->addTransition(w->ui->botonReanudar,SIGNAL(clicked()),ON);
    OFF->addTransition(this,SIGNAL(REANUDAR_signal()),ON);
    ON->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    OFF->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    Control_Pos->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Vel);
    Control_Vel->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Pos);


    //connect(Control_Pos,SIGNAL(entered()),this,SLOT(FuncionControlPos()));
    connect(Control_Pos,SIGNAL(entered()),&motor->timer_pos,SLOT(start()));
    connect(Control_Pos,SIGNAL(exited()),&motor->timer_pos,SLOT(stop()));
    //connect(motor->timer_pos.timer,SIGNAL(timeout()), &motor->timer_pos,  SLOT(timerSlot_pos()));

    //connect(Control_Vel,SIGNAL(entered()),this,SLOT(FuncionControlVel()));
    connect(Control_Vel,SIGNAL(entered()),&motor->timer_vel,SLOT(start()));
    connect(Control_Vel,SIGNAL(exited()),&motor->timer_vel,SLOT(stop()));
    //connect(motor->timer_vel.timer,SIGNAL(timeout()), &motor->timer_vel,  SLOT(timerSlot_vel()));

    //connect(OFF,SIGNAL(entered()),this,SLOT(ParpadeoLED()));
    connect(OFF,SIGNAL(entered()),&motor->timer_blinked,SLOT(Blink_LED_start()));
    connect(OFF,SIGNAL(exited()),&motor->timer_blinked,SLOT(Blink_LED_stop()));

    //esto creo que lo podríamos hacer en la ISR del main
    //*****   
    //connect(Estado_Final,SIGNAL(entered()),this,SLOT(ApagarPinesRPI()));
    //*****
    MachineControl->setInitialState(ON);
    ON->setInitialState(Control_Vel);
    MachineControl->start();
}

