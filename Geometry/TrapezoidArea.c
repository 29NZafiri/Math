#include "TrapezoidArea.h"
#include <stdio.h>

#include "sscanf.h"

void trpzdArea(void) {
    double a, b, h;
    printf("What is the first base:\n");
    ssscanf("%lf", &a);
    printf("What is the second base:\n");
    ssscanf("%lf", &b);
    printf("What is the height:\n");
    ssscanf("%lf", &h);
    printf("The area is: %.17g\n", (a + b) * h/2);
}
