#include "Factorial.h"

long long int factorial(int x) {
    if (x <= 0) return 1;
    int ans = 1;
    for (int i = 2; i <= x; i++) {
        ans *= i;
    }
    return ans;
}