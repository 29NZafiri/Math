#include "AnaGeo.h"

dbPnt midLn(dbPnt a, dbPnt b) {
    double x = (a.x + b.x) / 2;
    double y = (a.y + b.y) / 2;
    return (dbPnt){x, y};
}