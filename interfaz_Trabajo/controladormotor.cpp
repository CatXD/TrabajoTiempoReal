#include "controladormotor.h"

ControladorMotor::ControladorMotor()
{
VELADC_TO_RPM.SetTramo1(TRAMO1_PEND, TRAMO1_CRUCEY);
VELADC_TO_RPM.SetTramo2 (CRUCE12, TRAMO2, CRUCE23);
VELADC_TO_RPM.SetTramo3(TRAMO3_PEND, TRAMO3_CRUCEY);
Init();
}

ControladorMotor::Init()
{
    flag_exterminate_h_reg_vel = false;
    flag_exterminate_h_reg_pos = false;

    // int sem_init(sem_t *sem, int pshared, unsigned int value)
    sem_init (&sem_cambio_pos2vel, 0, 1);
    sem_init (&sem_cambio_vel2pos, 0, 0);

    pthread_mutex_init(&mutex,NULL);
}

/// @brief Funcion de suma de timespec
/// @param t1 timespec1
/// @param t2 timespec2
void SM_trabajo::suma(timespec &t1, timespec &t2)
{
    t1.tv_nsec+=t2.tv_nsec; //primero sumo los nanosegundos
    t1.tv_sec+=t2.tv_sec;   //despues los segundos
    if(t1.tv_nsec>=1e9){    //y ajustamos los nanosegundos
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }
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



void ControladorMotor::BucleControl_Pos ()
{
    int y_medida, salida;

    sem_wait (&sem_cambio_vel2pos);

    struct timespec t1,t2;
    t1.tv_nsec=motor->reg_pos.get_T()*1e6;//para pasar a segundos
    if(t1.tv_nsec>=1e9){
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }
    clock_gettime(CLOCK_REALTIME,&t2); //capturamos el tiempo actual

    while ( !flag_exterminate_h_reg_pos )
    {
        //Leo entradas

        //Recta de calibracion

        //Ejecuto regulador
        salida = this->reg_pos.calculaAccionControl ( y_medida );

        //Efectuo accion de control
        
        


        suma(t2,t1); //sumo al tiempo actual el periodo del hilo
        clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&t2,NULL); //espero el tiempo determinado
    }

    flag_exterminate_h_reg_pos = false;

    sem_post (&sem_cambio_pos2vel);
}

void ControladorMotor::BucleControl_Vel ()
{
        int y_medida, salida;

    sem_wait (&sem_cambio_pos2vel);

    struct timespec t1,t2;
    t1.tv_nsec=motor->reg_vel.get_T()*1e6;//para pasar a segundos
    if(t1.tv_nsec>=1e9){
        t1.tv_sec++;
        t1.tv_nsec-=1e9;
    }
    clock_gettime(CLOCK_REALTIME,&t2); //capturamos el tiempo actual


    while ( !flag_exterminate_h_reg_vel )
    {
        //Leo entradas

        //Recta de calibracion

        //Ejecuto regulador
        salida = this->reg_vel.calculaAccionControl ( y_medida );

        //Efectuo accion de control
        
        


        suma(t2,t1); //sumo al tiempo actual el periodo del hilo
        clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&t2,NULL); //espero el tiempo determinado
    }

    flag_exterminate_h_reg_vel = false;

    sem_post (&sem_cambio_vel2pos);
}