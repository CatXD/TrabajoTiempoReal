#include "controladormotor.h"


void ControladorMotor::Init ()
{

    timer_pos.Init(&reg_pos);
    timer_vel.Init(&reg_vel);
    timer_blinked.Init();
}
