#include "Modulo.h"
#include <stdio.h>

#include "GCF.h"

void umod(void) {
    int b = 1;
    printf("Enter 0 for the modulus to exit\n");
    while (b != 0) {
        b = 1;
        int a;
        printf("What number?\n");
        scanf("%d", &a);
        printf("What is the modulus?\n");
        scanf("%d", &b);
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

void testmod(void) {
    int a, b, c;
    printf("Enter 0 for the modulus to exit\n");
    while (c != 0) {
        printf("What is the first number?\n");
        scanf("%d", &a);
        printf("What is the second number?\n");
        scanf("%d", &b);
        printf("What is the modulus?\n");
        scanf("%d", &c);
        if (c != 0 && (a - b) % c == 0) {
            printf("%d \u2261 %d (mod %d)\n", a, b, c);
        }
        else {
            printf("%d \u2262 %d (mod %d)\n", a, b, c);
        }
    }
}

void modinv(void) {
    int a, b;
    printf("What number?\n");
    scanf("%d", &a);
    printf("What is the modulus?\n");
    scanf("%d", &b);
    if (GCF(a, b) != 1) {
        printf("%d has no modular inverse in mod %d\n", a, b);
    }
    else {
        int x = 0;
        while ((a * x) % b != 1 && x < b) {
            x += 1;
        }
        printf("The modular inverse of %d is %d in mod %d\n", a, x, b);
    }
}