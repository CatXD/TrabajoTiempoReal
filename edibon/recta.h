#ifndef RECTA_H
#define RECTA_H


class Recta
{
public:
    Recta( double pendiente,double corteEjeY=0);
    Recta( ) {}
    void setPendiente(double x1, double y1, double x2, double y2);
    void setPendiente(double pendiente);
    void setCorteEjeY(double corte);
    double calcularY(double x);
    double calcularX(double y);
private:
    double corteEjeY_;
    double pendiente_;
};

#endif // RECTA_H
