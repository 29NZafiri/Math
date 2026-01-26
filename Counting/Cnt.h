#ifndef MATH_CNT_H
#define MATH_CNT_H
#include <stddef.h>
#include <stdint.h>

typedef struct{
    size_t size;
    uint8_t* number;
} fib; //Little Endian, base 256

fib nthNum(int n);
void printFib(fib num);
unsigned long long int nCr(int n, int r);
unsigned long long int perms(int n, int k);
int* binomCoefs(int x, int y, int pow);

#endif //MATH_CNT_H