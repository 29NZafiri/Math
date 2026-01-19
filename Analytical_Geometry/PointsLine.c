#include "AnaGeo.h"
#include "FloatMath.h"

dbSys pntsLn(dbPnt a, dbPnt b) {
    double y = b.y - a.y;
    double x = b.x - a.x;
    dbFracSmp(&y, &x);
    double c = (x*a.y-y*a.x)/x;
    if (DbInt(y)) return (dbSys){0, 1, a.y}; //b.y would also work
    if (DbInt(x)) return (dbSys){1, 0, a.x}; //b.x would also work
    return (dbSys){-x, 1, c};
}
