#include "SlopePointLine.h"

#include <stdio.h>

#include "sscanf.h"

void slpPntLn(void) {
    double m, x1, y1;
    printf("Please enter the slope.\n");
    ssscanf("%lf", &m);
    printf("Please enter the x coordinate.\n");
    ssscanf("%lf", &x1);
    printf("Please enter the y coordinate.\n");
    ssscanf("%lf", &y1);
    double b = y1 - m*x1;
    printf("The equation for this line is: y = %.17gx %+.17g\n", m, b);
    printf("In Standard Form: %.17g x + y = %.17g\n", -m, b);
}
