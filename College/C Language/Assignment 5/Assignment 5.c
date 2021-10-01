#include <stdio.h>

int main(void) {
    // Set Variables
    int invPiels;
    int invCoors;
    int invBud;
    int invIronCity;
    int invItem;
    int invAmount;

    //User inputs for original inventory
    printf("Welcome to the inventory management system.\n");
    printf("Please enter the inventory amount of each beer by the case.\n");
    printf("Piels:");
    scanf("%d", &invPiels);
    printf("Coors:");
    scanf("%d", &invCoors);
    printf("Bud:");
    scanf("%d", &invBud);
    printf("Iron City:");
    scanf("%d", &invIronCity);


    //User inputs for transactions
    printf("Please input transactions\n");
    printf("Reminder Inventory Numbers are as Follows: Piels = 1, Coors = 2, Bud = 3, IronCity = 4.\n");
    printf("Inventory Item:");
    scanf("%d", &invItem );
    printf("Inventory Amount:");
    scanf("%d", &invAmount);


    //While Loop checking to see if the user wants to exit the input part of the program. Entering a 0 will leave the program
    while (invItem != 0){
        if (invItem == 1) //If user inputs 1 add to Piels' inventory count
           invPiels = invPiels + invAmount;
        else if (invItem == 2) //If user inputs 2 add to Coors' inventory count
           invCoors = invCoors + invAmount;
        else if (invItem == 3) //If user inputs 3 add to Bud's inventory count
           invBud = invBud + invAmount;
        else if (invItem == 4) //If user inputs 4 add to Iron City's inventory count
           invIronCity = invIronCity + invAmount;

    //Getting more inputs while in the loop to allow the user to continuously adding/removing from the inventory
    printf("Please input transactions\n");
    printf("Reminder Inventory Numbers are as Follows: Piels = 1, Coors = 2, Bud = 3, IronCity = 4. To Exit input 0 as inventory item number.\n");
    printf("Inventory Item:");
    scanf("%d", &invItem );
    printf("Inventory Amount:");
    scanf("%d", &invAmount);
    }

    //prints the inventory out after the use exists the input section
    printf("Below is the inventory after this week's transactions.\n");
    printf("Piels: %d\n", invPiels);
    printf("Coors: %d\n", invCoors);
    printf("Bud: %d\n", invBud);
    printf("Iron City: %d\n", invIronCity);


    //Button press to close application notice
    printf("Press any button to close the program.");
    scanf("");


   return 0;
}
