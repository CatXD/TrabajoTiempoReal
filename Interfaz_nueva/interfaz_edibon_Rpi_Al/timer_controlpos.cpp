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
    int pos_act_raw;
    double pos_grados, accion_control;

    //Leo entradas
    pos_act_raw = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_POT);

    //recta de calibracion
    pos_grados = 360.0 / 1023.0 * (pos_act_raw - 512);

    //Regulador
    accion_control = regulador->calculaAccionControl(regulador->get_consigna(), pos_grados, 0, 1023);


    printf("Pos grados: %f, U Pos= %f\n",pos_grados, accion_control);
    pwmWrite(PWM, accion_control);





    int t_nuevo = regulador->get_T();
    if (T_actual != t_nuevo)
    {
        T_actual = t_nuevo;
        timer->start(T_actual);
    }
}
