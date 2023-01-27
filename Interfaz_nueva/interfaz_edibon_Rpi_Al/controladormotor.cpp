#include "controladormotor.h"


void ControladorMotor::Init ()
{
    VELADC_TO_RPM.SetTramo1(TRAMO1_PEND, TRAMO1_CRUCEY);
    VELADC_TO_RPM.SetTramo2 (CRUCE12, TRAMO2, CRUCE23);
    VELADC_TO_RPM.SetTramo3(TRAMO3_PEND, TRAMO3_CRUCEY);
}
