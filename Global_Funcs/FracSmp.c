#include "FloatMath.h"
#include "Frac.h"
#include "Num.h"

int fracSmp(int* num, int* denom) {
    int G = GCF(*num, *denom);
    if (*denom < 0) G *= -1;
    *num /= G;
    *denom /= G;
    return G;
}

long long llFracSmp(long long* num, long long* denom) {
    long long G = llGCF(*num, *denom);
    if (*denom < 0) G *= -1;
    *num /= G;
    *denom /= G;
    return G;
}

int dbFracSmp(double* num, double* denom) {
    if (DbInt(*num) && DbInt(*denom)) {
        int G = GCF((int)*num, (int)*denom);
        if (*denom < 0) G *= -1;
        *num /= G;
        *denom /= G;
        return G;
    }
    return 1;
}