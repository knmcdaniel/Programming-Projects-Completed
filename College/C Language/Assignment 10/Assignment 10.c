#include <stdio.h>

//Give the user info about the program
void printExplanation(){
  printf("Enter the amount you want to withdrawal\n");
  printf("Note: withdrawal amount must be in quantities of 10\n");
}

//Verify the use input a number that is divisible by 10
int verifyMultiple(int money){
  int multipleCheck;

  multipleCheck = money % 10;

  if (multipleCheck == 0) {
    return 1;
    printf("%d", multipleCheck);
  }
  else{
    return 3;
  }

}

//Pass pointers to do math and find the amount of bills needed
void atmTransaction(int userInput, int * fFifty, int * fTwenty, int * fTen) {

  *fFifty = userInput / 50;
  *fTwenty = (userInput % 50) / 20;
  *fTen = ((userInput % 50) % 20) / 10;

}

//Print the transaction totals for each bill
void printTransaction(int money, int fifty, int twenty,int  ten){
  printf("Your withdrawal is:\n");
  printf("Fifties: %d\n", fifty);
  printf("Twenties: %d\n", twenty);
  printf("Tens: %d\n", ten);
  printf("Your total withdrawal is: $%d \n", money);
  printf("Thank you for choosing this ATM!\n");

}

int main(void) {
  int money;
  int fifty;
  int twenty;
  int ten;


  printExplanation();  //print explanation

  scanf("%d", &money); //get initial input



  while (verifyMultiple(money) != 1) { //Loop if input is not a multiple of 10
     printf("Input not a quantity of 10, please use another amount.\n");
     scanf("%d", &money);
   }

  atmTransaction(money, &fifty, &twenty, &ten); //Do math

  printTransaction(money, fifty, twenty, ten); //Print Results

      //Button press to close application notice
    printf("Press any button to close the program.");
    getch();


}
