#include <Cnt.h>

unsigned long long int nCr(int n, int r) {
    if (r > n) return 0;
    if (n/2 < r) r = n-r;
    unsigned long long int num = 1, denom = 1;
    for (unsigned long long int i = 0; i < r; i++)
        num *= n-i;
    for (unsigned long long int i = r; i >= 2; i--)
        denom *= i;
    unsigned long long int result = num / denom;
    return result;
}
