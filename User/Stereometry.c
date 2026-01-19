#include "../Stereometry/Strometry.h"
#include <stdio.h>

#include "Constants.h"
#include "Geo.h"
#include "sscanf.h"

void stro1() {
    double l, w, h;
    printf("Enter the length of the Rectangular Prism\n");
    ssscanf("%lf", &l);
    printf("Enter the width of the Rectangular Prism\n");
    ssscanf("%lf", &w);
    printf("Enter the height of the Rectangular Prism\n");
    ssscanf("%lf", &h);
    double vol = rectPrismVol(l, w, h);
    double SA = rectPrismSA(l, w, h);
    dbSqrt SD = rectPrismSD(l, w, h);
    spprintf("The Surface Area is %g units\u00b2\nThe Volume is %g units\u00b3\nThe Space Diagonal is %R ~  units\n", SA, vol, SD, dbCompSprt(SD));
}

void stro2() {
    double s, l;
    printf("Please enter the base side length\n");
    ssscanf("%lf", &s);
    printf("Please enter the apex length\n");
    ssscanf("%lf", &l);
    dbSqrt SlHe = sqrPymdSlHe(l, s);
    dbSqrt PyHe = sqrPymdPyHe(l, s);
    dbMSurd SA = sqrPymdSA(l, s);
    dbSqrt Vol = sqrPymdVol(s, l);
    spprintf("The surface area is %M ~ %g units\u00b2\nThe slant height is %R ~ %g\nThe pyramid's height is %R ~ %g\nThe volume is %R ~ %g", SA, dbCompSprt(SA.surd)+SA.rational, SlHe, dbCompSprt(SlHe), PyHe, dbCompSprt(PyHe), Vol, dbCompSprt(Vol));
}

void stro3() {
    double s, l;
    int n;
    printf("Please enter the base side length\n");
    ssscanf("%lf", &s);
    printf("Please enter the slant height\n");
    ssscanf("%lf", &l);
    printf("Please enter the number of sides the base has\n");
    ssscanf("%d", &n);
    double lt = ltArea(s, l, n);
    double base = pPolyArea(s*n, n);
    printf("The lateral surface area is %.15g\n"
           "The total surface area is %.15g\n", lt, lt+base);
}

void stro4() {
    double r, h;
    printf("Please enter the radius of the cylinder: ");
    ssscanf("%lf", &r);
    printf("Please enter the height of the cylinder: ");
    ssscanf("%lf", &h);
    double vol = rghCylVol(r, h);
    dbSqrt LatArea = rghConeHLArea(r, h);
    dbMSurd TotArea = {LatArea, r*r};
    spprintf("The volume is %g\u03C0 ~ %g\n"
        "The lateral surface area is %R\u03C0 ~ %g\n"
        "The total surface area is (%M)\u03C0 ~ %g", vol, vol*PI, LatArea, dbCompSprt(LatArea)*PI, TotArea, dbCompMSurd(TotArea)*PI);
}

void stro5() {
    int solve;
    printf("Do you have the Slant Height(1), or the Cone Height(2)?");
    ssscanf("%d", &solve);
    double vol;
    dbSqrt latArea;
    if (solve != 1 && solve != 2) return;
    double r;
    if (solve == 1) {
        double h;
        printf("Please enter the radius\n");
        ssscanf("%lf", &r);
        printf("Please enter the Cone Height\n");
        ssscanf("%lf", &h);
        vol = rghConeVol(r, h);
        latArea = rghConeHLArea(r, h);
    }
    if (solve == 2) {
        double l;
        printf("Please enter the radius\n");
        ssscanf("%lf", &r);
        printf("Please enter the Slant Height\n");
        ssscanf("%lf", &l);
        vol = rghConeVol(r, dbCompSprt(rghConeH(r, l)));
        latArea = rghConeLLArea(r, l);
    }
    dbMSurd totArea = {latArea, r*r};
    spprintf("The volume is %g\u03C0 ~ %g\n"
             "The lateral surface area is %R\u03C0 ~ %g\n"
             "The total surface area is (%M)\u03C0 ~ %g", vol, vol*PI, latArea, dbCompSprt(latArea)*PI, totArea, dbCompMSurd(totArea)*PI);
}

void stro(void) {
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
            stro1();
            break;
        case 2:
            stro2();
            break;
        case 3:
            stro3();
            break;
        case 4:
            stro4();
            break;
        case 5:
            stro5();
            break;
        default:
            break;
    }
}
