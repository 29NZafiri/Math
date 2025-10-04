#include "Combinations.h"
#include <stdio.h>
#include "Factorial.h"

void nCr(void) {
    int n, r;
    printf("Please enter n\n");
    scanf("%d", &n);
    printf("Please enter m\n");
    scanf("%d", &r);
    long long int result = factorial(n) / (factorial(n - r) * factorial(r));
    printf("%lld\n", result);
}