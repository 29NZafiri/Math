#include "Geo.h"
#include "spsqrt.h"

irFrac incenter(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double dval = s * (s - a) * (s - b) * (s - c);
    dbSqrt val = dbspsqrt(dval);
    return (irFrac){val, s};
}
