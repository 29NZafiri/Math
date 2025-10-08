#include "USynthDiv.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>

#include "sscanf.h"

void usynthdiv(void) {
    int cnt; //Amount of terms in the polynomial
    printf("How many terms are in your polynomial (The degree of the polynomial+1)?\n");
    ssscanf("%d", &cnt);

    double* coefs = malloc(cnt * sizeof(double)); //List of terms in the polynomial
    if (!coefs) {
        printf("Memory could not be allocated.\n");
        return;
    }

    promptfunc(coefs, cnt);

    double b;
    double a;
    printf("What is the coefficient of the linear term? (?x-b)\n");
    scanf("%lf", &a);
    printf("What would you like to divide by? (ax-?)\n");
    scanf("%lf", &b);

    printf("f(x)/(%.17gx%+.17g) = \n", a, -b);

    double* sol = synthdiv(coefs, cnt, a, b);

    for (int i = 0; i < cnt-2; i++) {
        printf("%+.17gx^%d", sol[i], cnt - i - 2);
    }
    printf("%+.17g", sol[cnt-2]);

    if (sol[cnt-1] != 0) printf(" %+.17g/(%.17gx%+.17g)", sol[cnt - 1], a, -b);

    free(coefs);
    free(sol);
}
