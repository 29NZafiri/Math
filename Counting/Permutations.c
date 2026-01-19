#include <Cnt.h>

unsigned long long int perms(int n, int k) {
    unsigned long long int perm = 1;
    for (unsigned long long int i = 0; i < k; i++)
        perm *= n-i;
    return perm;
}
