#include "timer_controlpos.h"
#include <QDebug>


//Timer_ControlPos::Timer_ControlPos(Regulador * reg)
//{

//}

void Timer_ControlPos::Init (Regulador * reg, Regulador * reg_vel)
{
    VELADC_TO_RPM.SetTramo1(TRAMO1_PEND, TRAMO1_CRUCEY);
    VELADC_TO_RPM.SetTramo2 (CRUCE12, TRAMO2, CRUCE23);
    VELADC_TO_RPM.SetTramo3(TRAMO3_PEND, TRAMO3_CRUCEY);

    // create a timer
    timer = new QTimer(this);
    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(timerSlot_pos()));

    regulador = reg;
    regulador_vel = reg_vel;
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
    int pos_act_raw, pos_ref_raw;
    double pos_grados, vel_ref, pos_ref_grados;

    contador--;

    if (contador <= 0)
    {

    //Leo entradas
    pos_act_raw = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_POT);
    pos_ref_raw = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_REF) / 21;

    //recta de calibracion
    pos_grados = 360.0 / 1023.0 * (pos_act_raw - 512);
    pos_ref_grados = Ref_To_Grados.calcularY(pos_ref_raw);
    regulador->set_consigna (pos_ref_grados);

    //Regulador
    vel_ref = regulador->calculaAccionControl(regulador->get_consigna(), pos_grados, -45, 45);
    regulador_vel->set_consigna(vel_ref);

    printf("Consigna grados: %f, Pos grados: %f, Vel ref: %f\n", regulador->get_consigna(), pos_grados, regulador_vel->get_consigna());

    contador = 10;
    }


    // Regulador de velocidad

    int vel_act_raw;
    double vel_rpm, accion_control;

    //Leo entradas velocidad
    vel_act_raw = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);

    //recta de calibracion
    vel_rpm = VELADC_TO_RPM.GetValue(vel_act_raw);

    //Regulador velocidad
    accion_control = regulador->calculaAccionControl(regulador->get_consigna(), vel_rpm, 0, 1023);

    pwmWrite(PWM, accion_control);


    int t_nuevo = regulador->get_T();
    if (T_actual != t_nuevo)
    {
        T_actual = t_nuevo;
        //timer->start(T_actual);
        timer->setInterval(t_nuevo);   }
}
