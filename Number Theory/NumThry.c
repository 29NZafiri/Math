#include <stdio.h>
#include "NumThry.h"
#include "Dvsrs.h"
#include "UGCF.h"
#include "Primes.h"
#include "Fctrs.h"
#include "LCM.h"
#include "Modulo.h"
#include "sscanf.h"

void NumThry(void){
    int choice;
    printf("Find the divisors of a number (1)\n"
    "Use the Sieve of Eratosthenes (2)\n"
    "Find the prime factors of a number (3)\n"
    "Find the GCF using the Euclidian Algorithm (4)\n"
    "Find the LCM of two numbers (5)\n"
    "Take the Modulo of a number (6)\n"
    "Check for Modular Congruence (7)\n"
    "Find the Modular Inverse of a Number (8)\n"
    "What number?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            Dvsrs();
            break;
        case 2:
            Primes();
            break;
        case 3:
            Factrs();
            break;
        case 4:
            UGCF();
            break;
        case 5:
            LCM();
            break;
        case 6:
            umod();
            break;
        case 7:
            testmod();
            break;
        case 8:
            modinv();
        default:
            break;
    }
}
