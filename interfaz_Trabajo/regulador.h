#ifndef REGULADOR_H
#define REGULADOR_H

#include<pthread.h>

//Necesitaremos 1 mutex, int:KP,KI,KD,T ¿ALGO MAS?
class Regulador
{   
    //Parametros configurables
    int T;                //periodo de muestreo

    double KP;            //accion proporcional
    double KI;            //accion integral
    double KD;            //accion diferencial

    //Variables internas
    double I;             //Valor del integrador
    double error_ans;     //error anterior

    //Estado
    double consigna_actual;
    double salida_actual;

    // double ref;
    // double pos;
    // double vel;
    pthread_mutex_t mutex;//creado para garantizar la exclusion mutua de la pantalla accediendo a KP


public:
    Regulador(double KP, double KI, double KD, int T);
    //setters y getters de las variables compartidas
    void set_KP(double KP);
    double get_KP(void);
    void set_KI(double KI);
    double get_KI(void);
    void set_KD(double KD);
    double get_KD(void);
    void set_T(int T);
    int get_T(void);
    // void set_ref(double ref);
    // double get_ref(void);
    // void set_pos(double pos);
    // double get_pos(void);
    // void set_vel(double vel);
    // double get_vel(void);

    double calculaAccionControl (double consigna, double y_medida);
};

#endif // REGULADOR_H
