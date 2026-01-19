#ifndef MATH_ALG_H
#define MATH_ALG_H
#include "Frac.h"
#include "AnaGeo.h"

double f(double* coef, int cnt, double x);
double intf(int* coef, int cnt, double x);
dbfrac sumFunc(const double* coefs);
frac intSumFunc(const int* coefs);
dbfrac prodFunc(const double* coefs, int cnt);
frac intProdFunc(const int* coefs, int cnt);

double* promptFunc(int* cnt);
int* intPromptFunc(int* cnt);

double* synthdiv(double* coefs, int cnt, double a, double b);
llfrac* llFsynthDiv(const llfrac* coefs, int cnt, llfrac a);
void printFctrsPoly(const int* coefs, const llfrac* zeros, int cnt, int zcnt);

typedef struct dbcmp {
    double real;
    double imag;
} dbComplex;
dbComplex addComplex(dbComplex a, dbComplex b);
dbComplex minusComplex(dbComplex a, dbComplex b);
dbComplex multComplex(dbComplex a, dbComplex b);
dbComplex divComplex(dbComplex a, dbComplex b);
double absComplex(dbComplex a);
dbComplex sqrtComplex(dbComplex a);
dbComplex sqrComplex(dbComplex a);
_Bool equalComplex(dbComplex a, dbComplex b);
_Bool ComplexInt(dbComplex a);
void printComplex(dbComplex a);

llfrac* plyfct(int* coefs, int cnt, int* zeroCnt);

typedef struct {
    _Bool cmplx;
    double real;
    double dis;
    double denom;
} rts;
rts quadRoots(const double* coefs);
dbfrac yVertexQuad(const double* coefs);
dbfrac xVertexQuad(const double* coefs);

dbPnt syseq(dbSys sys1, dbSys sys2);

#endif //MATH_ALG_H
