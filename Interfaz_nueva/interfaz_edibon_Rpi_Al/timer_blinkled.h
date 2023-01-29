#ifndef TIMER_BLINKLED
#define TIMER_BLINKLED
#include "definicion_pines.h"
#include <QTimer>

class Timer_BlinkLED : public QObject
{
    Q_OBJECT

protected:
    int periodo = 500;
    bool estado = false;
    int cont = 2;
public:
    void Init();
    QTimer *timer;

public slots:
    void Blink_LED_start();
    void Blink_LED_stop();
    void Blink_LED_exec();
};

#endif // MYTIMER_H
