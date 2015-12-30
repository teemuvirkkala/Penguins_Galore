#include "main.h"

int PlayGame(Pointer PointerX1, Pointer PointerY1, Pointer PointerDir1, Pointer PointerSpaces1, Pointer PointerPengID1, Pointer PointerX2, Pointer PointerY2, Pointer PointerDir2, Pointer PointerSpaces2, Pointer PointerPengID2) {

    // initializations//
    int NumberOfRows, NumberOfColumns, TempPengs, AllPengs, i, PengID, Spaces, Dir, X, Y, moved; //AllPengs should be the full amount of penguins in the future
    //Taking data from user//
    printf("Set board:");
    printf("\n1. Generate your own board");
    printf("\n2. Read board from file\n");
    scanf("%i", &i);

    switch(i) {
        case 1: {
            printf("\nEnter NumberOfRows: \n");
            scanf("%i", &NumberOfRows);
            NumberOfRows += 2;

            printf("Enter NumberOfColumns: \n");
            scanf("%i", &NumberOfColumns);
            NumberOfColumns += 2;

            printf("Enter of penguins for each player: \n");
            scanf("%i", &TempPengs);
            AllPengs=TempPengs*2;
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
    i = 0;
    //Peng placing
    while(i < AllPengs) {
        if(i % 2 == 0) {
            X = PointerX1(i);
            Y = PointerY1(i);
        } else if(i % 2) {
            X = PointerX2(i);
            Y = PointerY2(i);
        }

        if(PosPeng(X, Y, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray) == 1) {
            DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
            i++;
        } else {
            printf("You violated the rules! Try to place penguin again!\n");
        }
    }

    PrintCoords(AllPengs, PengArray);
    #ifdef TURNBYTURN_MODE
    TurnCounter(0);
    #endif
    i = 1;
    moved = 0;
    //Moving
    while(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray) == 0) {
        if(i % 2) {
            PengID = PointerPengID1(i);
        } else if(i % 2 == 0) {
            PengID = PointerPengID2(i);
        }

        if (PengID % 2 == i % 2) {
            if(i % 2) {
                Spaces = PointerSpaces1(i);
                Dir = PointerDir1(i);
            } else if(i % 2 == 0) {
                Spaces = PointerSpaces2(i);
                Dir = PointerDir2(i);
            }

            switch(Dir) {
                case 1: {
                        //go NE
                        if(MovePengNE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                            printf("\nYou moved to NE");
                            moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                case 2: {
                        //go E
                        if(MovePengE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                            printf("\nYou moved to E");
                            moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                case 3: {
                        //go SE
                        if(MovePengSE(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                           printf("\nYou moved to SE");
                           moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                case 4: {
                        // go SW
                        if(MovePengSW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                            printf("\nYou moved to SW");
                            moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                case 5: {
                        // go W
                        if(MovePengW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                            printf("\nYou moved to W");
                            moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                case 6: {
                        //go NW

                        if(MovePengNW(PengID, Spaces, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray)) {
                            printf("\nYou moved to NW");
                            moved = 1;
                        } else
                            printf("\nIllegal move!");
                        break;
                    }
                default: {
                        printf("\nGive me the number one more time! ");
                        break;
                    }
            }
        } else {
            printf("\nYou chose wrong penguin! Try again!");
        }
        Sleep(1000);
        DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
        PrintCoords(AllPengs, PengArray);
        if(moved == 1) {
            #ifdef TURNBYTURN_MODE
            TurnCounter(1);
            #endif
            i++;
            moved = 0;
        } else {
            #ifdef TURNBYTURN_MODE
            TurnCounter(0);
            #endif
        }

    }

    system ( "cls" );
    Score(AllPengs, 0, 1, 1, NumberOfColumns, FishArray, PengArray);
    printf("\nGame OVER!");
    exit(0);
}

