#ifndef TIMER_CONTROLPOS
#define TIMER_CONTROLPOS
#include "regulador.h"
#include "definicion_pines.h"
#include "recta.h"
#include <QTimer>
#include "valores_iniciales.h"
#include "recta3trozos.h"

class Timer_ControlPos : public QObject
{
    Q_OBJECT

protected:
    int periodo;
    Regulador * regulador;
    Regulador * regulador_vel;
    Recta Ref_To_Grados{PEND_REFTOGRADOS,ORD_ORIGEN_REFTOGRADOS};
    int contador = 0;
    Recta3Trozos VELADC_TO_RPM   ;

public:
    //Timer_ControlPos();
    void Init (Regulador * reg, Regulador * vel);
    QTimer *timer;
    int T_actual;

public slots:
    void timerSlot_pos();
    void start();
    void stop();
};




#endif // MYTIMER_H
