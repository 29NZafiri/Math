#include "Test.h"

#include <math.h>
#include <stdio.h>

void test(void) {
    printf("Test\n");
    double x;
    while (x != 0) {
        scanf("%lf", &x);
        double y = 2*sqrt(x*x-9)/3;
        printf("Y = %.17g\n", y);
    }
}