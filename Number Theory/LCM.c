#include "LCM.h"
#include <stdio.h>
#include "Sieve.h"
#include "GCF.h"

void LCM(void) {
    int m;
    int n;
    printf("Please enter your first number. \n");
    scanf("%d", &m);
    printf("Please enter your second number. \n");
    scanf("%d", &n);
    if (m != 0 && n != 0) {
        int final = m*n/GCF(m, n);
        printf("The LCM of %d and %d is %d \n", m, n, final);
        primefacts(final);
    }
    else printf("The LCM of %d and %d is %d \n", m, n, m);
}
