#include <stdio.h>


int recursive(int x)
{
  if (x <= 0){
   return 0;
  }
  else{
    return recursive(x - 1) + 2;
  }
}

int main (void){

  int x;
  int y;

  printf ("\nEnter X: ");
  scanf ("%d", &x);

  y = recursive(x);

  printf ("\n%d\n", y);

      //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

  return 0;
}

