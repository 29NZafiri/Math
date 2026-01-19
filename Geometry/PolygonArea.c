#include "Geo.h"
#include <math.h>
#include "Constants.h"

double pPolyArea(double perimeter, int n) {
    double apothem = perimeter / (2 * n * tan(PI / n));
    return apothem * perimeter / 2;
}

double aPolyArea(double apothem, int n) {
    double perimeter = 2*apothem*n*cos(PI/2-(double)2/n);
    return apothem * perimeter / 2;
}