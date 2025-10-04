#include "Slope.h"
#include <stdio.h>

#include "FloatMath.h"
#include "GCF.h"

void slpLn(void) {
    double x1, y1, x2, y2;
    printf("Please enter the first X coordinate\n");
    scanf("%lf", &x1);
    printf("Please enter the first Y coordinate\n");
    scanf("%lf", &y1);
    printf("Please enter the second X coordinate\n");
    scanf("%lf", &x2);
    printf("Please enter the second Y coordinate\n");
    scanf("%lf", &y2);
    double y = y2 - y1;
    double x = x2 - x1;
    if (DbZero(x)) {
        printf("The slope is undefined, as the line is vertical\n");
    }
    if (x < 0) {
        x *= -1;
        y *= -1;
    }
    double slope = y/x;
    if (DbInt(x) && DbInt(y)) {
        int g = GCF((int)x, (int)y);
        x /= g;
        y /= g;
        printf("The slope is %.17g, or %d/%d\n",slope, (int)y, (int)x);
    }
    else {
        printf("The slope is %.17g, or %.17g/%.17g\n",slope, y, x);
    }
}
