#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Num.h"
#include "Alg.h"

int intSynthDiv(int* coefs, const int cnt, const int zero) { //Synthetic division for integers while mutating coefs
    for (int i = 1; i < cnt; i++) {
        coefs[i] = coefs[i] + coefs[i-1] * zero;
    }
    return coefs[cnt-1];
}

long long ratSynthDiv(llfrac* coefs, const int cnt, const llfrac zero) { //Synthetic division for rationals while mutating coefs
    //Returns numerator
    for (int i = 1; i < cnt; i++) {
        long long denom = llLCM(zero.denom * coefs[i-1].denom, coefs[i].denom);
        long long num = coefs[i].num * denom / coefs[i].denom + coefs[i-1].num * zero.num * denom / coefs[i-1].denom / zero.denom;
        long long G = llGCF(num, denom);
        if (denom < 0) G *= -1;
        coefs[i] = (llfrac){num/G, denom/G};
    }
    return coefs[cnt-1].num;
}

llfrac* plyfct(int* coefs, const int cnt, int* zeroCnt) {
    llfrac* zeros = malloc(sizeof(llfrac) * (cnt-1)); //A nth degree polynomial has n roots
    if (!zeros) {
        fprintf(stderr, "Memory could not be allocated.\n");
        exit(-1);
    }
    { //Handle edge cases
        long safe = 0;
        for (int i = 0; i < cnt; i++) {
            safe += abs(coefs[i]);
        }
        if (!safe) { //0 polynomial
            free(coefs);
            zeros[0] = (llfrac){0, 0};
            *zeroCnt = 0;
            return zeros;
        }
        safe -= abs(coefs[cnt-1]);
        if (!safe) {
            free(coefs);
            zeros[0] = (llfrac){0, 0};
            zeroCnt[0] = 0;
            return zeros;
        }
    }

    long p = abs(coefs[cnt - 1]); //Last term of the polynomial
    long q = abs(coefs[0]); //First term of the polynomial
    //We only need the value at these indexes so we store it in a variable to make life easier

    int xtrap = 0; //How many trailing zeros
    while (p == 0) { //Find the real last term of the Polynomial in case the user provided zeros for trailing coefs
        xtrap++;
        p = abs(coefs[cnt - 1 - xtrap]);
    }

    int pfctrcnt;
    int* fctrs = divisors(p, &pfctrcnt);
    if (!fctrs) {
        fprintf(stderr, "Memory could not be allocated.\n");
        free(coefs);
        exit(-1);
    }

    int zcnt = 0;
    for (int i = 0; i < pfctrcnt; i++) { //This is the checking for zeros part
        int* tempcoefs = malloc(cnt * sizeof(int));
        int tcnt = cnt;
        if (!tempcoefs) {
            fprintf(stderr, "Memory could not be allocated.\n");
            free(coefs);
            free(fctrs);
            free(zeros);
            exit(-1);
        }
        int* tempmcoefs = malloc(cnt * sizeof(int));
        int mtcnt = cnt;
        if (!tempmcoefs) {
            fprintf(stderr, "Memory could not be allocated.\n");
            free(tempcoefs);
            free(coefs);
            free(fctrs);
            free(zeros);
            exit(-1);
        }
        memcpy(tempcoefs, coefs, sizeof(int) * cnt);
        memcpy(tempmcoefs, coefs, sizeof(int) * cnt);

        while (intSynthDiv(tempcoefs, tcnt, fctrs[i]) == 0) {
            llfrac zer = {fctrs[i], 1};
            zeros[zcnt] = zer;
            zcnt++;
            tcnt--;
        }
        while (intSynthDiv(tempmcoefs, mtcnt, -fctrs[i]) == 0) {
            llfrac mzer = {-fctrs[i], 1};
            zeros[zcnt] = mzer;
            zcnt++;
            mtcnt--;
        }
        free(tempcoefs);
        free(tempmcoefs);
    }

    if (q != 1) { //If there are rational zeros then we find them here
        int qfctrcnt;
        int* qfctrs = divisors(q, &qfctrcnt);

        llfrac* ratCoefs = malloc(sizeof(llfrac) * cnt);
        if (!ratCoefs) {
            fprintf(stderr, "Memory could not be allocated.\n");
            free(coefs);
            free(fctrs);
            free(zeros);
            exit(-1);
        }

        for (int i = 0; i < cnt; i++) ratCoefs[i] = (llfrac){coefs[i], 1};

        for (int i = 0; i < pfctrcnt; i++) {
            for (int j = 1; j < qfctrcnt; j++) {
                if (GCF(fctrs[i], qfctrs[j]) != 1) continue;
                llfrac* tempcoefs = malloc(cnt * sizeof(llfrac));
                int tcnt = cnt;
                if (!tempcoefs) {
                    fprintf(stderr, "Memory could not be allocated.\n");
                    free(coefs);
                    free(fctrs);
                    free(zeros);
                    free(ratCoefs);
                    exit(-1);
                }
                llfrac* tempmcoefs = malloc(cnt * sizeof(llfrac));
                int mtcnt = cnt;
                if (!tempmcoefs) {
                    fprintf(stderr, "Memory could not be allocated.\n");
                    free(tempcoefs);
                    free(coefs);
                    free(fctrs);
                    free(zeros);
                    free(ratCoefs);
                    exit(-1);
                }
                memcpy(tempcoefs, ratCoefs, sizeof(llfrac) * cnt);
                memcpy(tempmcoefs, ratCoefs, sizeof(llfrac) * cnt);

                while (ratSynthDiv(tempcoefs, tcnt, (llfrac){fctrs[i],qfctrs[j]}) == 0) {
                    llfrac zer = {fctrs[i], qfctrs[j]};
                    zeros[zcnt] = zer;
                    zcnt++;
                    tcnt--;
                }
                while (ratSynthDiv(tempmcoefs, mtcnt, (llfrac){-fctrs[i],qfctrs[j]}) == 0) {
                    llfrac mzer = {-fctrs[i], qfctrs[j]};
                    zeros[zcnt] = mzer;
                    zcnt++;
                    mtcnt--;
                }
                free(tempcoefs);
                free(tempmcoefs);
            }
        }
        free(qfctrs);
        free(ratCoefs);
    }
    for (int i = 0; i < xtrap; i++)
        zeros[zcnt+i] = (llfrac){0, 1};
    free(fctrs);
    *zeroCnt = zcnt + xtrap;
    return zeros;
}

