#include "Power.h"

int power(int base, int exp) {
    int final = base;
    for (int i = 2; i <= exp; i++)
        final *= base;
    return final;
}
