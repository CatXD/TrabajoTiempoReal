#ifndef PLACAFISICA_H
#define PLACAFISICA_H

#include <QObject>

class PlacaFisica
{
    Q_OBJECT
public:
    PlacaFisica();
signals:
    void PARAR_signal(void);
    void REANUDAR_signal(void);
};

#endif // PLACAFISICA_H
