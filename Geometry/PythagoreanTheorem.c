#include "Geo.h"
#include "spsqrt.h"

dbSqrt hyp(double a, double b) {
    return dbspsqrt(a*a + b*b);
}

dbSqrt leg(double a, double b) {
    if (a > b) return dbspsqrt(a*a - b*b);
    return dbspsqrt(b*b - a*a);
}