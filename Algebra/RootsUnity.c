#include <stdlib.h>

#include "Alg.h"
#include "Frac.h"

frac* rtsUnity(int pow) {
    frac* rts = malloc(sizeof(frac)*pow);
    for (int i = 0; i < pow; i++) {
        rts[i].num = i*2;
        rts[i].denom = pow;
    }
    return rts;
}