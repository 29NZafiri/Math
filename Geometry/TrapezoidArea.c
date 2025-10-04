#include "TrapezoidArea.h"
#include <stdio.h>

void trpzdArea(void) {
    double a, b, h;
    printf("What is the first base:\n");
    scanf("%lf", &a);
    printf("What is the second base:\n");
    scanf("%lf", &b);
    printf("What is the height:\n");
    scanf("%lf", &h);
    printf("The area is: %.17g\n", (a + b) * h/2);
}
