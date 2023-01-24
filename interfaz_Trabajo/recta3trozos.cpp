#include "recta3trozos.h"


Recta3Trozos::Recta3Trozos(Recta tramo1, double cruce12, double tramo2, double cruce23, Recta tramo3)
{
    Recta3Trozos::Tramo1 = tramo1;
    Recta3Trozos::Tramo2 = tramo2;
    Recta3Trozos::Tramo3 = tramo3;
    Recta3Trozos::Cruce12 = cruce12;
    Recta3Trozos::Cruce23= cruce23;
}

Recta3Trozos::Recta3Trozos(double tramo1_crucey, double tramo1_pend, double cruce12, double tramo2, double cruce23, double tramo3_crucey, double tramo3_pend)
{
    Recta3Trozos::Tramo1.setPendiente(tramo1_pend);
    Recta3Trozos::Tramo1.setCorteEjeY(tramo1_crucey);

    Recta3Trozos::Cruce12 = cruce12;

    Recta3Trozos::Tramo2 = tramo2;

    Recta3Trozos::Cruce23= cruce23;

    Recta3Trozos::Tramo3.setPendiente(tramo3_pend);
    Recta3Trozos::Tramo1.setCorteEjeY(tramo3_crucey);
}

double Recta3Trozos::GetValue (double x)
{
    if (x < Cruce12)
        return Tramo1.calcularY(x);
    else if (x < Cruce23)
        return Tramo2;
    else
        return Tramo3.calcularY(x);
}

int Recta3Trozos::getMonotonia ()
{
    if ( Tramo1.getPendiente() >= 0 && Tramo3.getPendiente() >= 0)
        return 1;
    if ( Tramo1.getPendiente() < 0 && Tramo3.getPendiente() < 0)
        return -1;
    return 0;
}

double Recta3Trozos::GetInversa(double y)
{
    if (getMonotonia() == -1)
    {
        if (y <= Tramo2)
            return Tramo3.calcularX(y);
        else
            return Tramo1.calcularX(y);
    }

    else //sino lo doy como monotonamente creciente
    //if (getMonotonia() == 1)
    {
        if (y <= Tramo2)
            return Tramo1.calcularX(y);
        else
            return Tramo3.calcularX(y);
    }
}
