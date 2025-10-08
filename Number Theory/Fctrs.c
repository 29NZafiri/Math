#include "Fctrs.h"
#include "Sieve.h"
#include <stdio.h>

#include "sscanf.h"

void Factrs(void) {
    int n = 1;
    while (n != 0){
        printf("What number would you like to factorize? (Enter 0 when done)\n");
        ssscanf("%d", &n);
        primefacts(n);
    }
}
