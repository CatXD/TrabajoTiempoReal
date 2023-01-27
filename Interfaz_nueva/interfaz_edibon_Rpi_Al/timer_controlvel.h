
#ifndef TIMER_CONTROLVEL
#define TIMER_CONTROLVEL

#include "regulador.h"
#include <QTimer>

class Timer_ControlVel : public QObject
{
    Q_OBJECT

protected:
    int periodo;
    Regulador * regulador;

public:

    void Init(Regulador * reg);
    QTimer *timer;


    int T_actual;

    void start();
    void stop();

public slots:
    void MyTimerSlot();
};

#endif // MYTIMER_H
