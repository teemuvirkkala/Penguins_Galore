#include "main.h"

void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    #ifdef TURNBYTURN_MODE
    static int turn=1;
    system ( "cls" );
    #endif

    for (i=0; i < NumOfRows; i++) {
        if(i % 2 != 0)
            printf(" ");
        for(j=0; j < NumOfCols; j++) {
            if(CheckPeng(i, j, PengRows, PengArray) == 0) { //Check if there's a penguin in given coordinates
                printf("P ");
            } else
                printf("%i ", FishArray[i][j]); //If not just print the amount of fishes
        }
    printf("\n");
    }
    printf("\n\n");

    #ifdef TURNBYTURN_MODE
    printf("Turn %d\n", turn);
    turn++;
    printf("Press any key to go to next turn\n");
    getch();
    #endif
}
