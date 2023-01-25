#ifndef VALORES_INICIALES_H
#define VALORES_INICIALES_H

#define CONTROL_VELKP 1
#define CONTROL_VELKI 10
#define CONTROL_VELKD 100

#define CONTROL_POSKP 2
#define CONTROL_POSKI 20
#define CONTROL_POSKD 200

#define POS_MIN -180
#define POS_MAX 180

#define VEL_MIN -45
#define VEL_MAX 45

#define MODO_CONTROL_VEL 1
#define MODO_CONTROL_POS 0

//para las rectas de calibracion
//para pasar pasar la referencia a grados
#define PEND_REFTOGRADOS (-0.32972)
#define ORD_ORIGEN_REFTOGRADOS 166.05

//para la funcion a trozos de velocidad analogica a rpms
//zona 1
#define TRAMO1_CRUCEY (-127.53)
#define TRAMO1_PEND 0.24004
//zona muerta
#define CRUCE12 503.0
#define TRAMO2 0.0
#define CRUCE23 596.0
//zona 3
#define TRAMO3_CRUCEY (-145.69)
#define TRAMO3_PEND 0.26600




#define Tms 200 //en ms



#endif // VALORES_INICIALES_H

