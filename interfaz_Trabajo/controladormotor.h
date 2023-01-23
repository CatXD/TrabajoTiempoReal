#ifndef CONTROLADORMOTOR_H
#define CONTROLADORMOTOR_H

#include "regulador.h"
#include "valores_iniciales.h"

class ControladorMotor
{

public:
    ControladorMotor();
    //NECESITAREMOS 2 INSTANCIAS DEL REGULADOR reg_pos, reg_vel
    Regulador reg_pos{CONTROL_POSKP,CONTROL_POSKI,CONTROL_POSKD,Tms};
    Regulador reg_vel{CONTROL_VELKP,CONTROL_VELKI,CONTROL_VELKD,Tms};
};

#endif // CONTROLADORMOTOR_H
