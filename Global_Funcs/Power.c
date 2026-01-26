#include "Power.h"

int power(int base, int exp) {
    if (exp == 0) return 1;
    int final = base;
    for (int i = 2; i <= exp; i++)
        final *= base;
    return final;
}