void printFctrsPoly(const int* coefs, const llfrac* zeros, const int cnt, const int zcnt) {
    if (zcnt != cnt - 1) { //cnt-1 is the degree of the polynomial
        int tcnt = cnt;
        long long int er = 1;
        for (int i = 0; i < zcnt; i++) er *= zeros[i].denom;
        llfrac* remain = malloc(sizeof(llfrac) * tcnt);
        for (int i = 0; i < tcnt; i++) remain[i] = (llfrac){coefs[i], 1};
        printf("The polynomial was not able to be fully factored. Only %d factors were found.\n", zcnt);
        if (coefs[0] < 0) printf("-");
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].denom == 1)
                printf("(x%+lld)", -zeros[i].num);
            else
                printf("(%lldx%+lld)", zeros[i].denom, -zeros[i].num);
        }
        for (int i = 0; i < zcnt; i++) { //Do the division of the known factors to find the remaining unfactorable part
            llfrac* tempremain = llFsynthDiv(remain, tcnt, zeros[i]);
            if (!tempremain) {
                free(remain);
                printf("\nMemory allocation failed during synthetic division. Returning early. Sorry!\n");
                exit(-1);
            }
            free(remain);
            remain = tempremain;
            tcnt--;
        }
        printf("(");
        for (int i = 0; i < tcnt; i++) {
            remain[i].num /= llabs(er);
            if (remain[i].num == 0) continue;
            if (remain[i].denom == 1) {
                if (remain[i].num == 1) printf("+x^%d", tcnt-i-1);
                else if (remain[i].num == -1) printf("-x^%d", tcnt-i-1);
                else printf("%+lldx^%d", remain[i].num, tcnt - i - 1);
            }
            else printf("+(%lldx^%d)/%lld", remain[i].num, tcnt - i - 1, remain[i].denom);
        }
        printf(")\n");
        free(remain);
    }

    else {
        printf("The polynomial was fully factored.\n");
        if (coefs[0] < 0) printf("-");
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].denom == 1)
                printf("(x%+lld)", -zeros[i].num);
            else
                printf("(%lldx%+lld)", zeros[i].denom, -zeros[i].num);
        }
        printf("\nThe roots of the polynomial are:\n");
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].denom == 1) printf("%lld, ", zeros[i].num);
            else {
                printf("%lld/%lld, ", zeros[i].num, zeros[i].denom);
            }
        }
    }
}