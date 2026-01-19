#include "../Geometry/Geo.h"
#include <stdio.h>

#include "FloatMath.h"
#include "sscanf.h"

void geo1() {
    int solve;
    dbSqrt ans = {0, -1, ""}; //In case the compiler freaks
    printf("Are you looking for the leg(1) or the hypotenuse(2)\n");
    ssscanf("%d", &solve);
    if (solve == 1) {
        double h, l;
        printf("What is the hypotenuse?\n");
        ssscanf("%lf", &h);
        printf("What is the leg?\n");
        ssscanf("%lf", &l);
        ans = leg(h, l);
        printf("The missing leg is %.15g\n", dbCompSprt(ans));
    }
    if (solve == 2) {
        double a, b;
        printf("What is the first leg?\n");
        ssscanf("%lf", &a);
        printf("What is the second leg?\n");
        ssscanf("%lf", &b);
        ans = hyp(a, b);
        printf("The hypotenuse is %.17g\n", dbCompSprt(ans));
    }
    if ((solve == 1 || solve == 2) && ans.irr != -1)
        spprintf("As a radical, it's %R\n", ans);
}

void geo2() {
    double a, b, c;
    printf("Enter the first side of the triangle: \n");
    ssscanf("%lf", &a);
    printf("Enter the second side of the triangle: \n");
    ssscanf("%lf", &b);
    printf("Enter the third side of the triangle: \n");
    ssscanf("%lf", &c);
    dbSqrt area = triArea(a, b, c);
    printf("The area of the triangle is %.15g\n", dbCompSprt(area));
    spprintf("As a radical: %R\n", area);
}

void geo3() {
    double a, b, c;
    printf("Enter the first side of the triangle: \n");
    ssscanf("%lf", &a);
    printf("Enter the second side of the triangle: \n");
    ssscanf("%lf", &b);
    printf("Enter the third side of the triangle: \n");
    ssscanf("%lf", &c);
    irFrac radius = incenter(a, b, c);
    double rad = dbCompSprt(radius.num)/radius.denom;
    printf("The inradius of the triangle is %.15g\n", rad);
    if (!DbInt(rad))
        spprintf("As a fraction, %R/%g\n", radius.num, radius.denom);
}

void geo4() {
    double a, b, h;
    printf("What is the first base:\n");
    ssscanf("%lf", &a);
    printf("What is the second base:\n");
    ssscanf("%lf", &b);
    printf("What is the height:\n");
    ssscanf("%lf", &h);
    double area = trpzdArea(a, b, h);
    printf("The area of the trapezoid is %.15g", area);
}

void geo5() {
    _Bool cperm;
    double perimeter = 0, apothem = 0, area;
    int n = 0;
    printf("Do you have the perimeter(1)?\n");
    ssscanf("%b", &cperm);
    printf("How many sides does the polygon have?\n");
    ssscanf("%lf", &n);
    if (cperm) {
        printf("What is the perimeter?\n");
        ssscanf("%lf", &perimeter);
        area = pPolyArea(perimeter, n);
    }
    else {
        printf("What is the apothem?\n");
        ssscanf("%lf", &apothem);
        area = aPolyArea(apothem, n);
    }
    printf("The area of the polygon is %.15g", area);

}

void geo6() {
    double a, b, c;
    printf("Enter the first side of the triangle: \n");
    ssscanf("%lf", &a);
    printf("Enter the second side of the triangle: \n");
    ssscanf("%lf", &b);
    printf("Enter the third side of the triangle: \n");
    ssscanf("%lf", &c);
    printf("This is %s triangle\n", pythInequal(a, b, c));
}

void geo7() {
    int n;
    printf("Enter the number of sides.\n");
    ssscanf("%d", &n);
    int sum = plgangle(n);
    printf("The sum of the angles in the polygon is %d degrees\n", sum);
    printf("In a regular polygon, each angle is %.15g degrees\n", (double)sum/n);
}

void Geo(void) {
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
            geo1();
            break;
        case 2:
            geo2();
            break;
        case 3:
            geo3();
            break;
        case 4:
            geo4();
            break;
        case 5:
            geo5();
            break;
        case 6:
            geo6();
            break;
        case 7:
            geo7();
            break;
        default:
            break;
    }
}
