#include "Combinations.h"
#include <stdio.h>
#include "sscanf.h"

void nCr(void) {
    int n, ir, r;
    printf("How many objects? (n in nCr)\n");
    scanf("%d", &n);
    printf("How many to pick? (r in nCr)\n");
    scanf("%d", &ir); //input r
    if (n/2 < ir) r = n-ir;
    else r = ir;
    unsigned long long int num = 1, denom = 1;
    for (unsigned long long int i = 0; i < r; i++)
        num *= n-i;
    for (unsigned long long int i = 2; i <= r; i++)
        denom *= i;
    unsigned long long int result = num / denom;
    printf("%dC%d = %lld\n", n, r, result);
}

