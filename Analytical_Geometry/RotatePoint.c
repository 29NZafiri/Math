#include <math.h>

#include "AnaGeo.h"
#include "Constants.h"

dbPnt rtPnt(dbPnt r, dbPnt a, double angle) {
    double x = a.x;
    double y = a.y;
    x -= r.x;    //Translate x so the rotation takes place about the origin
    y -= r.y;    //Translate y so the rotation takes place about the origin
    angle *= PI/180;     //Convert to radians
    double fx = x*cos(angle) - y*sin(angle);    //Application of the formula for rotating about the origin
    double fy = y*cos(angle) + x*sin(angle);    //Application of the formula for rotating about the origin
    fx += r.x;    //Translate x so that the rotated point is in the correct spot
    fy += r.y;    //Translate y so that the rotated point is in the correct spot
    return (dbPnt){fx, fy};
}

/* Original function. Less efficient, but more explicit
 * dbPnt rtPnt2(dbPnt r, dbPnt a, double angle) {
 *     double x = a.x;
 *     double y = a.y;
 *     x -= r.x;    //Translate x so the rotation takes place about the origin
 *     y -= r.y;    //Translate y so the rotation takes place about the origin
 *     double theta = atan2(y, x);     //Covert to Polar Coordinates
 *     double dist = sqrt(x*x + y*y);     //Covert to Polar Coordinates
 *     angle *= PI/180;     //Convert to radians
 *     theta = theta + angle;    //Adding the angles in polar coords gives the coords after rotation
 *     double fx = dist*cos(theta) + r.x;    //Convert to Cartesian Coordinates
 *     double fy = dist*sin(theta) + r.y;    //Convert to Cartesian Coordinates
 *     return (dbPnt){fx, fy};
 *     }
*/
