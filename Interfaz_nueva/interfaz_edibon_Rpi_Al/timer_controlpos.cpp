#include "timer_controlpos.h"
#include <QDebug>


//Timer_ControlPos::Timer_ControlPos(Regulador * reg)
//{

//}

void Timer_ControlPos::Init (Regulador * reg)
{

    // create a timer
    timer = new QTimer(this);
    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(timerSlot_pos()));

    regulador = reg;
}

void Timer_ControlPos::start()
{
    // msec
    T_actual = regulador->get_T();
    timer->start(T_actual);
}

void Timer_ControlPos::stop()
{
    timer->stop();
}


void Timer_ControlPos::timerSlot_pos()
{

    //Aqui control de posicion
    //Leo entradas

    //recta de calibracion

    //





    int t_nuevo = regulador->get_T();
    if (T_actual != t_nuevo)
    {
        T_actual = t_nuevo;
        timer->start(T_actual);
    }
}
