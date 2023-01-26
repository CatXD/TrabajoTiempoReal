#include "interfaz.h"
#include <QApplication>
#include <unistd.h>
#include <pthread.h>
#include "varcompartidas.h"

static VarCompartidas varCompartidas;

void * generaSierra(void *param) {
    Interfaz * dibu= static_cast < Interfaz * > (param);
    double ySierra;
    double pendiente=1;
    int tSierra=0;
    for (;;) {
        if ( tSierra <= 25  ) {
            ySierra=pendiente*tSierra;
        }
        else {
            ySierra=50 -pendiente*tSierra;
        }
        tSierra = (1 + tSierra ) % 50 ;
        usleep(100000);
        if (0 == dibu->getModoControl()){
            varCompartidas.salida=ySierra;
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
        tCuadrada = (1 + tCuadrada)  % 80 ;
        usleep(50000);
        if (1 == dibu->getModoControl()){
            varCompartidas.salida=yCuadrada;
        }
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interfaz w(&varCompartidas);
    w.show();
    pthread_t hiloSierra, hiloCuadrada;
    pthread_create(&hiloSierra, nullptr, generaSierra, static_cast <void *> ( &w));
    pthread_create(&hiloCuadrada, nullptr, generaCuadrada, static_cast <void *> ( &w));
    return a.exec();
}
