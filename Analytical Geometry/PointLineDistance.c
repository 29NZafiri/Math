#include "PointLineDistance.h"

#include <math.h>
#include <stdio.h>

#include "FloatMath.h"
#include "sscanf.h"

void dstPntLn(void) {
    double A, B, C, x, y;
    printf("The line should be in the equation Ax+By+C=0\n");
    printf("Please enter A\n");
    ssscanf("%lf", &A);
    printf("Please enter B\n");
    ssscanf("%lf", &B);
    printf("Please enter C\n");
    ssscanf("%lf", &C);
    printf("Please enter the X coordinate\n");
    ssscanf("%lf", &x);
    printf("Please enter the Y coordinate\n");
    ssscanf("%lf", &y);
    double num = DbAbs(A*x+B*y+C);
    double denom = sqrt(A*A+B*B);
    printf("The distance is %.17g\n", num/denom);
    printf("In fractional form, %.17g/%.17g", num, denom);
}
