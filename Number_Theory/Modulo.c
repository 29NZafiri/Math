#include "Num.h"

int modinv(int a, int b) {
    if (GCF(a, b) != 1) return 0;
    int x = 0;
    while ((a * x) % b != 1 && x < b) {
        x += 1;
    }
    return x;
}
