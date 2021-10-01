#include <stdio.h>

int main(void) {
    // Set Variables
    int userWeight;
    int userHeight;
    int userBMI;

    //User inputs
    printf("Please enter your weight:\n");
    scanf("%d", &userWeight);
    printf("Please enter your height in inches:\n");
    scanf("%d", &userHeight);

    //Calculating BMI
    userBMI = ((703 * userWeight) / (pow(userHeight, 2)));

    //Print BMI
    printf("Your BMI is:%d\n", userBMI);

    //Print category based on BMI
    if (userBMI > 30){
        printf("You are Obese.\n");
    }
    else if (userBMI > 25){
        printf("You are Overweight.\n");
    }
    else if (userBMI > 18.5){
        printf("You are Normal.\n");
    }
    else {
        printf("You are Underweight.\n");
    }

    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

   return 0;
}
