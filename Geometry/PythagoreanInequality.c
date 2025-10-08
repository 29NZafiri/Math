#include "PythagoreanInequality.h"
#include <stdio.h>
#include "FloatMath.h"
#include "sscanf.h"

void pythInequal(void) {
    double a, b, c;
    printf("Enter the first side of the triangle: \n");
    ssscanf("%lf", &a);
    printf("Enter the second side of the triangle: \n");
    ssscanf("%lf", &b);
    printf("Enter the third side of the triangle: \n");
    ssscanf("%lf", &c);
    double sides[3];
    if (a >= b && a >= c) {
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
    }
    else if (b >= a && b >= c) {
        sides[0] = b;
        sides[1] = a;
        sides[2] = c;
    }
    else if (c >= a && c >= b) {
        sides[0] = c;
        sides[1] = b;
        sides[2] = a;
    }
    int i = 0;
    if (sides[0] > sides[1] + sides[2]) {
        printf("This is not a triangle.\n");
        i++;
    }
    if (DbZero(sides[0] - sides[1] - sides[2])) {
        printf("This is a degenerate triangle.\n");
        i++;
    }
    if (a == b && b == c) {
        printf("This is an equilateral, and acute, triangle.\n");
        return;
    }
    if (DbZero(sides[0]*sides[0] - sides[1]*sides[1] - sides[2]*sides[2])) {
        printf("This is a right triangle.\n");
        i++;
    }
    if (sides[0]*sides[0] > sides[1]*sides[1] + sides[2]*sides[2]) {
        printf("This is an obtuse triangle.\n");
        i++;
    }
    if (sides[0]*sides[0] < sides[1]*sides[1] + sides[2]*sides[2]) {
        printf("This is an acute triangle.\n");
        i++;
    }
    if (i > 1) {
        printf("An error has occurred! Printing sides...\n");
        for (int j = 0; j < 2; j++) {
            printf("%.17g, ", sides[j]);
        }
        printf("%.17g\n", sides[2]);
    }
}
