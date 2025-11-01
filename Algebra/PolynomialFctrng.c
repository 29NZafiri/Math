#include "PolynomialFctrng.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FloatMath.h"
#include "func.h"
#include "GCF.h"
#include "sscanf.h"
#include "Constants.h"


struct zerostruc {
    int p;
    int q;
};

int intSynthDiv(int* coefs, const int cnt, const int zero) { //Synthetic division for integers while mutating coefs
    for (int i = 1; i < cnt; i++) {
        coefs[i] = coefs[i] + coefs[i-1] * zero;
    }
    return coefs[cnt-1];
}

double ratSynthDiv(double* coefs, const int cnt, const double zero) { //Synthetic division for rationals while mutating coefs
    for (int i = 1; i < cnt; i++) {
        coefs[i] = coefs[i] + coefs[i-1] * zero;
    }
    return coefs[cnt-1];
}

int* divisors(int n, int* cnt) {
    int fctrcnt = 0;
    int* fctrs = malloc((n+1) * sizeof(int)); //List of factors of n
    //A number n cannot have more than n+1 factors
    fctrs[fctrcnt++] = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            fctrs[fctrcnt++] = i;
        }
    }
    *cnt = fctrcnt;
    return fctrs;
}

void plyfct(void) {
    int cnt; //Amount of terms in the polynomial
    printf("How many terms are in your polynomial (The degree of the polynomial+1)?\n");
    ssscanf("%d", &cnt);

    int* coefs = malloc(cnt * sizeof(int)); //List of terms in the polynomial
    if (!coefs) {
        printf("Memory could not be allocated.\n");
        return;
    }
    double* doubcoefs = malloc(cnt * sizeof(double));
    if (!doubcoefs) {
        printf("Memory could not be allocated.\n");
        free(coefs);
        return;
    }

    promptfunc(doubcoefs, cnt);

    { //Handle edge cases
        int safe = 0;
        for (int i = 0; i < cnt; i++) {
            coefs[i] = (int)doubcoefs[i];
            safe += abs(coefs[i]);
        }
        if (!safe) {
            printf("0 polynomial. No factoring possible");
            free(coefs);
            free(doubcoefs);
            return;
        }
        safe -= abs(coefs[cnt-1]);
        if (!safe) {
            printf("Constant. No factoring possible");
            free(coefs);
            free(doubcoefs);
            return;
        }
    }

    int p = abs(coefs[cnt - 1]); //Last term of the polynomial
    int q = abs(coefs[0]); //First term of the polynomial
    //We only need the value at these indexes so we store it in a variable to make life easier

    int xtraq = 0; //How many leading zeros
    while (q == 0) { //Find the real first term of the Polynomial in case the user provided zeros for leading coefs
        xtraq++;
        q = abs(coefs[xtraq]);
    }

    int xtrap = 0; //How many trailing zeros
    while (p == 0) { //Find the real last term of the Polynomial in case the user provided zeros for trailing coefs
        xtrap++;
        p = abs(coefs[cnt - 1 - xtrap]);
    }

    int pfctrcnt;
    int* fctrs = divisors(p, &pfctrcnt);
    struct zerostruc* zeros = malloc(sizeof(struct zerostruc) * (cnt-1));
    if (!zeros) {
        printf("Memory could not be allocated.\n");
        free(doubcoefs);
        free(coefs);
        free(fctrs);
        return;
    }

    int zcnt = 0;
    int endless = 0; //Protect against endless loop
    for (int i = 0; i < pfctrcnt; i++) { //This is the checking for zeros part
        int* tempcoefs = malloc(cnt * sizeof(int));
        int tcnt = cnt;
        if (!tempcoefs) {
            endless++;
            if (endless >= TOO_LONG) {
                printf("Endless loop! Terminating");
                return;
            }
            i--;
            continue;
        }
        int* tempmcoefs = malloc(cnt * sizeof(int));
        int mtcnt = cnt;
        if (!tempmcoefs) {
            endless++;
            if (endless >= TOO_LONG) {
                printf("Endless loop! Terminating");
                return;
            }
            free(tempcoefs);
            i--;
            continue;
        }
        memcpy(tempcoefs, coefs, sizeof(int) * cnt);
        memcpy(tempmcoefs, coefs, sizeof(int) * cnt);

        while (intSynthDiv(tempcoefs, tcnt, fctrs[i]) == 0) {
            struct zerostruc zer = {fctrs[i], 1};
            zeros[zcnt] = zer;
            zcnt++;
            tcnt--;
        }
        while (intSynthDiv(tempmcoefs, mtcnt, -fctrs[i]) == 0) {
            struct zerostruc mzer = {-fctrs[i], 1};
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
        for (int i = 0; i < pfctrcnt; i++) {
            for (int j = 1; j < qfctrcnt; j++) {
                if (GCF(fctrs[i], qfctrs[j]) == 1) {
                    double* tempcoefs = malloc(cnt * sizeof(double));
                    int tcnt = cnt;
                    if (!tempcoefs) {
                        endless++;
                        if (endless >= TOO_LONG) {
                            printf("Endless loop! Terminating");
                            return;
                        }
                        i--;
                        continue;
                    }
                    double* tempmcoefs = malloc(cnt * sizeof(double));
                    int mtcnt = cnt;
                    if (!tempmcoefs) {
                        endless++;
                        if (endless >= TOO_LONG) {
                            printf("Endless loop! Terminating");
                            return;
                        }
                        free(tempcoefs);
                        i--;
                        continue;
                    }
                    memcpy(tempcoefs, doubcoefs, sizeof(double) * cnt);
                    memcpy(tempmcoefs, doubcoefs, sizeof(double) * cnt);

                    while (DbZero( ratSynthDiv(tempcoefs, tcnt, (double)fctrs[i]/qfctrs[j]) )) {
                        struct zerostruc zer = {fctrs[i], qfctrs[j]};
                        zeros[zcnt] = zer;
                        zcnt++;
                        tcnt--;
                    }
                    while (DbZero( ratSynthDiv(tempmcoefs, mtcnt, -(double)fctrs[i]/qfctrs[j]) )) {
                        struct zerostruc mzer = {-fctrs[i], qfctrs[j]};
                        zeros[zcnt] = mzer;
                        zcnt++;
                        mtcnt--;
                    }
                    free(tempcoefs);
                    free(tempmcoefs);
                }
            }
        }
        free(qfctrs);
    }
    free(fctrs);
    
    if (zcnt + xtrap != cnt - 1 - xtraq) { //cnt-1 is the degree of the polynomial
        int tcnt = cnt;
        double* remain = malloc(sizeof(double) * tcnt);
        memcpy(remain, doubcoefs, sizeof(double) * tcnt);
        printf("The polynomial was not able to be fully factored. Only %d factors were found.\n", zcnt);
        if (coefs[0] < 0) printf("-");
        if (xtrap > 0) printf("x^%d", xtrap);
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].q == 1)
                printf("(x%+d)", -zeros[i].p);
            else
                printf("(%dx%+d)", zeros[i].q, -zeros[i].p);
        }
        for (int i = 0; i < zcnt; i++) { //Do the division of the known factors to find the remaining unfactorable part
            double* tempremain = synthdiv(remain, tcnt, 1, (double)zeros[i].p/zeros[i].q);
            if (!tempremain) {
                free(remain);
                free(doubcoefs);
                free(coefs);
                free(zeros);
                printf("\nMemory allocation failed during synthetic division. Returning early. Sorry!\n");
                return;
            }
            free(remain);
            remain = tempremain;
            tcnt--;
        }
        printf("(");
        for (int i = 0; i < tcnt; i++) {
            if (remain[i] == 1) printf("+x^%d", i);
            else if (remain[i] == -1) printf("-x^%d", i);
            else if (remain[i] != 0){
                printf("%+.15gx^%d", remain[i], tcnt - i - 1);
            }
        }
        printf(")\n");
        free(remain);
    }

    else {
        printf("The polynomial was fully factored.\n");
        if (coefs[0] < 0) printf("-");
        if (xtrap > 0) printf("x^%d", xtrap);
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].q == 1)
                printf("(x%+d)", -zeros[i].p);
            else
                printf("(%dx%+d)", zeros[i].q, -zeros[i].p);
        }
        printf("\nThe roots of the quadratic are:\n");
        for (int i = 0; i < zcnt; i++) {
            if (zeros[i].q == 1) printf("%d, ", zeros[i].p);
            else {
                int smp = GCF(zeros[i].q, zeros[i].p);
                if (zeros[i].q < 0) smp *= -1;
                printf("%d/%d, ", zeros[i].p/smp, zeros[i].q/smp);
            }
        }
    }
    free(doubcoefs);
    free(coefs);
    free(zeros);
}

