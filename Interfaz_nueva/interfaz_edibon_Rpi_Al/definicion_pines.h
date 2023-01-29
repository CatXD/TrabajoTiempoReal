#ifndef DEFINICION_PINES_H
#define DEFINICION_PINES_H

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <string.h>


#define PWM 13 //23
#define PARAR 17 //0
#define REANUDAR 27 //2
#define LED 22 //3

#define CHAN_CONFIG_SINGLE   8   //setup channel 0 as Single-ended input
#define SPICHANNEL           0   //MCP3008 connect to SPI0
#define ANALCHANNEL_REF      0
#define ANALCHANNEL_POT      1
#define ANALCHANNEL_VEL      2




static int myAnalogRead(int spiChannel,int channelConfig,int analogChannel)
{
    if(analogChannel<0 || analogChannel>7)
        return -1;
    unsigned char buffer[3] = {1}; // start bit
    buffer[1] = (channelConfig+analogChannel) << 4;
    wiringPiSPIDataRW(spiChannel, buffer, 3);
    return ( (buffer[1] & 3 ) << 8 ) + buffer[2]; // get last 10 bits
}




#endif // DEFINICION_PINES_H
