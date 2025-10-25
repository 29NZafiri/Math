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
    unsigned long long int perm = 1;
    for (unsigned long long int i = 0; i < k; i++)
        perm *= n-i;
    printf("%dP%d = %lld", n, k, perm);
}
