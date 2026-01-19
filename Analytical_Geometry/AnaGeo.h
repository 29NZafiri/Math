#ifndef MATH_POINT_H
#define MATH_POINT_H
#include "Frac.h"
#include "spsqrt.h"

typedef struct dblPoint {
    double x;
    double y;
} dbPnt;

typedef struct intPoint {
    int x;
    int y;
} intPnt;

typedef struct longPoint {
    long x;
    long y;
} lPnt;

typedef struct longlongPoint {
    long long x;
    long long y;
} llPnt;

typedef struct dblSystem{
    double x;
    double y;
    double c;
} dbSys; //Ax+By=C

dbSqrt lnLength(dbPnt a, dbPnt b);
dbPnt midLn(dbPnt a, dbPnt b);
irFrac dstPntLn(dbSys eq, dbPnt a);
dbSys pntsLn(dbPnt a, dbPnt b);
dbPnt rtPnt(dbPnt r, dbPnt a, double angle);
dbfrac slpLn(dbPnt a, dbPnt b);
dbSys slpPntLn(double m, dbPnt a);
void printPoint(dbPnt p);
#endif //MATH_POINT_H