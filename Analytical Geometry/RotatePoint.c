#include "RotatePoint.h"

#include <math.h>
#include <stdio.h>

#include "Constants.h"
#include "sscanf.h"

void rtPnt() {
    double rx, ry, x, y, angle;
    printf("What is the X coordinate of the center of rotation (The stationary point)?\n");
    ssscanf("%lf", &rx);
    printf("What is the Y coordinate of the center of rotation (The stationary point)?\n");
    ssscanf("%lf", &ry);
    printf("What is the angle of rotation?\n");
    ssscanf("%lf", &angle);
    printf("What is the X coordinate of the point to rotate?\n");
    ssscanf("%lf", &x);
    printf("What is the Y coordinate of the point to rotate?\n");
    ssscanf("%lf", &y);
    x -= rx;    //Translate x so the rotation takes place about the origin
    y -= ry;    //Translate y so the rotation takes place about the origin
    double theta = atan2(y, x);     //Covert to Polar Coordinates
    if (theta < 0) theta += 2 * PI; //Correct atan2 to return [0, 2*pi)
    double r = sqrt(x*x + y*y);     //Covert to Polar Coordinates
    angle *= PI/180;     //Convert to radians
    theta = theta + angle;    //Adding the angles in polar coords gives the coords after rotation
    double fx = r*cos(theta) + rx;    //Convert to Cartesian Coordinates
    double fy = r*sin(theta) + ry;    //Convert to Cartesian Coordinates
    printf("The coordinates after the rotation are (%.15g,%.15g)\n", fx, fy);
}
