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
    Control_Pos->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),ControlVel);
    Control_Vel->addTransition(w->ui->toggleModoControl,SIGNAL(clicked()),Control_Pos);


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
