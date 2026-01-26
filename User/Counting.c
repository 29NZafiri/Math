#include "../Counting/Cnt.h"
#include <stdio.h>
#include <stdlib.h>

#include "sscanf.h"

void Cnt1() {
     int n, k;
     printf("How many objects? (n in nPk)\n");
     ssscanf("%d", &n);
     printf("How many spots? (k in nPk)\n");
     ssscanf("%d", &k);
     printf("%dP%d is %llu", n, k, perms(n, k));
}

void Cnt2() {
    int n, r;
    printf("How many objects? (n in nCr)\n");
    ssscanf("%d", &n);
    printf("How many spots? (r in nCr)\n");
    ssscanf("%d", &r);
    printf("%dC%d is %llu", n, r, nCr(n, r));
}

void Cnt3() {
    int n;
    printf("What number?\n");
    ssscanf("%d", &n);
    fib num = nthNum(n);
    printf("F(%d) = ", n);
    printFib(num);
}

void Cnt4() {
    int x, y, pow;
    printf("Expressions are assumed to be in the form (ax+by)\u207F\n");
    printf("What is the coefficient of the x term (a)?\n");
    ssscanf("%d", &x);
    printf("What is the coefficient of the y term (b)?\n");
    ssscanf("%d", &y);
    printf("What is the power of the binomial (n)?\n");
    ssscanf("%d", &pow);

    int* coefs = binomCoefs(x, y, pow);

    if (x == 1) printf("(x");
    else if (x == -1) printf("(-x");
    else printf("(%dx", x);

    if (y == 1) printf("+y)");
    else if (y == -1) printf("-y");
    else printf("%+dy)", y);

    printPower(pow);

    printf(" = ");

    if (pow == 1) {
        printf("%dx+%dy", x, y);
        free(coefs);
        return;
    }
    if (coefs[0] == 1) printf("x");
    else printf("%dx", coefs[0]);
    printPower(pow);
    for (int i = 1; i < pow; i++) {
        printf("%+dx", coefs[i]);
        printPower(pow-i);
        printf("y");
        printPower(i);
    }
    if (coefs[0] == 1) printf("+y");
    else printf("%+dy\n", coefs[pow-1]);
    printPower(pow);

    free(coefs);
}

void cnt(void) {
    int choice;
    printf("Compute Permutations (1)\n"
    "Compute Combinations (2)\n"
    "Find the nth Fibonacci number (3)\n"
    "Use the Binomial Theorem (4)\n"
    "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            Cnt1();
            break;
        case 2:
            Cnt2();
            break;
        case 3:
            Cnt3();
            break;
        case 4:
            Cnt4();
            break;
        default:
            break;
    }
}
