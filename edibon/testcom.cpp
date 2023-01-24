#include "testcom.h"
#include <iostream>
#include <iomanip>
#include "pid.h"

#define T_INC_PWM   50 // tiempo en ms

using namespace std;

TestCom:: TestCom(int chVel, int chPos, int chPoten, int pinPWM):
    canalEntradaVelocidad_(chVel), canalEntradaPosicion_ (chPos),
    canalRefPotenciometro_ (chPoten),  pinPWM_ (pinPWM) {
    conversorADC_ = nullptr ;
}

void TestCom::setConversor(AdcSpi *conversor, Recta *recta) {
    conversorADC_ = conversor;
    rectaConversor_ = recta;
}

void TestCom::setSensor( Recta *recta) {
    rectaSensor_ = recta;
}


void TestCom::correspondenciaPWMTensionVelocidad( ){
    double pwmTensionRPM[1024][4];
    cout<< setprecision(5);
    cout << "PWM \tValor Conversor \tTension" << endl;

    for (int i = 0; i < 10; ++i) {
        pwmWrite(pinPWM_,i);
        delay(T_INC_PWM);
        pwmTensionRPM[i][0]=static_cast <double> (i);
        pwmTensionRPM[i][1]=static_cast <double> (conversorADC_->adcReadSingle(canalEntradaVelocidad_) );
        pwmTensionRPM[i][2]= rectaConversor_->calcularX( pwmTensionRPM[i][1] );
   //     pwmTensionRPM[i][3]= rectaSensor_->calcularX( pwmTensionRPM[i][2] );
        cout << pwmTensionRPM[i][0]<<"\t\t"<<pwmTensionRPM[i][1] << "\t\t"<<pwmTensionRPM[i][2]<<endl;
    }
}

void TestCom::interactivePWM(){
    int valor=0;
    while (valor >=0 )
    {
        cout<<" Valor para pwm  ";
        cin>>valor;
        pwmWrite(pinPWM_,valor );
        cout << "PWM = "<<valor <<" Var leida Velocidad " <<  conversorADC_->adcReadSingle(canalEntradaVelocidad_ ) <<endl;
        cout << "PWM = "<<valor <<" Var leida Posicion " <<  conversorADC_->adcReadSingle(canalEntradaPosicion_ ) <<endl;
        cout << "PWM = "<<valor <<" Var leida Potenciometro " <<  conversorADC_->adcReadSingle(canalRefPotenciometro_) <<endl;
    }
}
