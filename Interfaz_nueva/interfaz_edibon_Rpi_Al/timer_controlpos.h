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



public slots:
    void timerSlot_pos();
    void start();
    void stop();
};




#endif // MYTIMER_H
