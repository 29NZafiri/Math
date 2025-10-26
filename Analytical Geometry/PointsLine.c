#include "PointsLine.h"
#include <stdio.h>

#include "FloatMath.h"
#include "GCF.h"
#include "sscanf.h"

void pntsLn(void) {
    double x1, y1, x2, y2;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &x1);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &y1);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &x2);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &y2);
    double y = y2 - y1;
    double x = x2 - x1;
    if (x == 0) {
        printf("The slope is undefined, as the line is vertical\n");
    }
    if (x < 0) {
        x *= -1;
        y *= -1;
    }
    double slope = y/x;
    if (DbInt(x) && DbInt(y) && x != 0) {
        int g = GCF((int)x, (int)y);
        x /= g;
        y /= g;
    }
    double b = (x*y1-y*x1)/x;
    printf("The equation for this line is: y = %.15gx + %.15g\n", slope, x);
    if (x == 0) printf("In standard form: y = %.15g/%.15g", b/x, y);
    else printf("In standard form: %.15gx %+.15gy = %.15g", -y, x, b*x);

}
