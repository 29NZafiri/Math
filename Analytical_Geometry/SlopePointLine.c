#include "AnaGeo.h"

dbSys slpPntLn(double m, dbPnt a) {
    double c = a.y - m*a.x;
    return (dbSys){-m, 1, c};
}
