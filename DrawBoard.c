#include "main.h"

//System calls act as placeholders as they are slow.

void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i,j;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    #ifdef TURNBYTURN_MODE
    static int turn=1;
    system ( "cls" );
    #endif

    #ifdef DEBUG_MODE
    for (i = 0; i < NumOfRows; i++) {
    #else
    for (i = 1; i < NumOfRows - 1; i++) {
    #endif // DEBUG_MODE
        if(i % 2 != 0)
            printf(" ");
            //SetConsoleTextAttribute(hConsole, 7);
        #ifdef DEBUG_MODE
        for(j = 0; j < NumOfCols; j++) {
        #else
        for(j = 1; j < NumOfCols - 1; j++) {
        #endif // DEBUG_MODE
            if(CheckPeng(i, j, AllPengs, PengArray)) { //Check if there's a penguin in given coordinates
                if(CheckPeng(i, j, AllPengs, PengArray) % 2){
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("P  ");
                } else{
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("P  ");
                }
                SetConsoleTextAttribute(hConsole, 7);
            } else if(FishArray[i][j] == 0) {
                #ifdef DEBUG_MODE
                printf("0  ");
                #else
                printf("   ");
                #endif // DEBUG_MODE

            } else {

                printf("%i  ", FishArray[i][j]); //If not just print the amount of fishes
            }
        }
        printf("\n\n");
    }
    printf("\n\n");

//printf coords of pengs under map
int k;
        for(k = 0; k < AllPengs; k++) {
        if(PengArray[k][1]==0 && PengArray[k][2]==0) printf(" ");
        else if (k%2==0 && k==0) {                                  //workaround for printing coords of no. 0 peng.
        SetConsoleTextAttribute(hConsole, 14);
        printf("%i. [%i, %i]\n", k, PengArray[k][1], PengArray[k][2]);
        }
        else if (k%2==0 && k!=0) {
            SetConsoleTextAttribute(hConsole, 14);
            printf("%i. [%i, %i]\n", k, PengArray[k][1], PengArray[k][2]);
        }
        else if (k%2!=0 & k!=0) {SetConsoleTextAttribute(hConsole, 12);
            printf("\t\t%i. [%i, %i]\n", k, PengArray[k][1], PengArray[k][2]);
        }
    }

SetConsoleTextAttribute(hConsole, 7);

    #ifdef TURNBYTURN_MODE
    printf("Turn %d\n", turn);
    turn++;
    printf("Press any key to go to next turn\n");
    getch();
    #endif
}
