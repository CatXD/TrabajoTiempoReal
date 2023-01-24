#include <iostream>
#include <iomanip>
#include <errno.h>
#include <string.h>
//#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "testcom.h"
#include "pid.h"
#include "adcspi.h"

#define CANAL_ADC_V 0
#define CANAL_ADC_POS 1
#define CANAL_ADC_POTEN 2

#define PWM_PIN 1
#define LED_PIN 0

using namespace std;

int main()
{   
    if ( wiringPiSetup() == -1)    {
        cerr << "error al inicializar wiringPi " <<  strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    pinMode(PWM_PIN, PWM_OUTPUT);
    pinMode(LED_PIN,OUTPUT);

    AdcSpi adcMCP3008Single;
    adcMCP3008Single.setSpiChannel(0);
    Recta rectaConversor;
    Recta rectaSensor;
    rectaConversor.setPendiente(pow(2,10)/5);
    rectaSensor.setPendiente(360/5);
    TestCom test( CANAL_ADC_V,CANAL_ADC_POS, CANAL_ADC_POTEN,PWM_PIN);
    test.setConversor(&adcMCP3008Single,&rectaConversor );
 //   test.correspondenciaPWMTensionVelocidad();


    reguladorP *regPosicion= new  reguladorP (4);


    double refPosicionGrados=-165;
    double errorPos=10;
    int bitsPosicion=0;
    double voltiosPos=0;
    double gradosPosicion=0;
    double actuadorPos=0;
    char start;
    pwmWrite(PWM_PIN, 512);
//    cout << "Espera a que pare y pulsa algo" ;
//    cin >> start;

        test.interactivePWM();
    cout << "Control posicion " << endl;
    while (refPosicionGrados < 150)
    {
        while ( abs(errorPos) > 0.5) {
            bitsPosicion = adcMCP3008Single.adcReadSingle(CANAL_ADC_POS);
            voltiosPos= rectaConversor.calcularX(bitsPosicion);
            gradosPosicion = rectaSensor.calcularX(voltiosPos);
            errorPos = refPosicionGrados - gradosPosicion;
            actuadorPos =  regPosicion->calcularUk(errorPos);
            pwmWrite(PWM_PIN, static_cast<int> (actuadorPos) );
            delay(100);

        }
        cout<<"refPosicion = "<< refPosicionGrados << " error= "<<errorPos<<
              " valor conversor= "<< bitsPosicion << " voltios " << voltiosPos <<
              " gradosPosicion = " << gradosPosicion << endl;
              refPosicionGrados += 10;

    }

    pwmWrite(PWM_PIN, 512);

}
