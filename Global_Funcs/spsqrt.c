#include "spsqrt.h"

#include <math.h>
#include <stdio.h>

#include "FloatMath.h"

sqRoot spsqrt(int x) {
    int i = 2;
    int rat = 0;
    int irr = 0;
    while (i*i <= x) {
        if (x % (i*i) == 0) {
            irr = x / (i*i);
            rat = i;
        }
        i++;
    }
    if (rat * rat == x) return (sqRoot){rat, -1, 0};
    if (rat != 0) return (sqRoot){rat, irr, 1};
    if (x == 1 || x == 0) return (sqRoot){x, -1, 0};
    return (sqRoot){-1, x, 1};
}

dbSqrt dbspsqrt(double x) {
    if (!DbInt(x)) {
        return (dbSqrt){-1, x, 1};
    }
    sqRoot ret = spsqrt((int)x);
    return (dbSqrt){(double)ret.rat, (double)ret.irr, ret.rad};
}

_Bool dbSqrtZero(dbSqrt rt) {
    if (DbZero(rt.irr) || DbZero(rt.rat)) return 1;
    return 0;
}

double compSprt(sqRoot a) {
    if (a.rad) return  (double)abs(a.rat)*sqrt(a.irr);
    return a.rat;
}

double dbCompSprt(dbSqrt a) {
    if (a.rad) return  DbAbs(a.rat)*sqrt(a.irr);
    return DbAbs(a.rat);
}

double dbCompMSurd(dbMSurd a) {
    return a.rational + dbCompSprt(a.surd);
}

void printSqrt(sqRoot rt) {
    if (rt.rat == -1) printf("%s%d", rt.rad ? "√" : "", rt.irr);
    else if (rt.irr == -1) printf("%d", rt.rat);
    else printf("%d%s%d", rt.rat, rt.rad ? "√" : "", rt.irr);
}

void printDbSqrt(dbSqrt rt) {
    if (rt.rat == -1) printf("%s%.15g", rt.rad ? "√" : "", rt.irr);
    else if (rt.irr == -1) printf("%.15g", rt.rat);
    else printf("%.15g%s%.15g", rt.rat, rt.rad ? "√" : "", rt.irr);
}

void printDbMSurd(dbMSurd surd) {
    if (DbZero(surd.rational)) printDbSqrt(surd.surd);
    else if (dbSqrtZero(surd.surd)) printf("%.15g", surd.rational);
    else if (surd.surd.irr == -1) printf("%.15g", surd.rational+surd.surd.rat);
    else {
        printDbSqrt(surd.surd);
        printf("%+.15g", surd.rational);
    }
}
