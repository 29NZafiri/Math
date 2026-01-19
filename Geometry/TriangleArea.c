#include "Geo.h"
#include "spsqrt.h"

dbSqrt triArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double val = s * (s - a) * (s - b) * (s - c);
    dbSqrt area = dbspsqrt(val);
    return area;
}
