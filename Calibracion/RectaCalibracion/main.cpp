#include <stdio.h>
#include <stdlib.h>
#include <recta3trozos.h>
int main ()
{
    Recta rec1 (-10, 2);
    Recta rec2 (10,2);
    Recta3Trozos recta(rec1,
                       -10.0, 0.0, 10.0,
                       rec2 );
}
