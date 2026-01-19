#include "AnaGeo.h"
#include "FloatMath.h"

dbSqrt lnLength(dbPnt a, dbPnt b) {
    double dist = (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
    if (DbInt(dist)) {
        dbSqrt ret;
        sqRoot rt = spsqrt((int)dist);
        ret.irr = (double)rt.irr;
        ret.rat = (double)rt.rat;
        ret.rad = rt.rad;
        return ret;
    }
    return (dbSqrt){1, dist, "√"};
}
