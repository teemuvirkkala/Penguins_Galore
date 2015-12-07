#include "main.h"

//System calls act as placeholders as they are slow.

void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i,j,k=0;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    #ifdef TURNBYTURN_MODE
    static int turn=1;
    system ( "cls" );
    #endif

    for (i=0; i < NumOfRows; i++) {
        if(i % 2 != 0)
            printf(" ");
            //SetConsoleTextAttribute(hConsole, 7);
        for(j=0; j < NumOfCols; j++) {
            if(CheckPeng(i, j, AllPengs, PengArray) == 0) { //Check if there's a penguin in given coordinates
                if(k%2==0){
                  SetConsoleTextAttribute(hConsole, 14);
                printf("P  ");
k++;
                }
                else{
                   SetConsoleTextAttribute(hConsole, 15);
                printf("P  ");
k++;
                }


                SetConsoleTextAttribute(hConsole, 7);
            } else if(FishArray[i][j]==0) {
                 printf("   ");
            } else {

                printf("%i  ", FishArray[i][j]); //If not just print the amount of fishes
            }
        }


    printf("\n\n");
    }
    printf("\n\n");

    #ifdef TURNBYTURN_MODE
    printf("Turn %d\n", turn);
    turn++;
    printf("Press any key to go to next turn\n");
    getch();
    #endif
}
