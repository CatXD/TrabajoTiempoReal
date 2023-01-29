#include "sm_trabajo.h"
#include <QApplication>
#include <unistd.h>
#include <pthread.h>
#include "valores_iniciales.h"
#include "definicion_pines.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


SM_trabajo * _machine_ptr;
Interfaz * _interfaz;

void spiSetup (int spiChannel)
{
    int valor;
    valor = wiringPiSPISetup (spiChannel, 10000);
    if ( valor< 0)
    {
        fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }
}


//void * generaSierra(void *param) {
//    Interfaz * dibu= static_cast < Interfaz * > (param);
//    double ySierra;
//    double pendiente=1;
//    int tSierra=0;
//    for (;;) {
//        if ( tSierra <= 25  ) {
//            ySierra=pendiente*tSierra;
//        }
//        else {
//            ySierra=50 -pendiente*tSierra;
//        }
//        tSierra = (1 + tSierra ) % 50 ;
//        usleep(100000);
//        if (0 == dibu->getModoControl()){
//            varCompartidas.salida=ySierra;
//        }
//    }
//}


//void * generaCuadrada(void *param) {
//    Interfaz * dibu= static_cast < Interfaz * > (param);
//    double yCuadrada =0.0;
//    int tCuadrada=0;
//    for (;;) {
//        if ( tCuadrada < 40  ) {
//            yCuadrada= 3;
//        }
//        else {
//            yCuadrada=-3;
//        }
//        tCuadrada = (1 + tCuadrada)  % 80 ;
//        usleep(50000);
//        if (1 == dibu->getModoControl()){
//            varCompartidas.salida=yCuadrada;
//        }
//    }
//}
void FuncionParar(){
    _interfaz->ui->ptLog->appendPlainText("Diego guarro");
    emit _machine_ptr->PARAR_signal();

}
void FuncionReanudar(){
    _interfaz->ui->ptLog->appendPlainText("Diego guarro");
    emit _machine_ptr->REANUDAR_signal();
}


int main(int argc, char *argv[])
{
    wiringPiSetupGpio();

    //SPI
    spiSetup(SPICHANNEL);

    //CONFIGURACION DE PINES
    pinMode(LED, OUTPUT);
    pinMode(PWM, PWM_OUTPUT);
    pinMode(PARAR, INPUT);
    pinMode(REANUDAR, INPUT);
    pullUpDnControl(PARAR,PUD_UP);
    pullUpDnControl(REANUDAR,PUD_UP);

    //CONFIGURACION DE LAS ISRS
    wiringPiISR (PARAR, INT_EDGE_FALLING, &FuncionParar);
    wiringPiISR (REANUDAR, INT_EDGE_FALLING,  &FuncionReanudar);


    ControladorMotor controlador;
    controlador.Init();
    QApplication a(argc, argv);
    Interfaz w(MODO_CONTROL_VEL,  nullptr, &controlador);
    SM_trabajo machine(&w,nullptr);
    _machine_ptr = &machine;
    _interfaz = &w;

    w.show();
//    pthread_t hiloSierra, hiloCuadrada;
//    pthread_create(&hiloSierra, nullptr, generaSierra, static_cast <void *> ( &w));
//    pthread_create(&hiloCuadrada, nullptr, generaCuadrada, static_cast <void *> ( &w));
    return a.exec();
}
