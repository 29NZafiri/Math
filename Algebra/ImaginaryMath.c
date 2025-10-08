#include "ImaginaryMath.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FloatMath.h"
#include "GCF.h"
#include "spsqrt.h"
#include "sscanf.h"


void imgMth(void) {
    double a, a1, a2, b, b1, b2;
    int choice;
    printf("Enter the real part of the first number\n");
    ssscanf("%lf", &a1);
    printf("Enter the imaginary part of the first number\n");
    ssscanf("%lf", &b1);
    printf("What operation would you like to perform? Addition (1), Subtraction (2), Multiplication (3), Division (4), Finding Square Roots (5), Squaring (6), or Taking Absolute Value (7)\n");
    ssscanf("%d", &choice);
    if (choice < 5) {
        printf("Enter the real part of the second number\n");
        ssscanf("%lf", &a2);
        printf("Enter the imaginary part of the second number\n");
        ssscanf("%lf", &b2);
    }
    switch (choice) {
        case 1:
            a = a1 + a2;
            b = b1 + b2;
            printf("%.17g + %.17gi + %.17g + %.17gi = %.17g + %.17gi\n", a1, b1, a2, b2, a, b);
            break;
        case 2:
            a = a1 - a2;
            b = b1 - b2;
            printf("%.17g + %.17gi - %.17g - %.17gi = %.17g + %.17gi\n", a1, b1, a2, b2, a, b);
            break;
        case 3:
            a = a1 * a2 - b1 * b2;
            b = a1 * b2 + a2 * b1;
            printf("(%.17g + %.17gi)(%.17g + %.17gi) = %.17g + %.17gi\n", a1, b1, a2, b2, a, b);
            break;
        case 4:
            double aN = a1 * a2 + b1 * b2;
            double bN = -a1 * b2 + a2 * b1;
            double d = a2*a2 + b2*b2;
            a = aN / d;
            b = bN / d;
            if (d != 0) {
                printf("(%.17g + %.17gi)/(%.17g + %.17gi) = %.17g + %.17gi\n", a1, b1, a2, b2, a, b);
                if (DbInt(d)) {
                    if (!DbInt(a) && DbInt(aN))
                        printf("%.17g = %d/%d\n", a, (int)aN/GCF((int)aN, (int)d), (int)d/GCF((int)aN, (int)d));

                    if (!DbInt(b) && DbInt(bN))
                        printf("%.17g = %d/%d\n", b, (int)bN/GCF((int)bN, (int)d), (int)d/GCF((int)bN, (int)d));
                }
            }
            else printf("Division by Zero! Failed operation! \n");
            break;
        case 5:
            if (a1 == 0 && b1 == 0) {
                a = 0;
                b = 0;
            }
            else if (b1 == 0 && a1 < 0) {
                a = 0;
                b = sqrt(-a1);
            }
            else {
                a = sqrt((a1+sqrt(a1*a1+b1*b1))/2);
                b = b1/(2*a);
            }
            printf("√(%.17g + %.17gi) is %.17g + %.17gi and %.17g + %.17gi\n", a1, b1, a, b, -a, -b);
            break;
        case 6:
            a = a1*a1-b1*b1;
            b = 2*a1*b1;
            printf("(%.17g + %.17gi)^2 = %.17g + %.17gi", a1, b1, a, b);
            break;
        case 7:
            a = a1*a1 + b1 * b1;
            b = sqrt(a);
            char* rt = dbspsqrt(a);
            printf("|%.17g + %.17gi| = %s = %.17g\n", a1, b1, rt, b);
            free(rt);
            break;
        default:
            break;
    }
}
