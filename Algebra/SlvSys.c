#include "SlvSys.h"

#include <stdio.h>

void syseq(void) {
    printf("Equations should be in the form X+Y=C\n");
    double a, b, c, d, e, f;
    printf("Enter the coefficient of the first X.\n");
    scanf("%lf", &a);
    printf("Enter the coefficient of the first Y.\n");
    scanf("%lf", &b);
    printf("Enter the first constant.\n");
    scanf("%lf", &c);
    printf("Enter the coefficient of the second X.\n");
    scanf("%lf", &d);
    printf("Enter the coefficient of the second Y.\n");
    scanf("%lf", &e);
    printf("Enter the coefficient of the second constant.\n");\
    scanf("%lf", &f);
    double Y = (f*a-c*d)/(a*e-b*d);
    double X = (c-b*Y)/a;
    printf("The solution to the equation is (%.17g,%.17g)\n", X, Y);
}
