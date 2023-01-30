#include <iostream>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>

using namespace std;

#define PWM 23 //13 //
#define PARAR 0 //17
#define REANUDAR 2 //27 //
#define LED 3 //22 //

#define CHAN_CONFIG_SINGLE   8   //setup channel 0 as Single-ended input
#define SPICHANNEL           0   //MCP3008 connect to SPI0
#define ANALCHANNEL_REF      0
#define ANALCHANNEL_POT      1
#define ANALCHANNEL_VEL      2

static int spifd ;

void spiSetup (int spiChannel)
{
    if ((spifd = wiringPiSPISetup (spiChannel, 10000)) < 0)
    {
        fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }
}


int myAnalogRead(int spiChannel,int channelConfig,int analogChannel)
{
    if(analogChannel<0 || analogChannel>7)
        return -1;
    unsigned char buffer[3] = {1}; // start bit
    buffer[1] = (channelConfig+analogChannel) << 4;
    wiringPiSPIDataRW(spiChannel, buffer, 3);
    return ( (buffer[1] & 3 ) << 8 ) + buffer[2]; // get last 10 bits
}

int main()
{
    int pwm;
    int vel;
    string rpm;
   int led_estado = 1;
    wiringPiSetup();
    spiSetup(SPICHANNEL);
    pinMode(PWM,PWM_OUTPUT);
    pinMode (LED, OUTPUT);
    pwmWrite(PWM,0);
    digitalWrite(LED, led_estado);
    cout << "PWM, VEL_AN, LCD_RPM"<<endl;

    pwm = 1023;
    pwmWrite(PWM,pwm);
    cout << pwm<< ", ";
    delay (3000);
    vel = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);
    cout << vel <<",";
    cin >> rpm;

    for (pwm = 1000; pwm >= 0; pwm -= 25)
    {
        pwmWrite(PWM,pwm);
        cout << pwm<< ", ";
        delay (3000);
        vel = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);

        cout << vel <<",";

        cin >> rpm;

        led_estado = !led_estado;
        digitalWrite(LED, led_estado);
    }




    cout << "FIN"<<endl;
    cin>>rpm;

    return 0;
}

int main1()
{
    int pwm;
    int vel;
    string rpm;
   int led_estado = 1;
    wiringPiSetupGpio();
    spiSetup(SPICHANNEL);
    pinMode(PWM,PWM_OUTPUT);
    pinMode (LED, OUTPUT);
    pwmWrite(PWM,0);
    digitalWrite(LED, led_estado);
    cout << "PWM, VEL_AN, LCD_RPM"<<endl;

    for (pwm = 0; pwm < 1024; pwm += 25)
    {
        pwmWrite(PWM,pwm);
        cout << pwm<< ", ";
        delay (3000);
        vel = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);

        cout << vel <<",";

        cin >> rpm;

        led_estado = !led_estado;
        digitalWrite(LED, led_estado);
    }

    pwm = 1023;
    pwmWrite(PWM,pwm);
    cout << pwm<< ", ";
    delay (3000);
    vel = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL_VEL);
    cout << vel <<",";

    cin >> rpm;
    cout << "FIN"<<endl;
    cin>>rpm;

    return 0;
}
