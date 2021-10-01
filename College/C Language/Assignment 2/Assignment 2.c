#include <stdio.h>

int main(void) {
    // Set Variables
    double userNum1;        //Set as double for division
    double userNum2;        //Set as double for division
    int mathAdd;
    int mathSubtract;
    int mathMultiply;
    double mathDivide;      //Set as double for division

    // Get Numbers from Users
    printf("Enter your first number:");  //Statement asking for information
    scanf("%lf", &userNum1);             //Actually capturing the information from user
    printf("Enter your second number:");
    scanf("%lf", &userNum2);


    //Do Math
    mathAdd = userNum1 + userNum2;          //Adding
    mathSubtract = userNum1 - userNum2;     //Subtracting
    mathMultiply = userNum1 * userNum2;     //Multiplying
    mathDivide = userNum1 / userNum2;       //Dividing

    //Print Math results
    printf("Your numbers added together are %d\n", mathAdd);
    printf("Your numbers subtracted are %d\n", mathSubtract);
    printf("Your numbers multiplied together are %d\n", mathMultiply);
    printf("Your numbers divided together are %.2lf\n", mathDivide);


    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

   return 0;
}
