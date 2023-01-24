#include "regulador.h"

Regulador::Regulador(double KP, double KI, double KD, int T)
{
    this->KP=KP;
    this->KI=KI;
    this->KD=KD;
    this->T=T;
    pthread_mutex_init(&mutex,NULL);
}
void Regulador::set_KP(double KP){
    pthread_mutex_lock(&mutex);
    this->KP=KP;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_KP(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=KP;
    pthread_mutex_unlock(&mutex);
    return valor;
}
void Regulador::set_KI(double KI){
    pthread_mutex_lock(&mutex);
    this->KI=KI;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_KI(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=KI;
    pthread_mutex_unlock(&mutex);
    return valor;
}
void Regulador::set_KD(double KD){
    pthread_mutex_lock(&mutex);
    this->KD=KD;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_KD(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=KD;
    pthread_mutex_unlock(&mutex);
    return valor;
}
void Regulador::set_T(int T){
    pthread_mutex_lock(&mutex);
    this->T=T;
    pthread_mutex_unlock(&mutex);
}
int Regulador::get_T(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=T;
    pthread_mutex_unlock(&mutex);
    return valor;
}

void Regulador::set_ref(double ref){
    pthread_mutex_lock(&mutex);
    this->ref=ref;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_ref(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=ref;
    pthread_mutex_unlock(&mutex);
    return valor;
}
void Regulador::set_pos(double pos){
    pthread_mutex_lock(&mutex);
    this->pos=pos;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_pos(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=pos;
    pthread_mutex_unlock(&mutex);
    return valor;
}
void Regulador::set_vel(double vel){
    pthread_mutex_lock(&mutex);
    this->vel=vel;
    pthread_mutex_unlock(&mutex);
}
double Regulador::get_vel(void){
    double valor;
    pthread_mutex_lock(&mutex);
    valor=vel;
    pthread_mutex_unlock(&mutex);
    return valor;
}
