#include "RightCylinder.h"
#include <stdio.h>

#include "sscanf.h"
#include "../Constants.h"


void rghCyl(void) {
    double r, h;
    printf("Please enter the radius of the cylinder: ");
    ssscanf("%lf", &r);
    printf("Please enter the height of the cylinder: ");
    ssscanf("%lf", &h);
    double Vol = r*r*h;
    double LatArea = 2*r*h;
    double TotArea = LatArea+2*r*r;
    printf("The Volume of the Cylinder is %.17g\u03C0\n"
    "The Lateral Surface Area of the Cylinder is %.17g\u03C0 ~ %.17g\n"
    "The Total Surface Area of the Cylinder is %.17g\u03C0 ~ %.17g\n", Vol, LatArea, LatArea * PI, TotArea, TotArea * PI);
}
