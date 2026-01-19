#include "Num.h"

int LCM(int num1, int num2) {
    int m = num1, n = num2, final;
    if (num1 < 0) m *= -1; //make sure that m is positive
    if (num2 < 0) n *= -1; //make sure that n is positive
    if (m != 0 && n != 0) final = m*n/GCF(m, n);
    else if (n > m) final = n;
    else final = m;
    return final;
}

long long llLCM(long long num1, long long num2) {
    long long m = num1, n = num2, final;
    if (num1 < 0) m *= -1; //make sure that m is positive
    if (num2 < 0) n *= -1; //make sure that n is positive
    if (m != 0 && n != 0) final = m/llGCF(m, n)*n;
    else if (n > m) final = n;
    else final = m;
    return final;
}