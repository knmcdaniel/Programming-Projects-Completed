#include <stdio.h>

int main(void) {
    // Set Variables
    char userColor[50];
    char firstLetter;

    //User inputs
    printf("Please enter the  first character of the color for the cylinder:\n");
    scanf("%s", &userColor);


    //Getting the first letter
    firstLetter = userColor[0];

    //Print information based on letter
    if ((firstLetter == 'o') || (firstLetter == 'O')){
        printf("The cylinder contains ammonia.\n");
    }
    else if ((firstLetter == 'b') || (firstLetter == 'B')){
        printf("The cylinder contains carbon monoxide.\n");
    }
    else if ((firstLetter == 'y') || (firstLetter == 'Y')){
        printf("The cylinder contains hydrogen.\n");
    }
    else if((firstLetter == 'g') || (firstLetter == 'G')){
        printf("The cylinder contains oxygen.\n");
    }
    else {
        printf("The color is not recognized.\n");
    }

    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

   return 0;
}
