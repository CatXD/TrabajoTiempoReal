#ifndef RECTA3TROZOS_H
#define RECTA3TROZOS_H
#include "recta.h"

class Recta3Trozos
{
protected:
    Recta Tramo1;
    double Cruce12;
    double Tramo2;
    double Cruce23;
    Recta Tramo3;

public:
    Recta3Trozos();
    Recta3Trozos(Recta tramo1, double cruce12, double tramo2, double cruce23, Recta tramo3);
    Recta3Trozos(double tramo1_crucey, double tramo1_pend, double cruce12, double tramo2, double cruce23, double tramo3_crucey, double tramo3_pend);

    void SetTramo1 (Recta tramo1);
    void SetTramo1 (double pend, double crucey);
    void SetTramo2 ( double cruce12, double tramo2, double cruce23);
    void SetTramo3 (Recta tramo3);
    void SetTramo3 (double pend, double crucey);

    double GetValue (double x);

    int getMonotonia (); //{DECRECIENTE = -1, NULA = 0, CRECIENTE = 1};

    double GetInversa(double y); //No se comprueba si es concava/convexa


};

#endif // RECTA3TROZOS_H
