#include "sm_trabajo.h"
#include <QApplication>
//#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include "valores_iniciales.h"

using namespace  std;

SM_trabajo * _machine_ptr;
Interfaz * _interfaz;

typedef enum {sierra, cuadrada} control;


double t=0.0;
double y=0.0;


void * generaSierra(void *param) {
    Interfaz * dibu= static_cast < Interfaz * > (param);
    double ySierra;
    double pendiente=1;
    int tSierra=0;
    int signo=0;
    for (;;) {
        if ( tSierra <= 25  ) {
            ySierra=pendiente*tSierra;
        }
        else {
            ySierra=50 -pendiente*tSierra;
        }
        tSierra = ++tSierra % 50 ;
        usleep(50000);
        if (0 == dibu->getModoControl()){
            cout <<"TRampa "<< tSierra<< " pares "<< t <<"  "<<ySierra<<"  signo"<< signo<< endl;
            t=t+0.2;
            y=ySierra;
        }
    }
}


void * generaCuadrada(void *param) {
    Interfaz * dibu= static_cast < Interfaz * > (param);
    double yCuadrada =0.0;
    int tCuadrada=0;
    for (;;) {
        if ( tCuadrada < 40  ) {
            yCuadrada= 3;
        }
        else {
            yCuadrada=-3;
        }
        tCuadrada = ++tCuadrada % 80 ;

        usleep(50000);
        if (1 == dibu->getModoControl()){
            cout <<"TCuadrada "<< tCuadrada<< " pares "<< t <<"  "<<y<< endl;
            t=t+0.1;;
            y=yCuadrada;
        }
    }
}

void *dibujar(void *param)
{
    Interfaz * dibu= static_cast < Interfaz * > (param);

    while(1){
        dibu->muestraDatoSlot(t,1.0,y);
        usleep(100000);
    }
}

void FuncionParar(){
    emit _interfaz->getControlMotor()->placaFisica.PARAR_signal();

}
void FuncionReanudar(){
    emit _interfaz->getControlMotor()->placaFisica.REANUDAR_signal();
}

int main(int argc, char *argv[])
{
    /*wiringPiSetupGpio();
    //CONFIGURACION DE PINES
    pinMode(LED, OUTPUT);
    pinMode(PWM, PWM_OUTPUT);
    pinMode(PARAR, INPUT);
    pinMode(REANUDAR, INPUT);
    pullUpDnControl(PARAR,PUD_UP);
    pullUpDnControl(REANUDAR,PUD_UP);

    //CONFIGURACION DE LAS ISRS
    wiringPiISR (int PARAR, int INT_EDGE_FALLING, &FuncionParar);
    wiringPiISR (int REANUDAR, int INT_EDGE_FALLING,  &FuncionReanudar);*/


    ControladorMotor controlador;
    QApplication a(argc, argv);
    Interfaz w(MODO_CONTROL_VEL,  nullptr, &controlador);
    SM_trabajo machine(&w,nullptr);

    _machine_ptr = &machine;
    _interfaz = &w;

    //machine.
    w.show();
    pthread_t hiloSierra, hiloCuadrada, hiloDibujar;
    pthread_create(&hiloSierra, nullptr, generaSierra, static_cast <void *> ( &w));
    pthread_create(&hiloCuadrada, nullptr, generaCuadrada, static_cast <void *> ( &w));
    pthread_create(&hiloDibujar, nullptr, dibujar, static_cast <void *> ( &w));

    return a.exec();
}
