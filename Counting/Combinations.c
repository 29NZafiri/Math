#include "Combinations.h"
#include <stdio.h>
#include "sscanf.h"

void nCr(void) {
    printf("\n");
    int n, r;
    printf("How many objects? (n in nCr)\n");
    ssscanf("%d", &n);
    printf("How many to pick? (r in nCr)\n");
    ssscanf("%d", &r);
    unsigned long long int num = 1, denom = 1;
    for (unsigned long long int i = 0; i < r; i++)
        num *= n-i;
    for (unsigned long long int i = 2; i <= r; i++)
        denom *= i;
    unsigned long long int result = num / denom;
    printf("%dC%d = %lld\n", n, r, result);
}
