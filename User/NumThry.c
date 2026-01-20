#include <stdio.h>
#include "sscanf.h"
#include "../Number_Theory/Num.h"

void Num1() {
    int n, cnt;
    printf("What number?\n");
    ssscanf("%d", &n);
    int* divisor = divisors(n, &cnt);
    printf("The divisors of %d are\n", n);
    for (int i = 0; i < cnt-1; i++)
        printf("%d, ", divisor[i]);
    printf("and %d\n", divisor[cnt-1]);
}

void Num2() {
    int n, cnt;
    printf("What number?\n");
    ssscanf("%d", &n);
    int* primes = sieve(n, &cnt);
    printf("The primes of %d are\n", n);
    for (int i = 0; i < cnt-1; i++)
        printf("%d, ", primes[i]);
    printf("and %d\n", primes[cnt-1]);
}

void Num3() {
    int n;
    printf("What number?\n");
    ssscanf("%d", &n);
    primefacts(n);
}

void Num4() {
    int n = 1;
    printf("What is the first number?\n");
    ssscanf("%d", &n);
    while (1) {
        int m;
        printf("What is the next number? (Enter 0 or 1 to exit)\n");
        ssscanf("%d", &m);
        if (m < 2) break;
        printf("The GCF of %d and %d is %d\n", m, n, GCF(n, m));
        n = GCF(n, m);
    }
}

void Num5() {
    int n = 1;
    printf("What is the first number?\n");
    ssscanf("%d", &n);
    while (1) {
        int m;
        printf("What is the next number? (Enter 0 or 1 to exit)\n");
        ssscanf("%d", &m);
        if (m < 2) break;
        printf("The LCM of %d and %d is %d\n", m, n, LCM(n, m));
        n = LCM(n, m);
    }
}

void Num6() {
    int b = 1;
    printf("Enter 0 for the modulus to exit\n");
    while (b != 0) {
        b = 1;
        int a;
        printf("What number?\n");
        ssscanf("%d", &a);
        printf("What is the modulus?\n");
        ssscanf("%d", &b);
        if (b != 0){
            int m = a % b;
            int x = 0;
            if (b < 0) {
                b *= -1;
                x = 1;
            }
            if (m < 0) m += b;
            if (x == 1) b *= -1;
            printf("%d (mod %d) is %d\n", a, b, m);
        }
    }
}

void Num7() {
    int a, b, c = 1;
    printf("Enter 0 for the modulus to exit\n");
    while (c != 0) {
        printf("What is the first number?\n");
        ssscanf("%d", &a);
        printf("What is the second number?\n");
        ssscanf("%d", &b);
        printf("What is the modulus?\n");
        ssscanf("%d", &c);
        if (c != 0 && (a - b) % c == 0) {
            printf("%d \u2261 %d (mod %d)\n", a, b, c);
        }
        else {
            printf("%d \u2262 %d (mod %d)\n", a, b, c);
        }
    }
}

void Num8() {
    int a, b = 1;
    printf("Enter 0 for the modulus to exit\n");
    while (b != 0) {
        printf("What number?\n");
        ssscanf("%d", &a);
        printf("What is the modulus?\n");
        ssscanf("%d", &b);
        int i = modinv(a, b);
        if (i) printf("%d has a modular inverse of %d mod %d.\n", a, i, b);
        else printf("%d has no modular inverse mod %d", a, b);
    }
}

void NumThry(void){
    int choice;
    printf("Find the divisors of a number (1)\n"
    "Use the Sieve of Eratosthenes (2)\n"
    "Find the prime factors of a number (3)\n"
    "Find the GCF using the Euclidian Algorithm (4)\n"
    "Find the LCM of some numbers (5)\n"
    "Take the Modulo of a number (6)\n"
    "Check for Modular Congruence (7)\n"
    "Find the Modular Inverse of a Number (8)\n"
    "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            Num1();
            break;
        case 2:
            Num2();
            break;
        case 3:
            Num3();
            break;
        case 4:
            Num4();
            break;
        case 5:
            Num5();
            break;
        case 6:
            Num6();
            break;
        case 7:
            Num7();
            break;
        case 8:
            Num8();
            break;
        default:
            break;
    }
}
