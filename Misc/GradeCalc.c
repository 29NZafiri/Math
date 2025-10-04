#include "GradeCalc.h"
#include <stdio.h>

void GradeCalc(void) {
    int weight_amount;
    double Res = 0;
    printf("How many parts do you have in your grading scale?\n");
    scanf("%d", &weight_amount);
    for (int i = 1; i <= weight_amount; i++) {
        double Question_correct = 0, Question_all = 0;
        double weight;
        printf("Enter Number %d on your grading scale.\n", i);
        scanf("%lf", &weight);
        int Amount;
        printf("How many assignments do you have that fall in this category?\n");
        scanf("%d", &Amount);
        for (int j = 1; j <= Amount; j++) {
            double Correct, Total;
            printf("How many correct do you have on assignment %d?\n", j);
            scanf("%lf", &Correct);
            Question_correct += Correct;
            printf("How many total points were you able to get on assignment %d?\n", j);
            scanf("%lf", &Total);
            Question_all += Total;
        }
        Res += Question_correct/Question_all * weight / 100;
    }
    printf("\nThe Grade Average is %.17g\n", Res * 100);
}
