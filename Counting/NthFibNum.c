#include <Cnt.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "Constants.h"

fib makeFib(size_t sz) { //Constructor for fib
    fib num;
    num.number = calloc(sz, sizeof(uint8_t));
    num.size = sz;
    return num;
}

void freeFib(fib num) { //Deconstructor for fib
    free(num.number);
    num.number = NULL;
    num.size = 0;
}

void trimFib(fib* num) { //Get rid of one leading zero
    if (num->number[num->size-1] == 0) {
        num->size--;
        uint8_t* temp = realloc(num->number, num->size * sizeof(uint8_t));
        if (!temp)
            exit(-1);
        num->number = temp;
    }
}

void assignFib(fib* num, uint8_t val) { //Assign a value to a fib (must be within uint8_t)
    num -> number[0] = val;
}

fib addFib(fib* a,fib* b) { //Add two fibs
    size_t sz = a->size;
    if (a->size < b->size) sz = b->size;
    sz++;
    fib result = makeFib(sz);
    uint8_t carry = 0;
    for (size_t i = 0; i < sz-1; i++) {
        uint16_t resa, resb;
        resa = a->number[i];
        if (i > a->size-1) resa = 0;
        resb = b->number[i];
        if (i > b->size-1) resb = 0;
        uint16_t res = resa + resb + carry;
        uint8_t firstRes = res & 0x00FF;
        uint8_t secondRes = (res & 0xFF00) >> 8;
        result.number[i] = firstRes;
        carry = secondRes;
    }
    result.number[sz-1] = carry;
    trimFib(&result);
    return result;
}

fib nthNum(int n) { //return the nth fib num
    if (n == 0) {fib ret = makeFib(1); assignFib(&ret, 0); return ret;}
    if (n <= 2) {fib ret = makeFib(1); assignFib(&ret, 1); return ret;}
    fib a = makeFib(1);
    fib b = makeFib(1);
    assignFib(&a, 1);
    assignFib(&b, 1);
    for (int i = 2; i < n; i++) {
        fib tmp = addFib(&a, &b);
        freeFib(b);
        b = a;
        a = tmp;
    }
    freeFib(b);
    return a;
}

void uPrintFib(fib num) {

}

uint8_t divideFibBy10(fib* num) { //TBH, vibe coded this. It divides by 10 a bunch
    uint16_t remainder = 0;

    for (size_t i = num->size; i > 0; i--) {
        remainder = (remainder * 256) + num->number[i-1];
        num->number[i-1] = (uint8_t)(remainder / 10);
        remainder %= 10;
    }

    trimFib(num);
    return (uint8_t)remainder;
}

void printFib(fib num) { //Vibe coded this too. It prints fibs
    char decimal_string[BUFFER_SIZE + 1];
    int digit_index = 0;

    fib working_copy = makeFib(num.size);
    if (num.size > 0) {
        memcpy(working_copy.number, num.number, num.size);
        working_copy.size = num.size;
    } else {
        printf("0\n");
        freeFib(working_copy);
        return;
    }

    do {
        uint8_t remainder = divideFibBy10(&working_copy);
        decimal_string[digit_index++] = remainder + '0';

        if (digit_index >= BUFFER_SIZE) {
            printf("ERROR: Number too large for print buffer.\n");
            break;
        }

    } while (working_copy.size > 0);

    if (digit_index == 0) {
        printf("0");
    } else {
        for (int i = digit_index - 1; i >= 0; i--) {
            printf("%c", decimal_string[i]);
        }
    };
    freeFib(working_copy);
}