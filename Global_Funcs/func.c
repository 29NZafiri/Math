#include "func.h"

#include <stdio.h>
#include <stdlib.h>

double f(const double* coef, const int cnt, const double x) {
    double fx = coef[0];
    for (int i = 1; i < cnt; i++) {
        fx = coef[i] + fx * x;
    }
    return fx;
}

double intf(const int* coef, const int cnt, const double x) {
    double fx = coef[0];
    for (int i = 1; i < cnt; i++) {
        fx = coef[i] + fx * x;
    }
    return fx;
}

void promptfunc(double* coefs, const int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("Enter the coefficient of the x^%d\n", cnt - i - 1);
        scanf("%lf", &coefs[i]);
    }
}

double* synthdiv(const double* coefs, const int cnt, const double a, const double b) {
    double* sol = malloc(sizeof(double) * cnt);
    sol[0] = coefs[0];
    double dvsr = b / a;
    for (int i = 1; i < cnt; i++) {
        sol[i] = coefs[i] + sol[i-1] * dvsr;
    }
    for (int i = 0; i < cnt - 1; i++) {
        sol[i] /= a;
    }
    return sol;
}