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
//    PlaySound("resources/penguins.wav", NULL, SND_ASYNC); // Plays sound file; need to add winmm in Settings -> Compiler ->                                      //                                              ->Linker Settings
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
    int NumberOfRows, NumberOfColumns, AllPengs = 2, i, p, PengID, Spaces, Dir, X, Y; //AllPengs should be the full amount of penguins in the future
    //Taking data from user//
    printf("\nEnter NumberOfRows: \n");
    scanf("%i", &NumberOfRows);
    NumberOfRows += 2;

    printf("Enter NumberOfColumns: \n");
    scanf("%i", &NumberOfColumns);
    NumberOfColumns += 2;

    int FishArray[NumberOfRows][NumberOfColumns]; //surrounded my 0 fishes floes
    MapCleaner(NumberOfRows, NumberOfColumns, FishArray);
    MapGenerator(NumberOfRows, NumberOfColumns, FishArray);

    int PengArray[AllPengs][3]; /* Columns: AllPengs, x coord, y coord of penguin? So one row per penguin.
                                    AllPengs to check if the player is allowed to move the penguin */
    MapCleaner(AllPengs, 3, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    //Main loop should go here
    //Manual loop//

    //Peng placing
    for (i=0;i<AllPengs;i++)
    {
        Enter:
        X=UserEnterCrdX(i);
        Y=UserEnterCrdY(i);
        if (PosPeng(X, Y, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)==1);
        else {printf("bad!\n");
        goto Enter;
        }
      DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    }
i=1;
    //Moving
  //  while(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray)==1){
    //Asking Player for PengID
    Move:
    if(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray)==0){
    PengID=UserEnterPengID(i);
    if (PengID%2==i%2){
        Spaces=UserEnterNumOfSpaces(i);
        Dir=UserEnterDir(i);
        switch(Dir){
                case 1:{
                    //go NW
                    printf("\nYou moved to NW");
                    MovePengNW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                }
                case 2:{
                    //go NE
                    printf("\nYou moved to NE");
                    MovePengNE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                }
                case 3:{
                    //go W
                    printf("\nYou moved to W");
                    MovePengW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                }
                case 4:{
                    // go E
                    printf("\nYou moved to E");
                    MovePengE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                }
                case 5:{
                    // go SW
                    printf("\nYou moved to SW");
                    MovePengSW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                }
                case 6:{
                    //go SE
                    printf("\nYou moved to SE");
                    MovePengSE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    break;
                default:{
                    printf("\nGive me the number one more time! ");
                }
            }
        }



    i++;
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
  goto Move;
    }



    }
else
printf("Game OVER!");

    //PosPeng2(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    //example moves
  /*  MovePengSE(1, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengSE(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengSW(1, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengSW(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengNW(1, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengNW(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengE(1, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

    MovePengW(2, 2, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
*/
    exit(0);
}
