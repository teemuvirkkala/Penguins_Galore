#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif
#define MAX_LEN 128 // for art drawing
//inclusion of other .c files//
//#include "DrawBoard.c"
//#include "MapGenerator.c


void AsciiArtPrinter(FILE *fptr)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);

        printf("\n");
}


void MapGenerator(int NumbOfRws, int NumbOfCol, int FishArray[NumbOfRws][NumbOfCol]){
    srand(time(NULL));         // Generator of number of fishes
    int i,j;
    for (i=0;i<NumbOfRws;i++) {
        for(j=0;j<NumbOfCol;j++)
            {
                FishArray[i][j]=((rand()%3)+1);
            }
}
}
void DrawBoard(const int NumOfRows, int NumOfCol, int FishArray[NumOfRows][NumOfCol]){
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
    //fun part start//
PlaySound("resources/penguins.wav", NULL, SND_ASYNC); // Plays sound file; need to add winmm in Settings -> Compiler ->                                      //                                              ->Linker Settings
char *filename = "resources/penguinsgalore.txt";
    FILE *fptr = NULL;
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
    AsciiArtPrinter(fptr);
    fclose(fptr);
    Sleep(1000);
    char *filename2 = "resources/peng.txt";
    FILE *fptr2 = NULL;
    if((fptr2 = fopen(filename2,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
    AsciiArtPrinter(fptr2);
    fclose(fptr2);
Sleep(1000);
//fun part end//


    // initializations//
    int NumberOfRows,NumberOfColumns;
  //Taking data from user//
printf("\nEnter NumberOfRows: \n");
scanf("%i", &NumberOfRows);
printf("Enter NumberOfColumns: \n");
scanf("%i", &NumberOfColumns);

    int FishArray[NumberOfRows][NumberOfColumns];
    int i,j;
    for (i=0;i<100;i++) {
        for(j=0;j<100;j++)
            {
                FishArray[i][j]=0;
            }
    }


MapGenerator(NumberOfRows, NumberOfColumns, FishArray);
DrawBoard(NumberOfRows, NumberOfColumns, FishArray);
}
