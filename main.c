#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef _WIN32               // Sleeping (Pause) function
#include <Windows.h>        // For Windows
#else
#include <unistd.h>         // And linux
#endif
//inclusion of other .c files//
//#include "DrawBoard.c"
//#include "MapGenerator.c"
//MapGenerator - needs to be rewritten as function to MapGenerator.c//
void MapGenerator(int FishArray, int NumberOfRows, int NumberOfColumns){
    srand(time(NULL));         // Generator of number of fishes
    int i,j;
    for (i=0;i<NumberOfRows;i++) {
        for(j=0;j<NumberOfColumns;j++)
            {
                FishArray[i][j]=(rand()%3)+1;
            }
}
}
//PlacePenguin - needs to be rewritten as function to PlacePenguin.c//


//MixedDrawBoard - needs to be rewritten as function to DrawBoard.c//
void DrawBoard(int FishArray, int NumberOfRows, int NumberOfColumns){
int i,j;
for (i=0;i<NumberOfRows;i++) {
if(i%2!=0) printf(" ");
        for(j=0;j<NumberOfColumns;j++)
        {
           printf("%i ", FishArray[i][j]);
        }
printf("\n");
}
}

int main()
{

//Taking data from user//

    // initializations//
    int NumberOfRows,NumberOfColumns,NumberOfPenguins;
    int FishArray[NumberOfRows][NumberOfColumns];
    char PenguinArray[NumberOfRows][NumberOfColumns];


printf("Enter NumberOfRows: \n");
scanf("%i", &NumberOfRows);
printf("Enter NumberOfColumns: \n");
scanf("%i", &NumberOfColumns);
printf("Enter NumberOfPenguins: \n");
scanf("%i", &NumberOfPenguins);
//Sleep(1000);

MapGenerator(FishArray, NumberOfRows, NumberOfColumns);
DrawBoard(FishArray, NumberOfRows, NumberOfColumns);
}


