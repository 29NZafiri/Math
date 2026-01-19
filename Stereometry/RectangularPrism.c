#include "Strometry.h"

double rectPrismVol(double l, double w, double h) {
    return l*w*h;
}

double rectPrismSA(double l, double w, double h) {
    return 2*(l*w+w*h+l*h);
}

dbSqrt rectPrismSD(double l, double w, double h) {
    double SD = l*l+w*w+h*h;
    return dbspsqrt(SD);
}