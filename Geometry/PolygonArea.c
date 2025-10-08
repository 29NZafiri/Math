#include "PolygonArea.h"
#include <math.h>
#include <stdio.h>

#include "sscanf.h"
#include "../Constants.h"

void polyArea(void) {
    int cperm, capoth;
    double perimeter = 0, apothem = 0;
    double n = 0, s = 0;
    printf("Do you have the perimeter(1)?\n");
    ssscanf("%d", &cperm);
    printf("Do you have the apothem(1)?\n");
    ssscanf("%d", &capoth);
    printf("How many sides does the polygon have?\n");
    ssscanf("%lf", &n);
    if (cperm == 1) {
        printf("What is the perimeter?\n");
        ssscanf("%lf", &perimeter);
    }
    else {
        printf("What is the length of a side?\n");
        ssscanf("%lf", &s);
        perimeter = n * s;
    }
    if (capoth == 1) {
        printf("What is the apothem?\n");
        ssscanf("%lf", &apothem);
    }
    else if (s != 0) {
        apothem = s / (2 * tan(PI / n));
    }
    else {
        apothem = perimeter / (2 * n * tan(PI / n));
    }
    double area = apothem * perimeter / 2;
    printf("The area of the polygon is %.17g\n", area);
}
