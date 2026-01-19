#include "Alg.h"
#include "AnaGeo.h"

dbPnt syseq(const dbSys sys1, const dbSys sys2) {
    double a = sys1.x, b = sys1.y, c = sys1.c, d = sys2.x, e = sys2.y, f = sys2.c;
    double Y = (f*a-c*d)/(a*e-b*d);
    double X = (c-b*Y)/a;
    return (dbPnt){X, Y};
}
