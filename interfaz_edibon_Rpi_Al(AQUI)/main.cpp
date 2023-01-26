#include "sm_trabajo.h"
#include <QApplication>
#include <unistd.h>
#include <pthread.h>
#include "valores_iniciales.h"


SM_trabajo * _machine_ptr;
Interfaz * _interfaz;

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
//            _interfaz.->reg_vel.get_consigna()=ySierra;
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
//    pthread_create(&hiloSierra, nullptr, generaSierra, static_cast <void *> ( &w));
//    pthread_create(&hiloCuadrada, nullptr, generaCuadrada, static_cast <void *> ( &w));
//    pthread_create(&hiloDibujar, nullptr, dibujar, static_cast <void *> ( &w));

    return a.exec();
}
