#include "../Counting/Cnt.h"
#include <stdio.h>

#include "sscanf.h"

void Cnt1() {
     int n, k;
     printf("How many objects? (n in nPk)");
     ssscanf("%d", &n);
     printf("How many spots? (k in nPk)");
     ssscanf("%d", &k);
     printf("%dP%d is %llu", n, k, perms(n, k));
}

void Cnt2() {
    int n, r;
    printf("How many objects? (n in nPr)");
    ssscanf("%d", &n);
    printf("How many spots? (r in nPr)");
    ssscanf("%d", &r);
    printf("%dP%d is %llu", n, r, nCr(n, r));
}

void Cnt3() {
    int n;
    printf("What number?");
    ssscanf("%d", &n);
    fib num = nthNum(n);
    printf("F(%d) = ", n);
    printFib(num);
}

void cnt(void) {
    int choice;
    printf("Compute Permutations (1)\n"
    "Compute Combinations (2)\n"
    "Find the nth Fibonacci number (3)\n"
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
        default:
            break;
    }
}
