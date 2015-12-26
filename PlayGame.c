#include "main.h"

int PlayGame(Pointer PointerX1, Pointer PointerY1, Pointer PointerDir1, Pointer PointerSpaces1, Pointer PointerPengID1, Pointer PointerX2, Pointer PointerY2, Pointer PointerDir2, Pointer PointerSpaces2, Pointer PointerPengID2)
{

    // initializations//
    int NumberOfRows, NumberOfColumns, AllPengs = 2, i, p, PengID, Spaces, Dir, X, Y; //AllPengs should be the full amount of penguins in the future
    //Taking data from user//
    printf("\nSet board:");
    printf("\n1. Generate your own board");
    printf("\n2. Read board from file");
    scanf("%i", &i);

    switch(i){
    case 1: {
     printf("\nEnter NumberOfRows: \n");
    scanf("%i", &NumberOfRows);
    NumberOfRows += 2;

    printf("Enter NumberOfColumns: \n");
    scanf("%i", &NumberOfColumns);
    NumberOfColumns += 2;

break;

    }
//case2


    }




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
    for(i=0;i+1<AllPengs;i++){
        Enter1:
        X=PointerX1(i);
        Y=PointerY1(i);
        if(PosPeng(X, Y, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)==1)
        DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
        else {
            printf("You violated the rules! Try to place penguin again!\n");
            goto Enter1;
        }
        Enter2:
        X=PointerX2(i+1);
        Y=PointerY2(i+1);
        if(PosPeng(X, Y, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)==1)
            DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
        else {
            printf("You violated the rules! Try to place penguin again!\n");
            goto Enter2;
        }
    }

i=1;
    //Moving







    Pass1:
    while(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray)==0)
    {
        Move1:
        PengID=PointerPengID1(i);
    if (PengID%2==i%2){
        Spaces=PointerSpaces1(i);
        Dir=PointerDir1(i);
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
    goto Pass2;
    }
    else {
        printf("You chose wrong penguin! Try again!");
        goto Move1;
    }
    }
    Pass2:
    while(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray)==0)
    {
        Move2:
        PengID=PointerPengID2(i);
    if (PengID%2==i%2){
        Spaces=PointerSpaces2(i);
        Dir=PointerDir2(i);
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
    goto Pass1;
    }
    else {
        printf("You chose wrong penguin! Try again!");
        goto Move2;
    }
    }

    system ( "cls" );
    Score(AllPengs, 0, 1, 1, NumberOfColumns, FishArray, PengArray);
    printf("\nGame OVER!");
    exit(0);
}

