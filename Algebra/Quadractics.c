#include "Quadractics.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FloatMath.h"
#include "func.h"
#include "GCF.h"
#include "spsqrt.h"

void Quadrics(void) {
    //Assign values to the coefficients of the quadratics
    double a, b, c;
    printf("Enter a\n");
    scanf("%lf", &a);
    printf("Enter b\n");
    scanf("%lf", &b);
    printf("Enter c\n");
    scanf("%lf", &c);

    if (a == 0) {
        // Prevent division by 0
        printf("a cannot be zero. Terminating early.\n");
        return;
    }

    double coef[3] = {a, b, c};

    //Roots
    {
        double dis = b*b - 4*a*c; //discriminant of the quadratic formula

        char* rt; //Houses the value for the square root in the quadratic formula

        if (dis > 0) { //2 real values

            rt = dbspsqrt(dis); //Simplifies the discriminant when taking the square root
            //For example, if dis = 8, rt = 2 root 2

            double root1 = (-b + sqrt(dis))/(2*a);
            double root2 = (-b - sqrt(dis))/(2*a);

            printf("The roots to the quadratic are: %.17g, %.17g\n", root1, root2);
            if (!DbInt(root1) || !DbInt(root2)) printf("Unsimplified: (%.17g\u00B1%s)/(%.17g)\n", -b, rt, 2*a);
            free(rt);
        }

        else if (dis == 0) { //2 repeated roots/1 root

            double root = -b/(2*a);
            double num = -b, denom = 2*a;

            printf("The root to the quadratic is: %.17g\n", root);
            if (!DbInt(root)) printf("As a Fraction, %.17g/%.17g\n", num, denom);

        }

        else { //2 imaginary roots

            rt = dbspsqrt(-dis); //Simplifies the discriminant when taking the square root
            //For example, if dis = 8, rt = 2 root 2

            printf("There are no real roots to the quadratic.\n");

            printf("The imaginary roots are: %.17g\u00B1%.17gi\n", -b/(2*a), sqrt(-dis)/(2*a));
            printf("Unsimplified: (%.17g\u00B1i%s)/(%.17g)\n", -b, rt, 2*a);
            free(rt);
        }
    }

    //Vieta
    {
        double sum = -b/a, pro = c/a;
        printf("By Vieta's formula, the sum of the roots is %.17g", sum);
        if (!DbInt(sum))
            printf(", or %.17g/%.17g", -b, a);
        printf(", and the product of the roots is %.17g", pro);
        if (!DbInt(pro))
            printf(", or %.17g/%.17g", c, a);
        printf("\n");
    }

    //Vertex
    {
        double Xvertex = -b/(2*a);
        double Yvertex = f(coef, 3, Xvertex); /*Same as plugging in Xvertex into the quadratic
        (4*a*c-b*b)/(4*a) would also work, but requires division, which is slower than the solution used
        a*x*x + b*x + c would also work, but is a bit less efficient than f()*/

        printf("The vertex of the quadratic is (%.17g, %.17g)\n", Xvertex, Yvertex);


        if (!DbInt(Xvertex)) { //Make sure that the X coordinate isn't an integer
            int XFracCmd;
            if (DbInt(a) && DbInt(b)) XFracCmd = GCF((int)b, 2*(int)a); //Simplify the fraction via GCF

            else XFracCmd = 1; //Fraction has decimal numerator and/or denominator

            if (a < 0) XFracCmd *= -1; //Ensure the Denominator is positive

            printf("The X coordinate of the vertex as a fraction is %.17g/%.17g\n", -b/XFracCmd, 2*a/XFracCmd);
        }

        if (!DbInt(Yvertex)) { //Make sure that the Y coordinate isn't an integer
            int YFracCmd;

            if (DbInt(a) && DbInt(b) && DbInt(c)) YFracCmd = GCF((int)(4*a*c-b*b), 4*(int)a); //Simplify the fraction via GCF

            else YFracCmd = 1; //Fraction has decimal numerator and/or denominator

            if (a < 0) YFracCmd = -YFracCmd; //Ensure the Denominator is positive

            printf("The Y coordinate of the vertex as a fraction is %.17g/%.17g\n", (4*a*c-b*b)/YFracCmd, 4*a/YFracCmd);
        }
        //Range
        printf("The range of the quadratic is ");
        if (a > 0) {
            printf("[%.17g, \u221E)\n", Yvertex);
        }
        else {
            printf("(-\u221E, %.17g]\n", Yvertex);
        }
    }

    //Input values into the Quadratic
    double x = 1;
    double ans;
    while (x != 0) {
        printf("Would you like to try any numbers? When done, enter 0. \n");
        scanf("%lf", &x);
        ans = f(coef, 3, x);
        printf("f(%.17g) = %.17g\n", x, ans);
    }
}
