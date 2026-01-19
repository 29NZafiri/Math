#include "FloatMath.h"
#include "Alg.h"
#include "Num.h"

rts quadRoots(const double* coefs) {
    double a = coefs[0];
    double b = coefs[1];
    double c = coefs[2];
    rts roots;
    roots.dis = b*b - 4*a*c; //discriminant of the quadratic formula
    roots.real = -b;
    roots.denom = 2*a;
    roots.cmplx = 0;
    if (roots.dis < 0) roots.cmplx = 1;
    return roots;
}

dbfrac yVertexQuad(const double* coefs) {
    double a = coefs[0];
    double b = coefs[1];
    double c = coefs[2];
    double num = 4*a*c-b*b;
    int YFracCmd = 1;
    if (DbInt(a) && DbInt(b) && DbInt(c)) YFracCmd = GCF((int)(4*a*c-b*b), 4*(int)a); //Simplify the fraction via GCF
    if (a < 0) YFracCmd *= -1;
    return (dbfrac){num/YFracCmd, 4*a/YFracCmd};
}

dbfrac xVertexQuad(const double* coefs) {
    double a = coefs[0];
    double b = coefs[1];
    int XFracCmd = 1;
    if (DbInt(a) && DbInt(b)) XFracCmd = GCF((int)b, 2*(int)a); //Simplify the fraction via GCF
    if (a < 0) XFracCmd *= -1;
    return (dbfrac){-b/XFracCmd, 2*a/XFracCmd};
}

