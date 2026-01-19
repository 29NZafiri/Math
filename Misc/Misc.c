#include "Misc.h"
#include <stdio.h>
#include "GradeCalc.h"
#include "sscanf.h"

void misc(void) {
    int choice;
    printf("Calculate Grades (1)\n"
           "Which one?\n");
    ssscanf("%d", &choice);
    switch(choice) {
        case 1:
            GradeCalc();
            break;
        default:
            break;
    }
}
