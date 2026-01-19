#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../Algebra/Alg.h"
#include "FloatMath.h"
#include "spsqrt.h"
#include "sscanf.h"

void Alg1(void) {
    // Assign values to the coefficients of the quadratics
    double a, b, c;
    printf("Enter a\n");
    ssscanf("%lf", &a);
    printf("Enter b\n");
    ssscanf("%lf", &b);
    printf("Enter c\n");
    ssscanf("%lf", &c);

    double coef[3] = {a, b, c};

    if (a == 0) {
        // Prevent division by 0
        printf("a cannot be zero. Terminating early.\n");
        return;
    }
    { //roots
    rts roots = quadRoots(coef);
    if (!roots.cmplx) {
        if (roots.dis) {
            double root1 = (roots.real+sqrt(roots.dis))/roots.denom;
            double root2 = (roots.real-sqrt(roots.dis))/roots.denom;
            printf("The roots to the quadratic are: %.15g, %.15g\n", root1, root2);
            if (!DbInt(root1) && !DbInt(root2)) {
                if (DbInt(roots.dis)) spprintf("Unsimplified: (%g\u00B1%r)/(%g)\n", -b, spsqrt((int)roots.dis), 2*a);
                else printf("Unsimplified: (%.15g\u00B1√%.15g)/(%.15g)\n", -b, roots.dis, 2*a);
            }
        }
        else {
            double root = roots.real/roots.denom;
            printf("The root to the quadratic is: %.15g\n", root);
            if (!DbInt(root)) printf("As a Fraction, %.15g/%.15g\n", roots.real, roots.denom);
        }
    }
    else {
        dbComplex root1 = {roots.real/roots.denom, sqrt(-roots.dis)/roots.denom};
        dbComplex root2 = {roots.real/roots.denom, -sqrt(-roots.dis)/roots.denom};
        spprintf("The roots to the quadratic are: %i, %i\n", root1, root2);
        if (!ComplexInt(root1) && !ComplexInt(root2)) {
            if (DbInt(roots.dis)) spprintf("Unsimplified: (%g\u00B1i%r)/(%g)\n", -b, spsqrt(-(int)roots.dis), 2*a);
            else printf("Unsimplified: (%.15g\u00B1i√%.15g)/(%.15g)\n", -b, -roots.dis, 2*a);
        }
    }
    }

    { //Vieta's
    dbfrac sumF = sumFunc(coef);
    double sum = sumF.num/sumF.denom;
    printf("By Vieta's formula, the sum of the roots is %.15g", sum);
    if (!DbInt(sum)) printf(", or %.15g/%.15g", sumF.num, sumF.denom);
    dbfrac proF = prodFunc(coef, 3);
    double pro = proF.num/proF.denom;
    printf(", and the product of the roots is %.15g", pro);
    if (!DbInt(pro)) printf(", or %.15g/%.15g", proF.num, proF.denom);
    printf("\n");
    }

    { //Vertex
    dbfrac XvertexF = xVertexQuad(coef);
    dbfrac YvertexF = yVertexQuad(coef);
    double Xvertex = XvertexF.num/XvertexF.denom;
    double Yvertex = f(coef, 3, Xvertex); /*Same as plugging in Xvertex into the quadratic
    // (4*a*c-b*b)/(4*a) would also work, but requires division, which is slower than the solution used
    // a*x*x + b*x + c would also work, but is a bit less efficient than f()*/

    printf("The vertex of the quadratic is (%.15g, %.15g)\n", Xvertex, Yvertex);

    if (!DbInt(Xvertex)) printf("The X coordinate of the vertex as a fraction is %.15g/%.15g\n", XvertexF.num, XvertexF.denom);

    if (!DbInt(Yvertex)) printf("The Y coordinate of the vertex as a fraction is %.15g/%.15g\n", YvertexF.num, YvertexF.denom);
    //Range
    printf("The range of the quadratic is ");
    if (a > 0) printf("[%.15g, \u221E)\n", Yvertex);
    else printf("(-\u221E, %.15g]\n", Yvertex);
    }

    //Input values into the Quadratic
    double x = 1;
    while (x != 0) {
        printf("Would you like to try any numbers? When done, enter 0. \n");
        ssscanf("%lf", &x);
        double ans = f(coef, 3, x);
        printf("f(%.15g) = %.15g\n", x, ans);
    }
}

void Alg2(void) {
    int x;
    printf("Enter the integer Square root you would like to simplify: \n");
    ssscanf("%d", &x);
    sqRoot final = spsqrt(x);
    spprintf("Simplified, the square root is %r", final);
}

void Alg3(void) {
    int num, denom;
    printf("What is the numerator?\n");
    ssscanf("%d", &num);
    printf("What is the denominator?\n");
    ssscanf("%d", &denom);
    printf("The original fraction was %d/%d\n", num, denom);
    int G = fracSmp(&num, &denom);
    if (G > 1) {
        printf("The new fraction is %d/%d\n", num, denom);
        printf("The new fraction was reduced by a factor of %d", G);
    }
}

