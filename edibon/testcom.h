#ifndef FUNCIONESTEST_H
#define FUNCIONESTEST_H
#include "adcspi.h"

class TestCom
{
public:
    TestCom(int chVel, int chPos, int chPoten, int pinPWM);
    void correspondenciaPWMTensionVelocidad();
    void setConversor(AdcSpi *conversor, Recta *recta);
    void setSensor( Recta *recta);
    void interactivePWM();

private:

    int canalEntradaVelocidad_;
    int canalEntradaPosicion_;

    int canalRefPotenciometro_;
    int pinPWM_;
    AdcSpi *conversorADC_;
    Recta *rectaConversor_;
    Recta *rectaSensor_;
};

#endif // FUNCIONESTEST_H
