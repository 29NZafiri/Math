#ifndef MATH_FRAC_H
#define MATH_FRAC_H
#include "spsqrt.h"

typedef struct Frac {
    int num;
    int denom;
} frac;

typedef struct llFrac {
    long long num;
    long long denom;
} llfrac;

typedef struct dblFrac {
    double num;
    double denom;
} dbfrac;

typedef struct sqrtFrac {
    dbSqrt num;
    double denom;
} irFrac;

int fracSmp(int* num, int* denom);
long long llFracSmp(long long* num, long long* denom);
int dbFracSmp(double* num, double* denom);

#endif //MATH_FRAC_H