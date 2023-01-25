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
    motor = w->getControlMotor();

    //para transiciones desde ISRs del main.cpp
    /*TRAN_PARAR = new Transicion_Parar();
    TRAN_REANUDAR = new Transicion_Reanudar();*/

    //transicciones
    ON->addTransition(w->ui->botonParar,SIGNAL(clicked()),OFF);
    OFF->addTransition(w->ui->botonReanudar,SIGNAL(clicked()),ON);
    ON->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    OFF->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    Control_Pos->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Vel);
    Control_Vel->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Pos);


    connect(Control_Pos,SIGNAL(entered()),this,SLOT(FuncionControlPos()));
    connect(Control_Vel,SIGNAL(entered()),this,SLOT(FuncionControlVel()));
    connect(OFF,SIGNAL(entered()),this,SLOT(ParpadeoLED()));
    //esto creo que lo podríamos hacer en la ISR del main
    //*****   
    //connect(Estado_Final,SIGNAL(entered()),this,SLOT(ApagarPinesRPI()));
    //*****
    MachineControl->setInitialState(ON);
    ON->setInitialState(Control_Vel);
    MachineControl->start();


    //ON->addTransition()



//rellenar todo --> transicciones + connects

    //PROTOTIPO DE FUNCION Entry/Exit
    /*void SM_trabajo::s11Entrar()
    {
        w->cambiarColorActivado(w->labelS11);
    }*/
}

void SM_trabajo::Llamar_ControlPos()
{
    w->ui->ptLog->appendPlainText("realizando control de posicion");

    pthread_create (&motor.h_reg_pos, nullptr, BucleControl_Pos, nullptr);
}

void SM_trabajo::Llamar_ControlPos()
{
    motor->Exterminar_BucleControl_Pos();
}

void SM_trabajo::Llamar_ControlVel()
{
    w->ui->ptLog->appendPlainText("realizando control de velocidad");

    pthread_create (&motor.h_reg_vel, nullptr, BucleControl_Vel, nullptr);
}

void SM_trabajo::Llamar_ControlVel()
{
    motor->Exterminar_BucleControl_Vel();
}