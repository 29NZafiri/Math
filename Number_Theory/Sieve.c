#include "Num.h"
#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Power.h"

int* sieve(const int n, int* primeCount) {
    int count = n; //How many primes are there
    //Complementary Counting is used (Remove what we don't want)

    _Bool* isPrime = malloc((n + 1) * sizeof(_Bool)); //Allocate the necessary memory for the list
    if (!isPrime) return NULL;
    for (int i = 2; i <= n; i++)
        isPrime[i] = 1;

    count--; //1 is not prime, but doesn't get counted in the loop
    for (int i = 2; i*i <= n; i++) {
        for (int j = i*i; j <= n; j+=i) {
            if (isPrime[j])
                count--;
            isPrime[j] = 0;
        }
    }
    int* primes = malloc(count * sizeof(int));
    if (!primes) {
        free(isPrime);
        return NULL;
    }
    int index = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes[index++] = i;

    free(isPrime);
    *primeCount = count;
    if (index != count) {
        fprintf(stderr, "WARNING: index = %d but count = %d — heap corruption likely\n", index, count);
    };
    return primes; //Returns a list of the prime factors up to n
}

int* hfacts(const int n, int* fctrCount) { //function that helps out all the other functions
    if (n < 2) { //There are no prime numbers less than 2
        *fctrCount = 0;
        return NULL;
    }

    int primecounts; //Counts how many primes there are

    int* primes = sieve(n, &primecounts); //Get the primes up to n
    if (!primes) {
        fprintf(stderr, "WARNING! Error: [hfacts]! Failure allocating [primes]! Returning empty.");
        *fctrCount = 0;
        return NULL;
    }

    int fctrsize = INITIAL_ARRAY_SIZE; //Size of Factors
    int* factors = malloc(fctrsize * sizeof(int)); //List to hold the factors of n
    if (!factors) {
        fprintf(stderr, "WARNING! Error: [hfacts]! Failure allocating [smpfacts2]! Returning empty.");
        free(primes);
        exit(-1);
    }

    int size = 0; //Make sure that the list has enough space for the numbers

    for (int i = 0; i < primecounts; i++) {
        if (n%primes[i] == 0) { //If n is divisible by a prime

            if (fctrsize == size) { //If more space is needed to hold the factors

                fctrsize *= 2; //Double the size of the list to make room for more factors

                int* temp = realloc(factors, fctrsize * sizeof(int));
                if (!temp) {
                    fprintf(stderr, "WARNING! Error: [hfacts]! Failure allocating [temp]! Returning empty.");
                    free(primes);
                    exit(-1);
                }

                factors = temp;
            }
            factors[size] = primes[i]; //Make a list of the primes that can divide n
            size++;
        }
    }

    free(primes);
    *fctrCount = size;
    return factors;
}

int* ffacts(const int n, int* fctrCount) { //Finds the full divisors of n
    //For example, if 2^3 is a factor, 8 will be returned
    int sz; //Number of primes that divide n
    int* basefacts = hfacts(n, &sz); //List of primes that can divide n
    if (!basefacts) {
        *fctrCount = 0;
        return NULL;
    }

    int* fullfacts = malloc(sz * sizeof(int)); //Holds the factors raised their respective powers
    if (!fullfacts) {
        free(basefacts);
        *fctrCount = 0;
        return NULL;
    }

    for (int i = 0; i < sz; i++) { //Count how many times each prime divides n
        int fct = basefacts[i];
        int num = n;
        int count = 0;
        while (num % fct == 0) {
            num /= fct;
            count++;
        }
        fullfacts[i] = power(fct, count); // Store the prime as the base factor raised to the respective power
    }
    *fctrCount = sz;
    free(basefacts);
    return fullfacts;
}

int* bfacts(const int n, int* fctrCount) { //Finds the base divisors of n
    //For example, if 2^3 is a factor, 2 will be returned
    int sz; //Number of primes that divide n
    int* basefacts = hfacts(n, &sz); //List of primes that divide n
    if (!basefacts) return NULL;
    *fctrCount = sz;
    return basefacts;
}

int* pfacts(const int n, int* fctrCount) { //Finds the powers of the divisors of n
    //For example, if 2^3 is a factor, 3 will be returned
    int sz;
    int* basefacts = hfacts(n, &sz);
    if (!basefacts) {
        fprintf(stderr, "WARNING! Error: [pfacts]! Return is NULL for [facts]! Falling Back\n");
        return NULL;
    }
    int* powers = malloc(sz * sizeof(int));
    if (!powers) {
        fprintf(stderr, "WARNING! Error: [pfacts]! Return is NULL for [powers]! Falling Back\n");
        free(basefacts);
        return NULL;
    }
    for (int i = 0; i < sz; i++) { //Count how many times a given prime divides n
        int fct = basefacts[i];
        int num = n;
        int count = 0;
        while (num % fct == 0) {
            num /= fct;
            count++;
        }
        powers[i] = count;
    }
    *fctrCount = sz;
    free(basefacts);
    return powers;
}

void primefacts(const int n) { //Print the factors of n
    if (n < 2) {
        printf("Value cannot be less than 2.\n");
        return;
    }

    int sz; //Number of primes that divide n
    int* facts = hfacts(n, &sz); //List of primes that divide n
    if (!facts) return;

    int* ffctrs = malloc(sz * sizeof(int)); //List of full factors of n
    if (!ffctrs) {
        free(facts);
        return;
    }

    int* pfctrs = malloc(sz * sizeof(int)); //List of powers of the factors of n
    if (!pfctrs) {
        free(facts);
        free(ffctrs);
        return;
    }

    for (int i = 0; i < sz; i++) { //Count how many times a given factor divides n
        int fct = facts[i];
        int num = n;
        int count = 0;
        while (num % fct == 0) {
            num /= fct;
            count++;
        }
        ffctrs[i] = power(fct, count);
        pfctrs[i] = count;
    }

    printf("The prime factors of %d are: ", n);
    for (int i = 0; i < sz; i++) {
        printf("%d%s", ffctrs[i], (i == sz - 1) ? "\n" : ", ");
    }
    printf("In exponent form: ");
    for (int i = 0; i < sz; i++) {
        printf("%d^%d%s", facts[i], pfctrs[i], (i == sz - 1) ? "\n" : ", ");
    }
    free(ffctrs);
    free(pfctrs);
    free(facts);
}