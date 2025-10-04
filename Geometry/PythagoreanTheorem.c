#include "PythagoreanTheorem.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "spsqrt.h"

void pyththrm(void) {
    int solve;
    double ans = 0;
    printf("Are you looking for the leg(1) or the hypotenuse(2)\n");
    scanf("%d", &solve);
    if (solve == 1) {
        ans = pythL();
        printf("The missing leg is %.17g\n", sqrt(ans));
    }
    if (solve == 2) {
        ans = pythH();
        printf("The hypotenuse is %.17g\n", sqrt(ans));
    }
    if (solve == 1 || solve == 2) {
        if (sqrt(ans) != (int)sqrt(ans)) {
            char* sqrtans = dbspsqrt(ans);
            printf("As a radical, it's %s\n", sqrtans);
            free(sqrtans);
        }
    }
}

double pythL(void) {
    double h, l;
    printf("What is the hypotenuse?\n");
    scanf("%lf", &h);
    printf("What is the leg?\n");
    scanf("%lf", &l);
    double ans = h*h - l*l;
    return ans;
}

double pythH(void) {
    double a, b;
    printf("What is the first leg?\n");
    scanf("%lf", &a);
    printf("What is the second leg?\n");
    scanf("%lf", &b);
    double ans = a*a + b*b;
    return ans;
}
