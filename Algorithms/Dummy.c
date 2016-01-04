#include "user.h"
#include <stdio.h>

int DummyCrdX(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, j, x;

    for(i = 1; i < NumOfRows - 1; i++) {
        for(j = 1; j < NumOfCols - 1; j++) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                x = i;
                return x;
            }
        }
    }
    return 0;
}

int DummyCrdY(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, j, y;

    for(i = 1; i < NumOfRows - 1; i++) {
        for(j = 1; j < NumOfCols - 1; j++) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                y = j;
                return y;
            }
        }
    }
    return 0;
}

int DummySpaces(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int s;

    printf("Enter number of spaces: \n");
    scanf("%i", &s);

    return s;
}

int DummyDir(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int d;

    printf("Enter direction of movement: \n");
    scanf("%i", &d);

    return d;
}

int DummyPengID(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int PID;

    printf("Enter which penguin you want to use: \n");
    scanf("%i", &PID);

    return PID;
}
