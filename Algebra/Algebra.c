#include "Algebra.h"
#include <stdio.h>
#include "FracSmp.h"
#include "FunctionCalc.h"
#include "ImaginaryMath.h"
#include "PolynomialFctrng.h"
#include "SmpSqrt.h"
#include "Quadractics.h"
#include "SlvSys.h"
#include "sscanf.h"
#include "USynthDiv.h"

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
            Quadrics();
            break;
        case 2:
            smpSqrt();
            break;
        case 3:
            fracSmp();
            break;
        case 4:
            syseq();
            break;
        case 5:
            imgMth();
            break;
        case 6:
            usynthdiv();
            break;
        case 7:
            funcCalc();
            break;
        case 8:
            plyfct();
            break;
        default:
            break;
    }
}
