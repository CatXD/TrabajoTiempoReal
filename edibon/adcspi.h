#ifndef ADCSPI_H
#define ADCSPI_H

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include "recta.h"

#define CHAN_CONFIG_SINGLE 8
#define CHAN_CONFIG_DIFF 0

class AdcSpi
{
public:
    AdcSpi(int mode=8);
    void setSingleEndded();
    void setDiffEndded();
    void setSpiChannel(int channel);
    int adcReadSingle(int ADCInputChannel);
    void setRectaConversor(Recta *ptrRecta);

private:
    int channelConfigMode;
    unsigned annalogChannel;
    uint8_t bufferCom[3];
    int spiChannel;
    Recta *ptrRectaConversor;
};

#endif // ADCSPI_H
