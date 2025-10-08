#include "sscanf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ssscanf(const char* type, void* p) {
    char num[100];
    scanf("%s", num);
    if (strcmp(type, "%d") == 0) {
        int res = (int)strtol(num, NULL, 10);
        ((int*)p)[0] = res;
    }
    if (strcmp(type, "%lf") == 0) {
        double res = strtod(num, NULL);
        ((double*)p)[0] = res;
    }
    if (strcmp(type, "%ld") == 0) {
        long res = strtol(num, NULL, 10);
        ((long*)p)[0] = res;
    }
}


