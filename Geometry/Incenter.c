#include "Incenter.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "spsqrt.h"

void incenter(void) {
    double a, b, c;
    printf("Please enter the first side of the triangle:\n");
    scanf("%lf", &a);
    printf("Please enter the second side of the triangle:\n");
    scanf("%lf", &b);
    printf("Please enter the third side of the triangle:\n");
    scanf("%lf", &c);
    double s = (a + b + c) / 2;
    double val = s * (s - a) * (s - b) * (s - c);
    double radius = sqrt(val)/s;
    printf("The radius of the triangle's incenter is %.17g\n", radius);
    char* rt = dbspsqrt(val);
    printf("As a radical, %s/%d\n", rt, (int)s);
    free(rt);
}
