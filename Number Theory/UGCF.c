#include "GCF.h"
#include <stdio.h>
#include "Sieve.h"

void UGCF(void) {
    int m;
    int n;
    printf("Please enter your first number. \n");
    scanf("%d", &m);
    printf("Please enter your second number. \n");
    scanf("%d", &n);
    int final = GCF(m, n);
    printf("The GCF of %d and %d is %d \n", m, n, final);
    primefacts(final);
}
