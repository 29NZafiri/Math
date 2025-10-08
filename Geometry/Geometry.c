#include "Geometry.h"
#include <stdio.h>
#include "Incenter.h"
#include "PolygonAngles.h"
#include "PolygonArea.h"
#include "PythagoreanInequality.h"
#include "PythagoreanTheorem.h"
#include "sscanf.h"
#include "TrapezoidArea.h"
#include "TriangleArea.h"

void Geometry(void) {
    int choice;
    printf("Solve for sides of right triangles (1)\n"
        "Compute the area of a triangle (2)\n"
        "Find the radius of a triangle's Incenter (3)\n"
        "Calculate the area of a Trapezoid with the height (4)\n"
        "Find the area of a regular polygon (5)\n"
        "Use the Pythagorean Inequality (6)\n"
        "Find angle measures in Polygons (7)\n"
        "Which number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            pyththrm();
            break;
        case 2:
            triArea();
            break;
        case 3:
            incenter();
            break;
        case 4:
            trpzdArea();
            break;
        case 5:
            polyArea();
            break;
        case 6:
            pythInequal();
            break;
        case 7:
            plgangle();
            break;
        default:
            break;
    }
}
