#include "Strometry.h"

double rghConeVol(double r, double h) {
    return r*r*h/3;
}

dbSqrt rghConeL(double r, double h) {
    return dbspsqrt(h*h+r*r);
}

dbSqrt rghConeH(double r, double l) {
    return dbspsqrt(l*l-r*r);
}

dbSqrt rghConeHLArea(double r, double h) { //multiply by PI to find true answer
    dbSqrt l = rghConeL(r, h);
    l.rat *= r;
    return l;
}

dbSqrt rghConeLLArea(double r, double l) { //multiply by PI to find true answer
    dbSqrt h = rghConeH(r, l);
    h.rat *= r;
    return h;
}