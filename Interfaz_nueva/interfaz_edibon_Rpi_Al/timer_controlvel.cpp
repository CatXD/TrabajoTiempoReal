#include "timer_controlvel.h"
#include <QDebug>



void Timer_ControlVel::Init (Regulador * reg)
{
    // create a timer
    timer = new QTimer(this);
    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(timerSlot_vel()));

    regulador = reg;
}

void Timer_ControlVel::start()
{
    // msec
    T_actual = regulador->get_T();
    timer->start(T_actual);
}

void Timer_ControlVel::stop()
{
    timer->stop();
}


void Timer_ControlVel::timerSlot_vel()
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
