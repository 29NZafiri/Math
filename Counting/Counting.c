#include "Counting.h"
#include "Combinations.h"
#include "NthFibNum.h"
#include "Permutations.h"
#include <stdio.h>

#include "sscanf.h"

void cnt(void) {
    int choice;
    printf("Compute Permutations (1)\n"
    "Compute Combinations (2)\n"
    "Find the nth Fibonacci number (3)\n"
    "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            Perms();
            break;
        case 2:
            nCr();
            break;
        case 3:
            nthNum();
            break;
        default:
            break;
    }
}
