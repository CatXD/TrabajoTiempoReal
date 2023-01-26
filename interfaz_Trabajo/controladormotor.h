#ifndef CONTROLADORMOTOR_H
#define CONTROLADORMOTOR_H
#include "regulador.h"
#include "valores_iniciales.h"
#include "recta3trozos.h"
#include "placafisica.h"

class ControladorMotor
{
public:
    //NECESITAREMOS 2 INSTANCIAS DEL REGULADOR reg_pos, reg_vel
    ControladorMotor();
    Regulador reg_pos{CONTROL_POSKP,CONTROL_POSKI,CONTROL_POSKD,Tms};
    Regulador reg_vel{CONTROL_VELKP,CONTROL_VELKI,CONTROL_VELKD,Tms};
    Recta Ref_To_Grados{PEND_REFTOGRADOS,ORD_ORIGEN_REFTOGRADOS};
    Recta3Trozos VELADC_TO_RPM;
    PlacaFisica placaFisica;

};
#endif // CONTROLADORMOTOR_H
