#include "Combinations.h"
#include <stdio.h>
#include "Factorial.h"
#include "sscanf.h"

void nCr(void) {
    int n, r;
    printf("Please enter n\n");
    ssscanf("%d", &n);
    printf("Please enter m\n");
    ssscanf("%d", &r);
    long long int result = factorial(n) / (factorial(n - r) * factorial(r));
    printf("%lld\n", result);
}
