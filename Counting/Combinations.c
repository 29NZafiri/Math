#include <Cnt.h>

unsigned long long int nCr(int n, int ir) {
    int r;
    if (n/2 < ir) r = n-ir;
    else r = ir;
    unsigned long long int num = 1, denom = 1;
    for (unsigned long long int i = 0; i < r; i++)
        num *= n-i;
    for (unsigned long long int i = r; i >= 2; i--)
        denom *= i;
    unsigned long long int result = num / denom;
    return result;
}
