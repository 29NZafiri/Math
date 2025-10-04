#include "spsqrt.h"
#include "FloatMath.h"
#include <stdio.h>
#include <stdlib.h>

char* spsqrt(int x) {
    char* result = malloc(100 * sizeof(char));
    int i = 2;
    int gi = 0;
    int sp = 0;
    while (i*i <= x) {
        if (x % (i*i) == 0) {
            sp = x / (i*i);
            gi = i;
        }
        i++;
    }
    if (gi * gi == x) {
        sprintf(result, "%d", gi);
    } else if (gi != 0) {
        sprintf(result, "%d√%d", gi, sp);
    } else if (x == 1) {
        sprintf(result, "%d", x);
    } else {
        sprintf(result, "√%d", x);
    }
    return result;
}

char* dbspsqrt(double x) {
    char* result;
    if (DbInt(x)) {
        result = spsqrt((int)x);
    } else {
        char* res = malloc(100 * sizeof(char));
        sprintf(res, "√%.17g", x);
        result = res;
    }
    return result;
}

int rspsqrt(int x) {
    int i = 2;
    int sp = 0;
    while (i*i <= x) {
        if (x % (i*i) == 0) {
            sp = x / (i*i);
        }
        i++;
    }
    if (sp != 0) {
        return sp;
    }
    return 1;
}

int ispsqrt(int x) {
    int i = 2;
    int gi = 0;
    while (i*i <= x) {
        if (x % (i*i) == 0) {
            gi = i;
        }
        i++;
    }
    if (gi != 0) {
        return gi;
    }
    return x;

}

