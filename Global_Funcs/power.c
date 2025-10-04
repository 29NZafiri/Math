#include "power.h"

int power(int x,int y) {
    int final = x;
    for (int i = 2; i <= y; i++) {
        final *= x;
    }
    return final;
}
