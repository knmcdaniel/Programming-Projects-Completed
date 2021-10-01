#include <stdio.h>

int main()
{
	float votes[5][4]={192,48,206,37,
					 147,90,312,21,
					 186,12,121,38,
					 114,21,480,39,
					 267,13,382,29};

	char cand[4]={'A','B','C','D'};


  char Winner;
  char firstLargestCan;
	char secondLargestCan;
	int row_totals[5];
	int col_totals[4];
	float total_votes;
  int i;
	float percent[4];
  float firstLargestPerc;
  float secondLargestPerc;


	int row,col;

	for(row=0;row<=4;row++)         //Calculates Row Totals
	{
		row_totals[row]=0;

		for(col=0;col<=3;col++)
		{
			row_totals[row] += votes[row][col];
		}
	}

  for(col=0;col<=3;col++)       //Calculates Column totals
	{
		col_totals[col]=0;

		for(row=0;row<=4;row++)
		{
			col_totals[col] += votes[row][col];
		}
	}

  printf("\n");
	printf("            Candidate   Candidate   Candidate   Candidate   Total\n");   //Print Beginning Chart with Votes and totals.
	printf(" Precinct       A           B           C           D       Votes\n");
	for(row=0;row<=4;row++)
	{
		printf("%6d",row+1);
		for(col=0;col<=3;col++)
		{
			printf("%12.f",votes[row][col]);
		}
		printf("%11.d\n",row_totals[row]);
	}

  printf("\n");



	printf("            Candidate   Candidate   Candidate   Candidate    Vote\n");      //Print Percentage Chart with winners noted per precinct
	printf(" Precinct       A           B           C           D      Winners\n");
	for(row=0;row<=4;row++)
	{
    firstLargestPerc = 0.0;
    secondLargestPerc = 0.0;
		printf("%6d",row+1);

		for(col=0;col<=3;col++)
		{
      percent[col]= (100*votes[row][col] / row_totals[row]);   //Does Math to get percent per row/column and sets it to percent[col]
			printf("%11.2f%%", percent[col]);

      if (percent[col] > firstLargestPerc){            //Designates the first and second largest percent/Candidate
             secondLargestPerc = firstLargestPerc;     //Assigns Second Largest Percent with the previous largest percent
             secondLargestCan = firstLargestCan;       //Assigns Second Largest Candidate with the previous largest Candidate
             firstLargestPerc = percent[col];          //Assings the Largest percent with the current percent
             firstLargestCan = cand[col];              //Assings the Largest candidate with the current Candidate
      }

      if (percent[col] > secondLargestPerc && percent[col] < firstLargestPerc){     //Checks if current percent is larger than second but smaller than first
            secondLargestPerc = percent[col];                                       //Assigns second largest percent with current percent
            secondLargestCan = cand[col];                                           //Assigns second largest candidate with current candidate
      }

    }

    if (50 > firstLargestPerc){       //Checks to see if First largest percent is above 50 to see if its a run-off or not
    printf("     Run-off Between Candidate %c %c \n", firstLargestCan, secondLargestCan);   //Prints Run-off candidates
    }
    else {
    printf("     Winner! Candidate %.c\n", firstLargestCan);      //Prints winning candidate
    }
  }



//Document the total vote count per candidate

total_votes = 0;
printf("\nThe Total Vote Count is:\n");
for(col=0;col<=3;col++){
  printf("Candidate %c : %d\n", cand[col], col_totals[col]);
  total_votes += col_totals[col];
}
printf("Total Votes : %.f\n", total_votes);


//Document the total vote percentage per candidate

printf("\nThe Total Vote Count in Percent is:\n");
for(col=0;col<=3;col++){
  percent[col] = (100*col_totals[col]/total_votes);
  printf("Candidate %c : %.2f%%\n", cand[col], percent[col]);
}

firstLargestPerc = 0.0;
secondLargestPerc = 0.0;


//Calculate the largest and second largest candidates based on percentage overall

for(col=0;col<=3;col++){
  if (percent[col] > firstLargestPerc){
      secondLargestPerc = firstLargestPerc;
      secondLargestCan = firstLargestCan;
      firstLargestPerc = percent[col];
      firstLargestCan = cand[col];
    }

  if (percent[col] > secondLargestPerc && percent[col] < firstLargestPerc){
      secondLargestPerc = percent[col];
      secondLargestCan = cand[col];
    }
}

//Print candidate based on percentage scale.

if (50 > firstLargestPerc){
    printf("Run-off Between Candidate %c %c \n", firstLargestCan, secondLargestCan);
    }
    else {
    printf("Winner! Candidate %.c\n", firstLargestCan);
    }


    //Button press to close application notice
    printf("Press any button to close the program.");
    getch();

	return 0;


}
