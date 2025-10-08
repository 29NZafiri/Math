#include "RightSquarePyramid.h"
#include <math.h>
#include <stdio.h>

#include "sscanf.h"

void sqrprymd(void) {
    double s, l;
    printf("Please enter the base side length\n");
    ssscanf("%lf", &s);
    printf("Please enter the apex length\n");
    ssscanf("%lf", &l);
    double SlHe = sqrt((l*l)-(s*s/4));
    double SA = 4*((SlHe)*s/2)+(s*s);
    double PyHe = sqrt((SlHe*SlHe)-(s*s/4));
    double Vol = (PyHe*(s*s))/3;
    printf("The surface area is %.17g units\u00b2\n"
      "The slant height is %.17g\n"
      "The pyramid's height is %.17g\n"
      "The volume is %.17g units\u00b3\n", SA, SlHe, PyHe, Vol);
}
