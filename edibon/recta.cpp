#include "recta.h"

Recta::Recta(double pendiente,double corteEjeY) : corteEjeY_(corteEjeY), pendiente_(pendiente) {}

void Recta::setPendiente(double x1, double y1, double x2, double y2) {
    pendiente_= (y2-y1)/(x2-x1);
}

void Recta::setPendiente(double pendiente){
    pendiente_ = pendiente ;
}

void Recta::setCorteEjeY(double corte){
    corteEjeY_ = corte;
}

double Recta::calcularY(double x){
    return (corteEjeY_ + pendiente_ * x);
}

double Recta::calcularX(double y){
    return (y -corteEjeY_)/pendiente_;
}
