#include <stdlib.h>

#include "Cnt.h"
#include "Power.h"

int* binomCoefs(int x, int y, int pow) {
    int* coefs = malloc(sizeof(int) * (pow + 1));
    for (int i = 0; i <= pow; i++)
        coefs[i] = (int)nCr(pow, i) * power(x, pow - i) * power(y, i);
    return coefs;
}
