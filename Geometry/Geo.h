#ifndef MATH_GEO_H
#define MATH_GEO_H
#include "Frac.h"

irFrac incenter(double a, double b, double c);
int plgangle(int n);
double pPolyArea(double perimeter, int n);
double aPolyArea(double apothem, int n);
char* pythInequal(double a, double b, double c);
dbSqrt hyp(double a, double b);
dbSqrt leg(double a, double b);
double trpzdArea(double a, double b, double h);
dbSqrt triArea(double a, double b, double c);

#endif //MATH_GEO_H