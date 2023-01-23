#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>


#define PWM 23 //GPIO13
#define LED 3 //gpio22
#define PARAR 0 //17
#define REANUDAR 2//gpio27

#define CHAN_CONFIG_SINGLE  8   //setup channel 0 as Single-ended input
#define SPICHANNEL          0   //MCP3008 connect to SPI0
#define ANALCHANNEL0_REF      0
#define ANALCHANNEL1_POT      1
#define ANALCHANNEL2_VEL      2
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

int max = 0;
int adc0,adc1,adc2;
wiringPiSetup();
spiSetup(SPICHANNEL);
pinMode(PWM,PWM_OUTPUT);

pwmWrite(PWM,1023);
delay(1000);
for(;;)
{
adc0 =myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL0_REF);

printf("ADC 0= %d\n",adc0);
pwmWrite(PWM,adc0);

adc1 =myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL1_POT);
if (adc1 > max)
{
    max = adc1;
}
printf("ADC 1= %d, max: %d\n",adc1,max);


adc2 =myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALCHANNEL2_VEL);
printf("ADC 2= %d\n\n",adc2);


delay(100);
}
return 0;
}


//int main()
//{
//    int adc;
//    float voltage;
//    char buf[5];
//    if(wiringPiSetup() < 0)
//    {   fprintf(stderr,"Can't init wiringPi: %s\n",strerror(errno));
//        exit(EXIT_FAILURE);
//    }

//    spiSetup(SPICHANNEL);//init spi

//    i2cfd = wiringPiI2CSetup(LCDADDR);//init i2c
//    init();//init LCD
//    clear();//clear screen

//    print_info();

//    while(1)
//    {
//        adc = myAnalogRead(SPICHANNEL,CHAN_CONFIG_SINGLE,ANALOGCHANNEL);
//        voltage = adc/1024.*3.3;
//        write(0,0,"Voltage:");
//        sprintf(buf,"%1.2f",voltage);//float change to string
//        write(8,0,buf);//print voltage on lcd
//        write(12,0,"V");//print unit

//        write(8,1,"--OSOYOO");
//        delay(1000);
//    }
//    return 0;
//}
