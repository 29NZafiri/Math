#include "Geo.h"
#include "FloatMath.h"

char* pythInequal(double a, double b, double c) {
    double sides[3];
    if (a >= b && a >= c) {
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
    }
    else if (b >= a && b >= c) {
        sides[0] = b;
        sides[1] = a;
        sides[2] = c;
    }
    else if (c >= a && c >= b) {
        sides[0] = c;
        sides[1] = b;
        sides[2] = a;
    }
    if (sides[0] > sides[1] + sides[2])
        return "an impossible";
    if (DbEq(sides[0], sides[1] + sides[2]))
        return "a degenerate";
    if (a == b && b == c)
        return "an equilateral";
    if (DbEq(sides[0]*sides[0], sides[1]*sides[1] + sides[2]*sides[2]))
        return "a right";
    if (sides[0]*sides[0] > sides[1]*sides[1] + sides[2]*sides[2])
        return "an obtuse";
    if (sides[0]*sides[0] < sides[1]*sides[1] + sides[2]*sides[2])
        return "an acute";
    return "an error-prone";
}
