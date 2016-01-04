#include "main.h"

int PlayGame(int P1ID, Pointer PointerX1, Pointer PointerY1, Pointer PointerDir1, Pointer PointerSpaces1, Pointer PointerPengID1, int P2ID, Pointer PointerX2, Pointer PointerY2, Pointer PointerDir2, Pointer PointerSpaces2, Pointer PointerPengID2) {

    // initializations//
    int NumberOfRows, NumberOfColumns, AllPengs = 0, i, PengID, Spaces, Dir, X, Y, moved, idRow, score1 = 0, score2 = 0; //AllPengs should be the full amount of penguins in the future
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
            break;
        }
        case 2: {
            NumberOfRows = LoadRoC(1);
            NumberOfColumns = LoadRoC(2);
            AllPengs = LoadRoC(3);
            TurnCounter(LoadRoC(4));
            score1 = LoadRoC(5);
            score2 = LoadRoC(6);
            break;
        }
        //case2
    }

    if(AllPengs == 0) {
        printf("Enter of penguins for each player: \n");
        scanf("%i", &AllPengs);
        AllPengs = AllPengs * 2;
    }

    int FishArray[NumberOfRows][NumberOfColumns]; //surrounded my 0 fishes floes
    int PengArray[AllPengs][3]; /* Columns: AllPengs, x coord, y coord of penguin? So one row per penguin.
                                AllPengs to check if the player is allowed to move the penguin */

    switch(i) {
        case 1: {
            MapCleaner(NumberOfRows, NumberOfColumns, FishArray);
            MapGenerator(NumberOfRows, NumberOfColumns, FishArray);
            break;
        }
        case 2: {
            LoadBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
            break;
        }
        //case2
    }

    if(score1 == 0 && score2 == 0) {
        MapCleaner(AllPengs, 3, PengArray);
        DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);

        //Main loop should go here
        //Manual loop//
        i = 0;
        //Peng placing
        while(i < AllPengs) {
            if(i % 2 == 0) {
                if(P1ID == 1) {
                    X = PointerX1(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                    Y = PointerY1(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                } else {
                    X = PointerX1(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    Y = PointerY1(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                }
            } else if(i % 2) {
                if(P2ID == 1) {
                    X = PointerX2(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                    Y = PointerY2(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                } else {
                    X = PointerX2(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                    Y = PointerY2(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                }
            }

            if(PosPeng(X, Y, NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray) == 1) {
                DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
                i++;
            } else {
                printf("You violated the rules! Try to place penguin again!\n");
                Sleep(1000);
                DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
            }
        }
    }

    DrawBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray);
    PrintCoords(score1, score2, AllPengs, PengArray);
    #ifdef TURNBYTURN_MODE
    printf("Turn %d\n", TurnCounter(-1));
    #endif
    i = TurnCounter(-1);
    moved = 0;
    //Moving
    while(CheckEnd(NumberOfColumns, FishArray, AllPengs, PengArray) == 0) {
        if(i % 2) {
            PengID = PointerPengID1(i, NumberOfColumns, FishArray, AllPengs, PengArray);
        } else if(i % 2 == 0) {
            PengID = PointerPengID2(i, NumberOfColumns, FishArray, AllPengs, PengArray);
        }

        if (PengID % 2 == i % 2) {
            if(i % 2) {
                Spaces = PointerSpaces1(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                Dir = PointerDir1(i, NumberOfColumns, FishArray, AllPengs, PengArray);
            } else if(i % 2 == 0) {
                Spaces = PointerSpaces2(i, NumberOfColumns, FishArray, AllPengs, PengArray);
                Dir = PointerDir2(i, NumberOfColumns, FishArray, AllPengs, PengArray);
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

        if(moved == 1) {
            #ifdef TURNBYTURN_MODE
            TurnCounter(0);
            #endif
            idRow = WhichPenguin(PengID, AllPengs, PengArray);
            if(i % 2) {
                score1 = Score(score1, PengArray[idRow][1], PengArray[idRow][2], NumberOfColumns, FishArray);
            } else if(i % 2 == 0) {
                score2 = Score(score2, PengArray[idRow][1], PengArray[idRow][2], NumberOfColumns, FishArray);
            }
            i++;
            moved = 0;
            SaveBoard(NumberOfRows, NumberOfColumns, FishArray, AllPengs, PengArray, score1, score2);
        }

        PrintCoords(score1, score2, AllPengs, PengArray);
        printf("Turn %d\n", TurnCounter(-1));
        printf("Press any key to go to next turn\n");
        getch();
    }

    system ( "cls" );
    if (score1 > score2)
        printf("Player1 won! with %i points!", score1);
    else if(score1 == score2)
        printf("It's a tie! Both players have %i points!", score1);
    else
        printf("Player2 won! with %i points!", score2);
    printf("\nGame OVER!");
    exit(0);
}

