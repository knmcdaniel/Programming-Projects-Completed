#include <stdio.h>

int main(void) {

    FILE* inFile = NULL; // File pointer
    FILE* outFile = NULL; // File pointer
    // Set Variables
    int invPiels;
    int invCoors;
    int invBud;
    int invIronCity;
    int invItem;
    int invAmount;

    //User inputs for original inventory

     inFile = fopen("beerinput.txt", "r");
     if (inFile == NULL) {
      printf("Could not open file beerinput.txt.\n");
      return -1; // -1 indicates error
    }

    printf("Welcome to the inventory management system.\n");
    printf("Please wait while we scan the inventory sheet.\n");
    fscanf( inFile, "%d", &invPiels);
    fscanf( inFile, "%d", &invCoors);
    fscanf( inFile, "%d", &invBud);
    fscanf( inFile, "%d", &invIronCity);

    // After initial inventory continue pulling more inputs.
    fscanf( inFile,"%d", &invItem );
    fscanf( inFile,"%d", &invAmount);


    //While Loop to continuously input data until the invItem is -1
    while (invItem != -1){
        if (invItem == 1){ //If invItem is 1 add to Piels' inventory count
           invPiels += invAmount;
           printf("Updated %d of Peils to the inventory.\n", invAmount);
        }
        else if (invItem == 2){ //If invItem is 2 add to Coors' inventory count
           invCoors += invAmount;
           printf("Updated %d of Coors to the inventory.\n", invAmount);
        }
        else if (invItem == 3){ //If invItem is 3 add to Bud's inventory count
           invBud += invAmount;
           printf("Updated %d of Bud to the inventory.\n", invAmount);
        }
        else if (invItem == 4){ //If invItem is 4 add to Iron City's inventory count
           invIronCity += invAmount;
          printf("Updated %d of IronCity to the inventory.\n", invAmount);
        }

    //Getting more inputs while in the loop to allow the file to continuously adding/removing from the inventory
    fscanf( inFile, "%d", &invItem );
    fscanf( inFile, "%d", &invAmount);
    }

    //Close the file after the loop pulling in data.
    fclose(inFile);

    //prints the inventory out after the file is done being imported
    printf("Below is the inventory after the transactions.\n");
    printf("Piels: %d\n", invPiels);
    printf("Coors: %d\n", invCoors);
    printf("Bud: %d\n", invBud);
    printf("Iron City: %d\n", invIronCity);

    printf("Information saved to - beeroutput.txt");

    outFile = fopen("beeroutput.txt", "w");

    if (outFile == NULL) {
      printf("Could not open file beeroutput.txt.\n");
      return -1; // -1 indicates error
   }

    fprintf(outFile, "Below is the inventory after the transactions.\n");
    fprintf(outFile, "Piels: %d\n", invPiels);
    fprintf(outFile, "Coors: %d\n", invCoors);
    fprintf(outFile, "Bud: %d\n", invBud);
    fprintf(outFile, "Iron City: %d\n", invIronCity);

    fclose(outFile);

    //Button press to close application notice
    printf(" - Press any button to close the program.");
    getch();

   return 0;
}
