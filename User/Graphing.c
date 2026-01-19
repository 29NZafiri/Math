#include <math.h>
#include <stdio.h>

#include "../Analytical_Geometry/AnaGeo.h"
#include "FloatMath.h"
#include "sscanf.h"

void anaGeo1(void) {
    dbPnt a, b;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &a.y);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &b.x);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &b.y);
    dbSqrt lenth = lnLength(a, b);
    spprintf("The length is %R ~ %g \n", lenth, dbCompSprt(lenth));
}

void anaGeo2(void) {
    dbPnt a, b;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &a.y);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &b.x);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &b.y);
    dbPnt mid = midLn(a, b);
    spprintf("The middle is %p\n", mid);
}

void anaGeo3(void) {
    dbPnt a, b;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &a.y);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &b.x);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &b.y);
    dbfrac slope = slpLn(a, b);
    if (DbZero(slope.denom)){
        printf("The slope is undefined, as the line is vertical\n");
        return;
    }
    printf("The slope is %.15g/%.15g\n", slope.num, slope.denom);
}

void anaGeo4(void) {
    dbPnt a, b;
    printf("Please enter the first X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the first Y coordinate\n");
    ssscanf("%lf", &a.y);
    printf("Please enter the second X coordinate\n");
    ssscanf("%lf", &b.x);
    printf("Please enter the second Y coordinate\n");
    ssscanf("%lf", &b.y);
    if (DbEq(a.x ,b.x)) {
        printf("The equation for this line is x = %.15g\n", a.x);
        return;
    }
    if (DbEq(a.y, b.y)) {
        printf("The equation for this line is y = %.15g\n", a.y);
        return;
    }
    dbSys line = pntsLn(a, b);
    printf("The equation for this line is: y = %.15gx %+.15g\n", -line.x, line.c);
    printf("In standard form, %.15gx + y = %.15g\n", line.x, line.c);
}

void anaGeo5(void) {
    dbPnt a;
    double m;
    printf("Please enter the slope\n");
    ssscanf("%lf", &m);
    printf("Please enter the X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the Y coordinate\n");
    ssscanf("%lf", &a.y);
    dbSys line = slpPntLn(m, a);
    printf("The equation for this line is: y = %.15gx %+.15g\n", -line.x, line.c);
    printf("In standard form, %.15gx + y = %.15g\n", line.x, line.c);
}

void anaGeo6(void) {
    dbSys line;
    dbPnt a;
    printf("The line should be in the equation Ax+By+C=0\n");
    printf("Please enter A\n");
    ssscanf("%lf", &line.x);
    printf("Please enter B\n");
    ssscanf("%lf", &line.y);
    printf("Please enter C\n");
    ssscanf("%lf", &line.c);
    printf("Please enter the X coordinate\n");
    ssscanf("%lf", &a.x);
    printf("Please enter the Y coordinate\n");
    ssscanf("%lf", &a.y);
    irFrac dist = dstPntLn(line, a);
    printf("The distance is %.15g\n", dist.num.rat*sqrt(dist.num.irr)/dist.denom);
    spprintf("In fractional form, %R/%g\n", dist.num, dist.denom);
}

void anaGeo7(void) {
    dbPnt r, a;
    double angle;
    printf("What is the X coordinate of the center of rotation (The stationary point)?\n");
    ssscanf("%lf", &r.x);
    printf("What is the Y coordinate of the center of rotation (The stationary point)?\n");
    ssscanf("%lf", &r.y);
    printf("What is the angle of rotation? (Clockwise in degrees)\n");
    ssscanf("%lf", &angle);
    printf("What is the X coordinate of the point to rotate?\n");
    ssscanf("%lf", &a.x);
    printf("What is the Y coordinate of the point to rotate?\n");
    ssscanf("%lf", &a.y);
    dbPnt res = rtPnt(r, a, angle);
    spprintf("After rotation, the new point is %p\n", res);
}

void anaGeo(void) {
    int choice;
    printf("Find the Length of a Line in the Cartesian Plane (1)\n"
        "Find the Midpoint of a Line Segment in the Cartesian Plane (2)\n"
        "Find the Slope of a Line in the Cartesian Plane (3)\n"
        "Find the Equation for a Line with 2 Points (4)\n"
        "Find the Equation for a Line with a Slope and a Point (5)\n"
        "Find the Distance between a Point and a Line (6)\n"
        "Rotate a Point around another point (7)\n"
        "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            anaGeo1();
            break;
        case 2:
            anaGeo2();
            break;
        case 3:
            anaGeo3();
            break;
        case 4:
            anaGeo4();
            break;
        case 5:
            anaGeo5();
            break;
        case 6:
            anaGeo6();
            break;
        case 7:
            anaGeo7();
            break;
        default:
            break;
    }
}
