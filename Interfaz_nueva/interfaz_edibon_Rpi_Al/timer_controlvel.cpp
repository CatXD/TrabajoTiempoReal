#include "timer_controlvel.h"
#include <QDebug>



void Timer_ControlVel::Init (Regulador * reg)
{
    VELADC_TO_RPM.SetTramo1(TRAMO1_PEND, TRAMO1_CRUCEY);
    VELADC_TO_RPM.SetTramo2 (CRUCE12, TRAMO2, CRUCE23);
    VELADC_TO_RPM.SetTramo3(TRAMO3_PEND, TRAMO3_CRUCEY);
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
    int vel_act_raw;
    double vel_rpm, accion_control;

    //Leo entradas
    vel_act_raw = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);

    //recta de calibracion
    vel_rpm = VELADC_TO_RPM.GetValue(vel_act_raw);

    //Regulador
    accion_control = regulador->calculaAccionControl(regulador->get_consigna(), vel_rpm, 0, 1023);


    printf("U Vel= %f\n",accion_control);
    pwmWrite(PWM, accion_control);

    int t_nuevo = regulador->get_T();
    if (T_actual != t_nuevo)
    {
        T_actual = t_nuevo;
        timer->start(T_actual);
    }
}
