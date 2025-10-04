#include "TriangleArea.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "spsqrt.h"

void triArea(void) {
    double a, b, c;
    printf("Enter the first side of the triangle: \n");
    scanf("%lf", &a);
    printf("Enter the second side of the triangle: \n");
    scanf("%lf", &b);
    printf("Enter the third side of the triangle: \n");
    scanf("%lf", &c);
    double s = (a + b + c) / 2;
    double val = s * (s - a) * (s - b) * (s - c);
    double area = sqrt(val);
    char* rt = dbspsqrt(val);
    printf("The area of the triangle is %.17g\n", area);
    printf("As a radical: %s\n", rt);
    free(rt);
}
