#ifndef TIMER_CONTROLVEL
#define TIMER_CONTROLVEL

#include "definicion_pines.h"
#include "regulador.h"
#include <QTimer>
#include "recta3trozos.h"
#include "valores_iniciales.h"

class Timer_ControlVel : public QObject
{
    Q_OBJECT

protected:
    int periodo;
    Regulador * regulador;
    Recta3Trozos VELADC_TO_RPM   ;

public:

    void Init(Regulador * reg);
    QTimer *timer;
    int T_actual;

public slots:
    void timerSlot_vel();
    void start();
    void stop();
};

#endif // MYTIMER_H
