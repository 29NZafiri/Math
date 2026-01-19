#include "AnaGeo.h"

dbfrac slpLn(dbPnt a, dbPnt b) {
    double y = b.y - a.y;
    double x = b.x - a.x;
    dbFracSmp(&y, &x);
    return (dbfrac){y, x};
}
