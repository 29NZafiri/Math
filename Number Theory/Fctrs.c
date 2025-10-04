#include "Fctrs.h"
#include "Sieve.h"
#include <stdio.h>

void Factrs(void) {
    int n = 1;
    while (n != 0){
        printf("What number would you like to factorize? (Enter 0 when done)\n");
        scanf("%d", &n);
        primefacts(n);
    }
}