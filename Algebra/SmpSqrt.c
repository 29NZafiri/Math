#include "SmpSqrt.h"
#include <stdio.h>
#include <stdlib.h>

#include "spsqrt.h"
#include "sscanf.h"

void smpSqrt(void) {
    int x;
    printf("Enter the integer Square root you would like to simplify: \n");
    ssscanf("%d", &x);
    char* final = spsqrt(x);
    printf("Simplified, the square root is %s", final);
    free(final);
}
