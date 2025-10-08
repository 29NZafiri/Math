#include "Permutations.h"

#include <stdio.h>

#include "Factorial.h"
#include "sscanf.h"

void Perms(void) {
    int n, k;
    printf("How many objects? (n in nPk)\n");
    ssscanf("%d", &n);
    printf("How many spaces? (k in nPk)\n");
    ssscanf("%d", &k);
    long long int num = factorial(n);
    long long int den = factorial(n-k);
    long long int perm = num/den;
    printf("%dP%d = %lld", n, k, perm);
}
