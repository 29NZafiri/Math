#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "Geometry/Geometry.h"
#include "Algebra/Algebra.h"
#include "Analytical Geometry/Graphing.h"
#include "Misc/Misc.h"
#include "Number Theory/NumThry.h"
#include "Stereometry/Stereometry.h"
#include "Counting/Counting.h"
#include "Testing/Test.h"

int main(int argc, char *argv[]) {
    int sub = 1;
    if (argc > 1) {
        if (strcmp(argv[1], "Y") == 0 || strcmp(argv[1], "y") == 0) {
            setlocale(LC_ALL, "en_US.UTF-8");
        }
    }
    else {
        printf("Set locale to UTF-8? (Recommended to do so) Y/N\n");
        int utf;
        scanf("%c", &utf);
        if (utf == 'Y' || utf == 'y') {
            printf("Setting Locale...\n");
            setlocale(LC_ALL, "en_US.UTF-8");
        }
    }
    while (sub != 0) {
        printf("\nWhat would you like to do?\n");
        printf("Geometry (1)\n"
            "Stereometry (2)\n"
            "Algebra (3)\n"
            "Analytical Geometry/Graphing (4)\n"
            "Number Theory (5)\n"
            "Counting (6)\n"
            "Misc (7)\n");
        printf("Which one? (0 when done)\n");
        scanf("%d", &sub);
        switch (sub) {
            case 1:
                Geometry();
                break;
            case 2:
                Stereometry();
                break;
            case 3:
                Algebra();
                break;
            case 4:
                anaGeo();
                break;
            case 5:
                NumThry();
                break;
            case 6:
                cnt();
                break;
            case 7:
                misc();
                break;
            case 8:
                test();
                break;
            default:
                #ifdef _WIN32
                    system("cls"); // For Windows
                #else
                    system("clear"); // For Linux/macOS
                #endif
        }
    }
    return 0;
}
