#ifndef TIMER_CONTROLPOS
#define TIMER_CONTROLPOS
#include "regulador.h"

#include <QTimer>

class Timer_ControlPos : public QObject
{
    Q_OBJECT

protected:
    int periodo;
    Regulador * regulador;

public:
    //Timer_ControlPos();
    void Init (Regulador * reg);

    QTimer *timer;


    int T_actual;

    void start();
    void stop();

public slots:
    void timerSlot_pos();
};




#endif // MYTIMER_H
