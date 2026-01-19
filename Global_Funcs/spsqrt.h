#ifndef SPSQRT_H
#define SPSQRT_H

typedef struct sqrot{
    int rat;
    int irr;
    _Bool rad;
} sqRoot;

typedef struct dbSqrot{
    double rat;
    double irr;
    _Bool rad;
} dbSqrt;

typedef struct msrdi {
    sqRoot surd;
    int rational;
} mSurd;

typedef struct dbmsrd {
    dbSqrt surd;
    double rational;
} dbMSurd;

sqRoot spsqrt(int x);
dbSqrt dbspsqrt(double x);
double compSprt(sqRoot a);
double dbCompSprt(dbSqrt a);
double dbCompMSurd(dbMSurd a);
void printSqrt(sqRoot sq);
void printDbSqrt(dbSqrt rt);
void printDbMSurd(dbMSurd surd);

#endif //SPSQRT_H
