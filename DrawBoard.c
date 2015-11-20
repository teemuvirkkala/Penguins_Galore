#include "main.h"

void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;
    //system ( "cls" );

    for (i=0;i<NumOfRows;i++) {
        if(i%2!=0)
            printf(" ");
        for(j=0;j<NumOfCols;j++) {
            if(PengArray[PengRows-1][0] == 1 && PengArray[PengRows-1][1] == i && PengArray[PengRows-1][2] == j) //Check if the penguin is on these coordinates
                printf("P ");
            else
                printf("%i ", FishArray[i][j]); //If not just print the amount of fishes
        }
    printf("\n");
    }
    printf("\n\n");
    //getch();
}