void Alg4(void) {
    printf("Equations should be in the form X+Y=C\n");
    double a, b, c, d, e, f;
    printf("Enter the coefficient of the first X.\n");
    ssscanf("%lf", &a);
    printf("Enter the coefficient of the first Y.\n");
    ssscanf("%lf", &b);
    printf("Enter the first constant.\n");
    ssscanf("%lf", &c);
    printf("Enter the coefficient of the second X.\n");
    ssscanf("%lf", &d);
    printf("Enter the coefficient of the second Y.\n");
    ssscanf("%lf", &e);
    printf("Enter the coefficient of the second constant.\n");\
    ssscanf("%lf", &f);
    dbSys sys1 = {a, b, c};
    dbSys sys2 = {d, e, f};
    dbPnt solutions = syseq(sys1, sys2);
    spprintf("The solutions to the equation are %p", solutions);
}

void Alg5(void) {
    dbComplex a, b, result;
    int choice;
    printf("Enter the real part of the first number\n");
    ssscanf("%lf", &a.real);
    printf("Enter the imaginary part of the first number\n");
    ssscanf("%lf", &a.imag);
    printf("What operation would you like to perform? Addition (1), Subtraction (2), Multiplication (3), Division (4), "
           "Finding Square Roots (5), Squaring (6), or Taking Absolute Value (7)\n");
    ssscanf("%d", &choice);
    if (choice > 5) {
        printf("Enter the real part of the second number\n");
        ssscanf("%lf", &b.real);
        printf("Enter the imaginary part of the second number\n");
        ssscanf("%lf", &b.imag);
    }
    char* op = "+-*/√^|";
    switch (choice) {
        case 1:
            result = addComplex(a, b); break;
        case 2:
            result = minusComplex(a, b); break;
        case 3:
            result = multComplex(a, b); break;
        case 4:
            result = divComplex(a, b); break;
        case 5:
            result = sqrtComplex(a); break;
        case 6:
            result = sqrComplex(a); break;
        case 7:
            result.real = absComplex(a);
            result.imag = 0; break;
        default:
            printf("Invalid choice\n"); return;
    }
    if (choice < 5) {
        printComplex(a);
        printf("%c", op[choice]);
        printComplex(b);
        printf("=");
        printComplex(result);
    }
    else {
        if (choice == 5 || choice == 7) printf("%c", op[choice]);
        printComplex(a);
        if (choice != 7) printf("%c", op[choice]);
        spprintf("= %i", result);
        if (choice == 7) spprintf("& %i", multComplex(result, (dbComplex){-1, 0}));
    }
}

void Alg6(void) {
    int cnt; //Amount of terms in the polynomial
    double* coefs = promptFunc(&cnt); //List of terms in the polynomial
    double a, b;
    printf("What is the coefficient of the linear term? (?x-b)\n");
    ssscanf("%lf", &a);
    printf("What would you like to divide by? (ax-?)\n");
    ssscanf("%lf", &b);
    printf("f(x)/(%.15gx%+.15g) = \n", a, -b);
    double* sol = synthdiv(coefs, cnt, a, b);
    for (int i = 0; i < cnt-2; i++)
        printf("%+.15gx^%d", sol[i], cnt - i - 2);
    printf("%+.15g", sol[cnt-2]);
    if (sol[cnt-1] != 0) printf(" %+.15g/(%.15gx%+.15g)", sol[cnt - 1], a, -b);
    free(coefs);
    free(sol);
}

void Alg7(void) {
    int cnt; //Amount of terms in the polynomial
    double* coefs = promptFunc(&cnt); //List of terms in the polynomial
    double x = 1;
    while (x != 0) {
        printf("What number would you like to try? When done, enter 0. \n");
        ssscanf("%lf", &x);
        double ans = f(coefs, cnt, x);
        printf("f(%.15g) = %.15g\n", x, ans);
    }
    free(coefs);
}

void Alg8(void) {
    int cnt, zcnt;
    int* coefs = intPromptFunc(&cnt);
    if (cnt == 1) {
        printf("Constant. No factoring Possible.");
        return;
    }
    llfrac* zeros = plyfct(coefs, cnt, &zcnt);
    printFctrsPoly(coefs, zeros, cnt, zcnt);
    free(coefs);
    free(zeros);
}

void Algebra(void){
    int choice;
    printf("Solve a Quadratic (1)\n"
    "Simplify a Square Root (2)\n"
    "Simplify Fractions (3)\n"
    "Solve a two-variable system of equations (4)\n"
    "Do Imaginary Arithmetic (5)\n"
    "Synthetically Divide (6)\n"
    "Plug values into a Function (7)\n"
    "Factor a Polynomial (8)\n"
    "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            Alg1();
            break;
        case 2:
            Alg2();
            break;
        case 3:
            Alg3();
            break;
        case 4:
            Alg4();
            break;
        case 5:
            Alg5();
            break;
        case 6:
            Alg6();
            break;
        case 7:
            Alg7();
            break;
        case 8:
            Alg8();
            break;
        default:
            break;
    }
}
