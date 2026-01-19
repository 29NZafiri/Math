#include "Num.h"
#include <stdlib.h>

int* divisors(int n, int* cnt) {
    int fctrcnt = 0;
    int* fctrs = malloc((n+1) * sizeof(int)); //List of factors of n
    //A number n cannot have more than n+1 factors
    fctrs[fctrcnt++] = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            fctrs[fctrcnt++] = i;
        }
    }
    *cnt = fctrcnt;
    return fctrs;
}
