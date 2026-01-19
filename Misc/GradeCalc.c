#include "GradeCalc.h"
#include <stdio.h>

#include "sscanf.h"

void GradeCalc(void) {
    int weight_amount;
    double Res = 0;
    printf("How many parts do you have in your grading scale?\n");
    ssscanf("%d", &weight_amount);
    for (int i = 1; i <= weight_amount; i++) {
        double Question_correct = 0, Question_all = 0;
        double weight;
        printf("Enter Number %d on your grading scale.\n", i);
        ssscanf("%lf", &weight);
        int Amount;
        printf("How many assignments do you have that fall in this category?\n");
        ssscanf("%d", &Amount);
        for (int j = 1; j <= Amount; j++) {
            double Correct, Total;
            printf("How many correct do you have on assignment %d?\n", j);
            ssscanf("%lf", &Correct);
            Question_correct += Correct;
            printf("How many total points were you able to get on assignment %d?\n", j);
            ssscanf("%lf", &Total);
            Question_all += Total;
        }
        Res += Question_correct/Question_all * weight / 100;
    }
    printf("\nThe Grade Average is %.15g\n", Res * 100);
}
