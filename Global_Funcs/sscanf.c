#include "sscanf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "Alg.h"
#include "Constants.h"
#include "spsqrt.h"
#include "AnaGeo.h"
#include "Power.h"

void ssscanf(const char* type, void* p) {
    char num[BUFFER_SIZE];
    scanf("%99s", num);
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
    if (strcmp(type, "%b") == 0) {
        long res = strtol(num, NULL, 10);
        ((_Bool*)p)[0] = 0;
        if (res) ((_Bool*)p)[0] = 1;
    }
}

void printPower(int pow) {
    if (pow == 1) return;
    int cnt = 0;
    int tmp = pow;
    while (tmp > 0) {
        tmp /= 10;
        cnt++;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        switch (pow/power(10, i) % 10) {
            case 0:
                printf("\u2070");
                break;
            case 1:
                printf("\u00B9");
                break;
            case 2:
                printf("\u00B2");
                break;
            case 3:
                printf("\u00B3");
                break;
            case 4:
                printf("\u2074");
                break;
            case 5:
                printf("\u2075");
                break;
            case 6:
                printf("\u2076");
                break;
            case 7:
                printf("\u2077");
                break;
            case 8:
                printf("\u2078");
                break;
            case 9:
                printf("\u2079");
                break;
            default:
                break;
        }
    }
}

void spprintf(char* format, ...) {
    va_list args;
    unsigned long long length = strlen(format);
    va_start(args, format);
    for (unsigned long long i = 0; i < length; i++) {
        if (format[i] != '%') {
            printf("%c", format[i]);
            continue;
        }
        switch (format[i + 1]) {
            case 'd':
                printf("%d", va_arg(args, int));
                break;
            case 's':
                printf("%s", va_arg(args, char*));
                break;
            case 'g':
                printf("%.15g", va_arg(args, double));
                break;
            case 'r':
                printSqrt(va_arg(args, sqRoot));
                break;
            case 'R':
                printDbSqrt(va_arg(args, dbSqrt));
                break;
            case 'i':
                printComplex(va_arg(args, dbComplex));
                break;
            case 'p':
                printPoint(va_arg(args, dbPnt));
                break;
            case 'M':
                printDbMSurd(va_arg(args, dbMSurd));
            default:
                break;
        }
        i++;
    }
    va_end(args);
}
