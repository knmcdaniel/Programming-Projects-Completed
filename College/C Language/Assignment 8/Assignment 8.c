#include <stdio.h>

void celsius_at_depth(int depth) {

   int celsius;

  celsius = (10 * depth) + 20;
  printf("Temperature at depth in C: %d\n", celsius);
}

void fahrenheit_at_depth(int depth) {

  int celsius;
  int fahrenheit;

  celsius = (10 * depth) + 20;
  fahrenheit = (1.8 * celsius) + 32;
  printf("Temperature at depth in F: %d\n", fahrenheit);

}

int main(void) {
int depth;

printf("Please enter a depth in Kilometers:");
scanf("%d", &depth);



celsius_at_depth(depth);
fahrenheit_at_depth(depth);


    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();


   return 0;
}
