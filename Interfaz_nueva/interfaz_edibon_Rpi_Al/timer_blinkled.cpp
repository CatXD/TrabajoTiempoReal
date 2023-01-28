#include "timer_blinkled.h"
#include <QDebug>



void Timer_BlinkLED::Init ()
{
    // create a timer
    timer = new QTimer(this);
    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));


}

void Timer_BlinkLED::Blink_LED_start()
{
    // msec
    estado = true;
    timer->start(periodo);
    digitalWrite(LED, estado);
}

void Timer_BlinkLED::Blink_LED_stop()
{
    digitalWrite(LED, 0);
    timer->stop();
}


void Timer_BlinkLED::Blink_LED_exec()
{
    estado = !estado;
    digitalWrite(LED, estado);
}
