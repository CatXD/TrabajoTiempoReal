#include "controladormotor.h"


void ControladorMotor::Init ()
{

    timer_pos.Init(&reg_pos, &reg_vel);
    timer_vel.Init(&reg_vel);
    timer_blinked.Init();
}
