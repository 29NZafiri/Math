#include "FunctionCalc.h"
#include <stdio.h>
#include <stdlib.h>

#include "func.h"
#include "sscanf.h"

void funcCalc(void) {
    int cnt; //Amount of terms in the polynomial
    printf("How many terms are in your polynomial (The degree of the polynomial+1)?\n");
    ssscanf("%d", &cnt);

    double* coefs = malloc(cnt * sizeof(double)); //List of terms in the polynomial
    if (!coefs) {
        printf("Memory could not be allocated.\n");
        return;
    }

    promptfunc(coefs, cnt);
    double x = 1;
    while (x != 0) {
        printf("What number would you like to try? When done, enter 0. \n");
        ssscanf("%lf", &x);
        double ans = f(coefs, cnt, x);
        printf("f(%.17g) = %.17g\n", x, ans);
    }
    free(coefs);
}
