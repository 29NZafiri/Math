#include "RightCone.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "FloatMath.h"
#include "spsqrt.h"


void rghCone(void) {
    int solve;
    printf("Do you have the Slant Height(1), or the Cone Height(2)?");
    scanf("%d",&solve);
    double r, h, l;
    if (solve == 1) {
        printf("Please enter the radius\n");
        scanf("%lf", &r);
        printf("Please enter the Cone Height\n");
        scanf("%lf", &h);
        l = h*h+r*r;
    }
    if (solve == 2) {
        printf("Please enter the radius\n");
        scanf("%lf", &r);
        printf("Please enter the Slant Height\n");
        scanf("%lf", &l);
        h = sqrt(l*l-r*r);
    }
    if (solve == 1 || solve == 2){
        double Vol = r*r*h/3;
        char* LatArea = malloc(100*sizeof(char));
        char* TLatArea = malloc(100*sizeof(char));
        if (DbInt(l) && DbInt(r)) {
            char* RtArea = dbspsqrt(l);
            sprintf(LatArea, "%g\u03C0%s", r*r, RtArea);
            free(RtArea);
        }
        else {
            sprintf(LatArea, "%g\u03C1\u221a%.17g", r*r, l);
        }
        sprintf(TLatArea, "\u03C0%.17g", r*r*sqrt(l));
        double TTotArea = r*r+r*r*sqrt(l);
        char* TotArea = malloc(100 * sizeof(char));
        char* rtTot = dbspsqrt(l);
        sprintf(TotArea, "%.17g+\u03C0%.17g*%s", r*r, r*r, rtTot);
        if (solve == 1) printf("The Slant Height is %.17g", l);
        if (solve == 2) printf("The Cone Height is %.17g", h);
        printf("The Volume of the Cone is %.17g"
        "The Lateral Surface Area of the Cone is %s ~ %s"
        "The Total Surface Area of the Cone is %s ~ %.17g", Vol, LatArea, TLatArea, TotArea, TTotArea);
        free(TotArea);
        free(rtTot);
        free(LatArea);
        free(TLatArea);
    }
}