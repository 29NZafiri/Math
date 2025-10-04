#include "Dvsrs.h"
#include <stdio.h>

void factors(int n) {
    int sz = 0;
    int x = 0;
    printf("The divisors of %d are ", n);
    for (int i = 1; i < n; i++) {
        if (n%i == 0) {
            printf("%d, ", i);
            sz += 1;
            x += i;
        }
    }
    printf("and %d.\n", n);
    printf("%d has %d factors.\n", n, sz+1);
    if (sz == 1) {
        printf("%d is prime. \n", n);
    }
    if (x < n) {
        printf("%d is an deficient number, as %d < %d.\n", n, n, x);
    }
    else if (x == n) {
        printf("%d is an perfect number, as %d = %d.\n", n, n, x);
    }
    else {
        printf("%d is an abundant number, as %d > %d.\n", n, n, x);
    }
}

void Dvsrs(void) {
    int n = 5;
    printf("Please enter a number.\n");
    scanf("%d", &n);
    while (n != 0) {
        int sz = 0;
        int x = 0;
        printf("The divisors of %d are ", n);
        for (int i = 1; i < n; i++) {
            if (n%i == 0) {
                printf("%d, ", i);
                sz += 1;
                x += i;
            }
        }
        printf("and %d.\n", n);
        printf("%d has %d factors.\n", n, sz+1);
        if (sz == 1) {
            printf("%d is prime. \n", n);
        }
        if (x < n) {
            printf("%d is an deficient number, as %d < %d.\n", n, n, x);
        }
        else if (x == n) {
            printf("%d is an perfect number, as %d = %d.\n", n, n, x);
        }
        else {
            printf("%d is an abundant number, as %d > %d.\n", n, n, x);
        }
        printf("Any other numbers? (0 for none)\n");
        scanf("%d", &n);
    }
}
