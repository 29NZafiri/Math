#include "Strometry.h"

dbSqrt sqrPymdSlHe(double l, double s) {
    return dbspsqrt(l*l-s*s/4);
}

dbSqrt sqrPymdPyHe(double l, double s) {
    double SlHe = l*l-s*s/4;
    return dbspsqrt(SlHe-s*s/4);
}

dbSqrt sqrPymdVol(double l, double s) {
    dbSqrt PyHe = sqrPymdPyHe(l, s);
    PyHe.rat *= s*s/3;
    return PyHe;
}

dbMSurd sqrPymdSA(double l, double s) {
    dbSqrt PyHe = sqrPymdPyHe(l, s);
    PyHe.rat *= s*2;
    return (dbMSurd){PyHe, s*s};
}