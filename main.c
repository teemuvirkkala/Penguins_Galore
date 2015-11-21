#define MAX_LEN 128
#include "main.h"

void AsciiArtPrinter(FILE *fptr)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);

        printf("\n");
}

int main()
{
    //fun part start//
    /*PlaySound("resources/penguins.wav", NULL, SND_ASYNC); // Plays sound file; need to add winmm in Settings -> Compiler ->                                      //                                              ->Linker Settings
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
    Sleep(1000);*/
    //fun part end//


    // initializations//
    int NumberOfRows, NumberOfColumns, PengRows = 2; //PengRows should be the full amount of penguins in the future
    //Taking data from user//
    printf("\nEnter NumberOfRows: \n");
    scanf("%i", &NumberOfRows);
    printf("Enter NumberOfColumns: \n");
    scanf("%i", &NumberOfColumns);

    int FishArray[NumberOfRows][NumberOfColumns];
    int PengArray[PengRows][3]; /* Columns: playerID, x coord, y coord of penguin? So one row per penguin.
                                    PlayerID to check if the player is allowed to move the penguin */

    //Main loop should go here
    MapGenerator(NumberOfRows, NumberOfColumns, FishArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);

    PosPeng(NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);

    MovePengSE(1, 1, NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);

    MovePengE(2, 1, NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, PengRows, PengArray);

    exit(0);
}
