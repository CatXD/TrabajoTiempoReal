#ifndef VALORES_INICIALES_H
#define VALORES_INICIALES_H

#define CONTROL_VELKP 3
#define CONTROL_VELKI 1
#define CONTROL_VELKD 0

#define CONTROL_POSKP 10
#define CONTROL_POSKI 1
#define CONTROL_POSKD 1

#define POS_MIN -180
#define POS_MAX 180

#define VEL_MIN -40
#define VEL_MAX 46

#define MODO_CONTROL_VEL 1
#define MODO_CONTROL_POS 0

//para las rectas de calibracion
//para pasar pasar la referencia a grados
#define PEND_REFTOGRADOS (-0.32693) //(-0.32972) modulo 5
#define ORD_ORIGEN_REFTOGRADOS 163.06 //166.05 modulo 5

//para la funcion a trozos de velocidad analogica a rpms
//zona 1
#define TRAMO1_CRUCEY (-116.22) //(-127.53) modulo 5
#define TRAMO1_PEND 0.21668 //0.24004 modulo 5
//zona muerta
#define CRUCE12 490.0 //503.0 modulo 5
#define TRAMO2 0.0 //0.0 modulo 5
#define CRUCE23 521.0 //596.0 modulo 5
//zona 3
#define TRAMO3_CRUCEY (-111.76) //(-145.69) modulo 5
#define TRAMO3_PEND 0.21663 //0.26600 modulo 5

#define Tms 500 //en ms



#endif // VALORES_INICIALES_H

