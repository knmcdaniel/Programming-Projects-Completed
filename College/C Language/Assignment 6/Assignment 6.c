#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 10;
   int userVals[NUM_ELEMENTS];
   int copiedVals[NUM_ELEMENTS];
   int i;
   int temp;
   int sorted;


   // Prompt user for input values and duplicate to second array
   printf("Enter %d integer values...\n", NUM_ELEMENTS);
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      printf("Value: ");
      scanf("%d", &(userVals[i]));
      copiedVals[i] =  userVals[i];
   }


    //infinite loop until sorted
   while(1){

    sorted = 0;

    for (i = 0; i < NUM_ELEMENTS-1; ++i) {
        if(copiedVals[i] < copiedVals[i+1]){
            int temp = copiedVals[i];
            copiedVals[i] = copiedVals[i+1];
            copiedVals[i+1] = temp;
            sorted = 1;
        }
    }

    if(sorted == 0){
        break;
    }

   }


   // Print numbers
   printf("\nUnsorted - Sorted\n");
   for (i = 0; i < NUM_ELEMENTS; ++i) {
        printf("%d      %d\n", userVals[i], copiedVals[i]);
    }

    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

   return 0;
}
