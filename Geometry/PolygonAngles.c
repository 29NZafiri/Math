#include "PolygonAngles.h"
#include <stdio.h>

void plgangle(void) {
    int n;
    printf("Enter the number of sides.\n");
    scanf("%d", &n);
    int sum = 180*(n-2);
    double angle = (double)sum/n;
    printf("The sum of the angles in the polygon is %d degrees\n", sum);
    printf("In a regular polygon, each angle is %.17g degrees\n", angle);
}
