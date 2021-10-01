#include <stdio.h>

int main(void) {
  typedef struct Element_Struct {
    char name[30];
    char symbol[3];
    char type[30];
    float number;
    float weight;
    int shell[7];
  } Element;

  Element userElement;
  int i;

  //Get User Inputs

  printf("Please enter information on your element\n");

  printf("Atomic Number:\n");
  scanf("%f", &userElement.number);

  printf("Name:\n");
  scanf("%s", &userElement.name[0]);

  printf("Symbol:\n");
  scanf("%s", &userElement.symbol[0]);

  printf("Class:\n");
  scanf("%s", &userElement.type[0]);

  printf("Atomic Weight:\n");
  scanf("%f", &userElement.weight);


  //Get User Inputs for Shell positioning

 printf("Enter the number of electrons in the designated shell\n");
  for (i = 0; i <= 6; ++i){
    printf("Shell %d:\n", i+1);
    scanf("%d",&userElement.shell[i]);
  }



//Print structure
printf("Atomic Number: %.f\n", userElement.number);
printf("Name: %s\n", userElement.name);
printf("Symbol: %s\n", userElement.symbol);
printf("Class: %s\n", userElement.type);
printf("Atomic Weight: %.4f\n", userElement.weight);
printf("Electrons in each shell: ");
for (i = 0; i <= 6; ++i){
   printf("%d ", userElement.shell[i]);
 }


     //Button press to close application notice
    printf("Press any button to close the program.");
    getch();


  return 0;
}
