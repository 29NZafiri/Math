#include "LateralPyramidArea.h"
#include <math.h>
#include <stdio.h>

#include "sscanf.h"
#include "../Constants.h"


void ltArea(void) {
    double s, l;
    int n;
    printf("Please enter the base side length\n");
    ssscanf("%lf", &s);
    printf("Please enter the slant height\n");
    scanf("%lf", &l);
    printf("Please enter the number of sides the base has\n");
    scanf("%d", &n);
    double LtAr = s*l*n/2;
    double apothem = s / (2 * tan(PI / n));
    double base = apothem * s * n / 2;
    double surfaceArea = LtAr + base;
    printf("The Lateral Surface area is %.17g\n"
        "If the pyramid is regular, the total surface area is %.17g\n", LtAr, surfaceArea);
}
