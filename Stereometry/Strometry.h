#ifndef MATH_STROMETRY_H
#define MATH_STROMETRY_H
#include "spsqrt.h"

double ltArea(double s, double l, double n);
double rectPrismVol(double l, double w, double h);
double rectPrismSA(double l, double w, double h);
dbSqrt rectPrismSD(double l, double w, double h);
double rghConeVol(double r, double h);
dbSqrt rghConeL(double r, double h);
dbSqrt rghConeH(double r, double l);
dbSqrt rghConeHLArea(double r, double h); //multiply by PI to find true answer
dbSqrt rghConeLLArea(double r, double l); //multiply by PI to find true answer
double rghCylVol(double r, double h);
double rghCylLat(double r, double h);
dbSqrt sqrPymdSlHe(double l, double s);
dbSqrt sqrPymdPyHe(double l, double s);
dbSqrt sqrPymdVol(double l, double s);
dbMSurd sqrPymdSA(double l, double s);

#endif //MATH_STROMETRY_H