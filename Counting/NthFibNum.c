#include "NthFibNum.h"
#include <stdio.h>

#include "sscanf.h"

void nthNum(void) {
    unsigned n;
    long long unsigned a = 0, b = 1;
    printf("How many Fibonacci numbers do you want?\n");
    ssscanf("%d",&n);
    if (n > 93) {
        printf("This number is too big. The program can only go up to F(93)\n");
        n = 93;
    }
    printf("The Fibonacci numbers up to %u are:\n"
        "0, 1,", n);
    for (int i = 2; i <= n; i++) {
        if (a < b) {
            a += b;
            printf(" %llu,", a);
        }
        else {
            b += a;
            printf(" %llu,", b);
        }
    }
    printf("\b.\n"
        "F(%u) = %llu", n, a > b ? a : b);
}
