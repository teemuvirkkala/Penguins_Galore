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
//#include "MapGenerator.c
void MapGenerator(int NumbOfRws, int NumbOfCol, int FishArray){
    srand(time(NULL));         // Generator of number of fishes
    int i,j;
    for (i=0;i<NumbOfRws;i++) {
        for(j=0;j<NumbOfCol;j++)
            {
                FishArray[i][j]=(rand()%3)+1;
            }
}
}
void DrawBoard(const int NumOfRows, int NumOfCol, int FishArray){
int i,j;
for (i=0;i<NumOfRows;i++) {
if(i%2!=0) printf(" ");
        for(j=0;j<NumOfCol;j++)
        {
           printf("%i ", FishArray[i][j]);
        }
printf("\n");
}
}

int main()
{
    // initializations//
    int NumberOfRows,NumberOfColumns;
  //Taking data from user//
printf("Enter NumberOfRows: \n");
scanf("%i", &NumberOfRows);
printf("Enter NumberOfColumns: \n");
scanf("%i", &NumberOfColumns);

    int FishArray[NumberOfRows][NumberOfColumns];


//Sleep(1000);

MapGenerator(NumberOfRows, NumberOfColumns, FishArray);
DrawBoard(NumberOfRows, NumberOfColumns, FishArray);
}


