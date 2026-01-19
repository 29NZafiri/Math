#include "FloatMath.h"
#include "../Constants.h"

float FlAbs(float x) {
    if (x < 0) return -x;
    return x;
}
double DbAbs(double x) {
    if (x < 0) return -x;
    return x;
}

_Bool DbInt(double a) {
    if (DbAbs(a - (int)a) > err) return 0;
    return 1;
}

_Bool FlInt(float a) {
    if (FlAbs(a - (int)a) > err) return 0;
    return 1;
}

_Bool DbZero(double a) {
    if (DbAbs(a) > err) return 0;
    return 1;
}

_Bool FlZero(float a) {
    if (FlAbs(a) > err) return 0;
    return 1;
}

_Bool FlEq(float a, float b) {
    if (FlAbs(a - b) > err) return 0;
    return 1;
}

_Bool DbEq(double a, double b) {
    if (DbAbs(a - b) > err) return 0;
    return 1;
}