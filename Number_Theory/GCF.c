#include "Num.h"

int GCF(int num1, int num2) {
    int m = num1, n = num2;
    if (num1 < 0) m *= -1; //make sure that m is positive
    if (num2 < 0) n *= -1; //make sure that n is positive
    while (m != 0 && n != 0) {
        if (m > n) m %= n;
        else n %= m;
    } //Euclidian Algorithm
    if (m > n) return m;
    return n;
}

long long llGCF(long long num1, long long num2) {
    long long m = num1, n = num2;
    if (num1 < 0) m *= -1; //make sure that m is positive
    if (num2 < 0) n *= -1; //make sure that n is positive
    while (m != 0 && n != 0) {
        if (m > n) m %= n;
        else n %= m;
    } //Euclidian Algorithm
    if (m > n) return m;
    return n;
}