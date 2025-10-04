#include "Counting.h"
#include "Combinations.h"
#include "NthFibNum.h"
#include <stdio.h>

void cnt(void) {
    int choice;
    printf("Compute Combinations (1)\n"
    "Find the nth Fibonacci number (2)\n"
    "What number?\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            nCr();
            break;
        case 2:
            nthNum();
            break;
        default:
            break;
    }
}
