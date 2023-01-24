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

    //transicciones
    //QEventTransition *enterTransition = new QEventTransition(button, QEvent::Enter);
    ON->addTransition(w->ui->botonParar,SIGNAL(clicked()),OFF);
    OFF->addTransition(w->ui->botonReanudar,SIGNAL(clicked()),ON);
    ON->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    OFF->addTransition(w->ui->botonFinalizar,SIGNAL(clicked()),Estado_Final);
    Control_Pos->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Vel);
    Control_Vel->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Pos);
    //faltan los eventos de la interfaz

    connect(Control_Pos,SIGNAL(entered()),this,SLOT(FuncionControlPos()));
    connect(Control_Vel,SIGNAL(entered()),this,SLOT(FuncionControlVel()));
    //esto creo que lo podríamos hacer en la ISR del main
    //*****
    //connect(OFF,SIGNAL(entered()),this,SLOT(ParpadeoLED()));
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

void SM_trabajo::suma(timespec &t1, timespec &t2)
{
    t1.tv_nsec+=t2.tv_nsec; //primero sumo los nanosegundos
    t1.tv_sec+=t2.tv_sec;   //despues los segundos
    if(t1.tv_nsec>=1e9){    //y ajustamos los nanosegundos
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }
}

void SM_trabajo::FuncionControlPos()
{
    struct timespec t1,t2;
    t1.tv_nsec=motor->reg_pos.get_T()*1e6;//para pasar a segundos
    if(t1.tv_nsec>=1e9){
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }
    clock_gettime(CLOCK_REALTIME,&t2); //capturamos el tiempo actual
    while(1){
        suma(t2,t1); //sumo al tiempo actual el periodo del hilo
        //aqui hacer
        //todo lo relacionado
        //con el lazo de control de POS
        clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&t2,NULL); //espero el tiempo determinado
    }
}

void SM_trabajo::FuncionControlVel()
{
    struct timespec t1,t2;
    t1.tv_nsec=motor->reg_vel.get_T()*1e6;//para pasar a segundos
    if(t1.tv_nsec>=1e9){
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }

    while(1){
        suma(t2,t1); //sumo al tiempo actual el periodo del hilo
        //aqui hacer
        //todo lo relacionado
        //con el lazo de control de VEL
        clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&t2,NULL); //espero el tiempo determinado
    }
}
