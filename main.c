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
    int NumberOfRows, NumberOfColumns, AllPengs = 4; //AllPengs should be the full amount of penguins in the future
    //Taking data from user//
    printf("\nEnter NumberOfRows: \n");
    scanf("%i", &NumberOfRows);
    int SurrNumberOfRows=NumberOfRows+2;
    printf("Enter NumberOfColumns: \n");
    scanf("%i", &NumberOfColumns);
    int SurrNumberOfColumns=NumberOfColumns+2;
    int FishArray[SurrNumberOfRows][SurrNumberOfColumns]; //surrounded my 0 fishes floes
    MapCleaner(SurrNumberOfRows, SurrNumberOfColumns, FishArray);
    MapGenerator(NumberOfRows, NumberOfColumns, FishArray);

    int PengArray[AllPengs][3]; /* Columns: AllPengs, x coord, y coord of penguin? So one row per penguin.
                                    AllPengs to check if the player is allowed to move the penguin */
    InitArray(AllPengs, 3, PengArray);
    //Main loop should go here

    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    PosPeng2(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    //example moves
    MovePengSE(1, 1, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengSE(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengE(1, 1, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengW(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengNE(1, 1, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengNW(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    exit(0);
}
