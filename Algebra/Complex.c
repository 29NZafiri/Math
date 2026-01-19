#include <math.h>
#include <stdio.h>

#include "FloatMath.h"
#include "Alg.h"

dbComplex addComplex(dbComplex a, dbComplex b) {
    dbComplex result = {a.real + b.real, a.imag + b.imag};
    return result;
}

dbComplex minusComplex(dbComplex a, dbComplex b) {
    dbComplex result = {a.real - b.real, a.imag - b.imag};
    return result;
}

dbComplex multComplex(dbComplex a, dbComplex b) {
    dbComplex result = {a.real * b.real - a.imag * b.imag, a.real * b.imag + b.imag * a.real};
    return result;
}

dbComplex divComplex(dbComplex a, dbComplex b) {
    double aN = a.real * b.real + a.imag * b.imag;
    double bN = -a.real * b.imag + b.real * a.imag;
    double d = b.real*b.real + b.imag*b.imag;
    dbComplex result = {aN / d, bN / d};
    return result;
}

double absComplex(dbComplex a) {
    return sqrt(a.real*a.real + a.imag*a.imag);
}

dbComplex sqrtComplex(dbComplex a) { //returns such that real part is positive
    dbComplex result;
    if (a.real == 0 && a.imag == 0) {
        result.real = 0;
        result.imag = 0;
    }
    else if (a.imag == 0 && a.real < 0) {
        result.real = 0;
        result.imag = sqrt(-a.real);
    }
    else {
        result.real = sqrt((a.real+absComplex(a))/2);
        result.imag = a.imag/(2*result.real);
    }
    return result;
}

dbComplex sqrComplex(dbComplex a) {
    dbComplex result = {a.real*a.real-a.imag*a.imag, 2*a.real*a.imag};
    return result;
}

_Bool equalComplex(dbComplex a, dbComplex b) {
    if (DbEq(a.real, b.real) && DbEq(a.imag, b.imag)) return 1;
    return 0;
}

_Bool ComplexInt(dbComplex a) {
    return DbInt(a.real) && DbInt(a.imag);
}

void printComplex(dbComplex a) {
    printf("%.15g%+.15gi", a.real, a.imag);
}