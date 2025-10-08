#include "Stereometry.h"
#include <stdio.h>
#include "RectangularPrism.h"
#include "RightSquarePyramid.h"
#include "LateralPyramidArea.h"
#include "RightCone.h"
#include "RightCylinder.h"
#include "sscanf.h"

void Stereometry(void) {
    int choice;
    printf("Solve a Rectangular Prism (1)\n"
        "Find Volume and Surface Area of a Right Square Pyramid (2)\n"
        "Find Lateral Surface Area of a Right Regular Pyramid (3)\n"
        "Solve a Right Cylinder (4)\n"
        "Solve a Right Cone (5)\n"
        "Which number?\n");
    ssscanf("%d",&choice);
    switch(choice) {
        case 1:
            RectPrism();
            break;
        case 2:
            sqrprymd();
            break;
        case 3:
            ltArea();
            break;
        case 4:
            rghCyl();
            break;
        case 5:
            rghCone();
            break;
        default:
            break;
    }
}
