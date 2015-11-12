#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef _WIN32               // Sleeping (Pause) function
#include <Windows.h>        // For Windows
#else
#include <unistd.h>         // And linux
#endif
//inclusion of other .c files//
#include "DrawBoard.c"
#include "GenerateBoard.c"


int main()
{
srand(time(NULL));         // Generator of number of fishes
//Taking data from user//

    // initializations//
    int NumberOfRows,NumberOfColumns,NumberOfPenguins;
    int i,j,k; //iterators

printf("Enter NumberOfRows: \n");
scanf("%i", &NumberOfRows);
printf("Enter NumberOfColumns: \n");
scanf("%i", &NumberOfColumns);
printf("Enter NumberOfPenguins: \n");
scanf("%i", &NumberOfPenguins);
//Sleep(1000);

// grid generation //

typedef struct GridStruct{
    int NumberOfFishes;
    int IsPenguin;
} Cell;

struct GridStruct Map[NumberOfRows][NumberOfColumns];




//GenerateBoard - needs to be rewritten as function to GenerateBoard.c//

    for (i=0;i<NumberOfRows;i++) {
        for(j=0;j<NumberOfColumns;j++)
            {
                Map[i][j].NumberOfFishes=(rand()%3)+1;
            }
}

//PlacePenguin - needs to be rewritten as function to PlacePenguin.c//
k=0;
if (k != NumberOfPenguins){
    for (i=0;i<NumberOfRows;i++)
        for(j=0;j<NumberOfColumns;j++)
                if(Map[i][j].NumberOfFishes==1)
                    {
                        Map[i][j].IsPenguin=1;
                        k++;
                        if(k == NumberOfPenguins)
                            break;
                    }
                    if(k == NumberOfPenguins)
                            break;

//DrawBoard - needs to be rewritten as function to DrawBoard.c//

for (i=0;i<NumberOfRows;i++) {
if(i%2!=0) printf(" ");
        for(j=0;j<NumberOfColumns;j++)
        {
            if (Map[i][j].IsPenguin==1) printf("P");
            printf("%i ", Map[i][j].NumberOfFishes);
        }
printf("\n");
}

}
