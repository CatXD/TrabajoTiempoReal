#ifndef CONTROLADORMOTOR_H
#define CONTROLADORMOTOR_H

#include "regulador.h"
#include "valores_iniciales.h"
#include "recta3trozos.h"
#include <pthread.h>
#include <semaphore.h>

class ControladorMotor
{
protected:
    bool flag_exterminate_h_reg_vel;
    bool flag_exterminate_h_reg_pos;

public:
    pthread_t h_reg_vel;
    pthread_t h_reg_pos;

    sem_t sem_cambio_pos2vel;
    sem_t sem_cambio_vel2pos;

    ControladorMotor();
    //NECESITAREMOS 2 INSTANCIAS DEL REGULADOR reg_pos, reg_vel
    Regulador reg_pos{CONTROL_POSKP,CONTROL_POSKI,CONTROL_POSKD,Tms};
    Regulador reg_vel{CONTROL_VELKP,CONTROL_VELKI,CONTROL_VELKD,Tms};
    Recta Ref_To_Grados{PEND_REFTOGRADOS,ORD_ORIGEN_REFTOGRADOS};
    Recta3Trozos VELADC_TO_RPM;

    void Init();
    void BucleControl_Pos ();
    void BucleControl_Vel ();

    void Exterminar_BucleControl_Pos();
    void Exterminar_BucleControl_Vel();

};

#endif // CONTROLADORMOTOR_H
