#ifndef CONTROLADORMOTOR_H
#define CONTROLADORMOTOR_H

#include "timer_controlvel.h"
#include "timer_controlpos.h"
#include "timer_blinkled.h"
#include "regulador.h"
#include "valores_iniciales.h"
#include "recta3trozos.h"
#include  <QObject>



class ControladorMotor //: public QObject
{
    //Q_OBJECT
public:
    //NECESITAREMOS 2 INSTANCIAS DEL REGULADOR reg_pos, reg_vel
    //ControladorMotor();
    Regulador reg_pos{CONTROL_POSKP,CONTROL_POSKI,CONTROL_POSKD,Tms};
    Regulador reg_vel{CONTROL_VELKP,CONTROL_VELKI,CONTROL_VELKD,Tms};


    Timer_ControlPos timer_pos;
    Timer_ControlVel timer_vel;
    Timer_BlinkLED timer_blinked;
    void Init();


//signals:
//    void PARAR_signal(void);
//    void REANUDAR_signal(void);
};

#endif // CONTROLADORMOTOR_H
