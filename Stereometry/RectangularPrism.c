#include "RectangularPrism.h"
#include <stdio.h>
#include <stdlib.h>

#include "spsqrt.h"
#include "sscanf.h"

void RectPrism(void) {
    double l, w, h;
    printf("Enter the length of the Rectangular Prism\n");
    ssscanf("%lf", &l);
    printf("Enter the width of the Rectangular Prism\n");
    ssscanf("%lf", &w);
    printf("Enter the height of the Rectangular Prism\n");
    ssscanf("%lf", &h);
    double SA = 2*((l*w)+(w*h)+(l*h));
    double Vol = l*w*h;
    char* SD = dbspsqrt((l*l)+(w*w)+(h*h));
    printf("The surface area is %.17g units\u00b2\n"
       "The volume is %.17g units\u00b3\n"
       "The Space Diagonal is %s units\n", SA, Vol, SD);
    free(SD);
}
