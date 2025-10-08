#include "SlvSys.h"

#include <stdio.h>

#include "sscanf.h"

void syseq(void) {
    printf("Equations should be in the form X+Y=C\n");
    double a, b, c, d, e, f;
    printf("Enter the coefficient of the first X.\n");
    ssscanf("%lf", &a);
    printf("Enter the coefficient of the first Y.\n");
    ssscanf("%lf", &b);
    printf("Enter the first constant.\n");
    ssscanf("%lf", &c);
    printf("Enter the coefficient of the second X.\n");
    ssscanf("%lf", &d);
    printf("Enter the coefficient of the second Y.\n");
    ssscanf("%lf", &e);
    printf("Enter the coefficient of the second constant.\n");\
    ssscanf("%lf", &f);
    double Y = (f*a-c*d)/(a*e-b*d);
    double X = (c-b*Y)/a;
    printf("The solution to the equation is (%.17g,%.17g)\n", X, Y);
}
