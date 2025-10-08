#include "FracSmp.h"
#include <stdio.h>
#include "GCF.h"
#include "sscanf.h"

void fracSmp(void) {
    int num, denom;
    printf("What is the numerator?\n");
    ssscanf("%d", &num);
    printf("What is the denominator?\n");
    ssscanf("%d", &denom);
    int G = GCF(num, denom);
    printf("The original fraction was %d/%d\n", num, denom);
    printf("The new fraction is %d/%d\n", num/G, denom/G);
}
