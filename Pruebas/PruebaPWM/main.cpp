/********************************************************************************************
*Filename      : breathing_led.c
*Description   : make LED breath.
*Author        : alan
*Website       : www.osoyoo.com
*Update        : 2017/06/26
********************************************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

//pin 1(BCM GPIO 18) is PWM  port
#define  LEDPIN   23


int main(){
    if(wiringPiSetup()==-1){
        printf("setup wiringPi failed!\n");
        printf("please check your setup\n");
        exit(1);
    }

    pinMode(LEDPIN,PWM_OUTPUT);

    pwmWrite(LEDPIN,512);
    delay(2000);
    for(int paso = 0;paso <1024; paso+=8){
            pwmWrite(LEDPIN,paso);

            delay(2000);

            //printf("%d, \n")
            }
    return 0;
 }
