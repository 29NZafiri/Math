#include <stdio.h>
#include <stdlib.h>

#include "FloatMath.h"
#include "Frac.h"
#include "Num.h"
#include "sscanf.h"

double f(const double* coef, const int cnt, const double x) {
    double fx = coef[0];
    for (int i = 1; i < cnt; i++)
        fx = coef[i] + fx * x;
    return fx;
}

double intf(const int* coef, const int cnt, const double x) {
    double fx = coef[0];
    for (int i = 1; i < cnt; i++)
        fx = coef[i] + fx * x;
    return fx;
}

int* intPromptFunc(int* cnt) {
    printf("How many coefficients do you have (degree + 1)?\n");
    ssscanf("%d", cnt);
    while (*cnt < 1) {
        printf("%d is not a valid amount. How many coefficients do you have (degree + 1)?\n", *cnt);
        ssscanf("%d", cnt);
    }
    int* coefs = malloc(sizeof(int) * *cnt);
    for (int i = 0; i < *cnt; i++) {
        printf("Enter the coefficient of the x^%d\n", *cnt - i - 1);
        ssscanf("%d", &coefs[i]);
    }
    int xtraLead = 0;
    while (!coefs[xtraLead] && xtraLead < *cnt) xtraLead++;
    if (xtraLead == *cnt) {
        int* temp = realloc(coefs, sizeof(int));
        if (!temp) {
            fprintf(stderr, "Memory could not be allocated.\n");
            exit(-1);
        }
        coefs = temp;
        coefs[0] = 0;
        *cnt = 1;
    }
    else if (xtraLead) {
        int* temp = malloc(sizeof(int) * (*cnt-xtraLead));
        for (int i = 0; i < *cnt - xtraLead; i++) temp[i] = coefs[i+xtraLead];
        free(coefs);
        coefs = temp;
        *cnt = *cnt - xtraLead;
    }
    return coefs;
}

double* promptFunc(int* cnt) {
    printf("How many coefficients do you have (degree + 1)?\n");
    ssscanf("%d", cnt);
    while (*cnt < 1) {
        printf("%d is not a valid amount. How many coefficients do you have (degree + 1)?\n", *cnt);
        ssscanf("%d", cnt);
    }
    double* coefs = malloc(sizeof(double) * *cnt);
    for (int i = 0; i < *cnt; i++) {
        printf("Enter the coefficient of the x^%d\n", *cnt - i - 1);
        ssscanf("%lf", &coefs[i]);
    }
    int xtraLead = 0;
    while (!coefs[xtraLead] && xtraLead < *cnt) xtraLead++;
    if (xtraLead == *cnt) {
        double* temp = realloc(coefs, sizeof(double));
        if (!temp) {
            fprintf(stderr, "Memory could not be allocated.\n");
            exit(-1);
        }
        coefs = temp;
        coefs[0] = 0;
        *cnt = 1;
    }
    else if (xtraLead) {
        double* temp = malloc(sizeof(double) * (*cnt-xtraLead));
        for (int i = 0; i < *cnt - xtraLead; i++) temp[i] = coefs[i+xtraLead];
        free(coefs);
        coefs = temp;
        *cnt = *cnt - xtraLead;
    }
    return coefs;
}

double* synthdiv(const double* coefs, const int cnt, const double a, const double b) {
    double* sol = malloc(sizeof(double) * cnt);
    sol[0] = coefs[0];
    double dvsr = b / a;

    for (int i = 1; i < cnt; i++)
        sol[i] = coefs[i] + sol[i-1] * dvsr;

    for (int i = 0; i < cnt - 1; i++)
        sol[i] /= a;

    return sol;
}

llfrac* llFsynthDiv(const llfrac* coefs, const int cnt, const llfrac a) {
    llfrac* sol = malloc(sizeof(llfrac) * cnt);
    sol[0] = coefs[0];
    for (int i = 1; i < cnt; i++) {
        long long denom = llLCM(a.denom, coefs[i].denom);
        denom = llLCM(denom, sol[i-1].denom);
        long long N1 = denom * coefs[i].num;
        N1 /= coefs[i].denom;
        long long N2 = sol[i-1].num * a.num * denom;
        N2 /= sol[i-1].denom * a.denom;
        long long num = N1 + N2;
        llFracSmp(&num, &denom);
        sol[i] = (llfrac){num, denom};
    }
    return sol;
}

dbfrac sumFunc(const double* coefs) {
    double a = coefs[0];
    double b = coefs[1];
    int G = 1;
    if (DbInt(a) && DbInt(b)) G = GCF((int)a, (int)b);
    if (a < 0) G *= -1;
    return (dbfrac){-b/G, a/G};
}

int neg(int power) {
    if (power % 2) return 1;
    return -1;
}

dbfrac prodFunc(const double* coefs, const int cnt) {
    double a = coefs[0];
    double c = coefs[cnt-1];
    int G = 1;
    if (DbInt(a) && DbInt(c)) G = GCF((int)a, (int)c);
    if (a < 0) G *= -1;
    return (dbfrac){neg(cnt) * c /G, a/G};
}


frac intSumFunc(const int* coefs) {
    int a = coefs[0];
    int b = coefs[1];
    int G = GCF(a, b);
    if (a < 0) G *= -1;
    return (frac){b/G, a/G};
}

frac intProdFunc(const int* coefs, const int cnt) {
    int a = coefs[0];
    int c = coefs[cnt-1];
    int  G = GCF(a, c);
    if (a < 0) G *= -1;
    return (frac){neg(cnt-1) * c /G, a/G};
}