#include "Midpoint.h"
#include <stdio.h>

#include "sscanf.h"

void midLn(void) {
    double x1, y1, x2, y2;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &x1);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &y1);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &x2);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &y2);
    double x = (x1 + x2) / 2;
    double y = (y1 + y2) / 2;
    printf("The coordinates of the midpoint are (%.17g,%.17g). \n", x, y);
}
