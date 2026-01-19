#include "AnaGeo.h"
#include "FloatMath.h"

irFrac dstPntLn(dbSys eq, dbPnt a) {
    dbSqrt num = {DbAbs(eq.x*a.x+eq.y*a.y-eq.c), eq.x*eq.x+eq.y*eq.y, "√"};
    double denom = eq.x*eq.x+eq.y*eq.y;
    return (irFrac){num, denom};
}
