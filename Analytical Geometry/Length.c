#include "Length.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FloatMath.h"
#include "spsqrt.h"

void lnLength(void) {
    double x1, y1, x2, y2;
    printf("Please enter the first X coordinate\n");
    scanf("%lf", &x1);
    printf("Please enter the first Y coordinate\n");
    scanf("%lf", &y1);
    printf("Please enter the second X coordinate\n");
    scanf("%lf", &x2);
    printf("Please enter the second Y coordinate\n");
    scanf("%lf", &y2);
    double dist = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    char* rt = dbspsqrt(dist);
    printf("The length of the line is %s", rt);
    if (!DbInt(sqrt(dist))) printf(", or about %.17g\n", sqrt(dist));
    else printf(".\n");
    free(rt);
}
