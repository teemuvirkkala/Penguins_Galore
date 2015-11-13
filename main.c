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

void MapGenerator(int NumbOfRws, int NumbOfCol, int FishArray[500][500]){
    srand(time(NULL));         // Generator of number of fishes
    int i,j;
    for (i=0;i<NumbOfRws;i++) {
        for(j=0;j<NumbOfCol;j++)
            {
                FishArray[i][j]=((rand()%3)+1);
            }
}
}
void DrawBoard(const int NumOfRows, int NumOfCol, int FishArray[500][500]){
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
PlaySound("penguins.wav", NULL, SND_ASYNC); // Plays sound file; need to add winmm in Settings -> Compiler ->
                                            //                                              ->Linker Settings

    // initializations//
    int NumberOfRows,NumberOfColumns;
  //Taking data from user//
printf("Enter NumberOfRows: \n");
scanf("%i", &NumberOfRows);
printf("Enter NumberOfColumns: \n");
scanf("%i", &NumberOfColumns);

    int FishArray[500][500];
    int i,j;
    for (i=0;i<100;i++) {
        for(j=0;j<100;j++)
            {
                FishArray[i][j]=0;
            }
    }
//Sleep(1000);

MapGenerator(NumberOfRows, NumberOfColumns, FishArray);
DrawBoard(NumberOfRows, NumberOfColumns, FishArray);
}


