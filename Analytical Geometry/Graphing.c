#include "Graphing.h"
#include <stdio.h>

#include "Length.h"
#include "Midpoint.h"
#include "PointLineDistance.h"
#include "PointsLine.h"
#include "Slope.h"
#include "SlopePointLine.h"

void anaGeo(void) {
    int choice;
    printf("Find the Length of a Line in the Cartesian Plane (1)\n"
        "Find the Midpoint of a Line Segment in the Cartesian Plane (2)\n"
        "Find the Slope of a Line in the Cartesian Plane (3)\n"
        "Find the Equation for a Line with 2 Points (4)\n"
        "Find the Equation for a Line with a Slope and a Point (5)\n"
        "Find the Distance between a Point and a Line (6)\n"
        "What number?\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            lnLength();
            break;
        case 2:
            midLn();
            break;
        case 3:
            slpLn();
            break;
        case 4:
            pntsLn();
            break;
        case 5:
            slpPntLn();
            break;
        case 6:
            dstPntLn();
            break;
        default:
            break;
    }
}
