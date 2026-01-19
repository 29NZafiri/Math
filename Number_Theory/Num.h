#ifndef MATH_NUM_H
#define MATH_NUM_H

int* divisors(int n, int* cnt);
int GCF(int num1, int num2);
long long llGCF(long long num1, long long num2);
int LCM(int num1, int num2);
long long llLCM(long long num1, long long num2);
int modinv(int a, int b);
int* sieve(int n, int* primeCount);
int* ffacts(int n, int* fctrCount);
int* bfacts(int n, int* fctrCount);
int* pfacts(int n, int* fctrCount);
void primefacts(int n);



#endif //MATH_NUM_H