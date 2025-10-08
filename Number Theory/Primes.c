#include "Primes.h"
#include "Sieve.h"
#include <stdio.h>
#include <stdlib.h>

#include "sscanf.h"

int* sieve(int n, int* primeCount);

void Primes(void) {
    int count;
    int up;
    printf("What would you like to go up to?\n");
    ssscanf("%d", &up);
    int* primes = sieve(up, &count);
    printf("The primes from 0 to %d are:\n", up);
    if (count > 0) {
        for (int i = 0; i < count-1; i++) {
            printf("%d, ", primes[i]);
        }
        printf("%d\n", primes[count-1]);
    }
    printf("\u03C0(%d) = %d\n", up, count);
    free(primes);
}
