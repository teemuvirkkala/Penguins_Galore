#include "user.h"
#include <stdio.h>

int DummyCrdX(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

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

int DummyCrdY(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

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

int DummySpaces(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int sp;
    sp = 1;
    return sp;
}

int DummyDir(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int d, idRow;
    idRow = WhichPenguin(PID, AllPengs, PengArray);

    if(CheckMove(idRow, 2, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 2;
    } else if(CheckMove(idRow, 3, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 3;
    } else if(CheckMove(idRow, 4, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 4;
    } else if(CheckMove(idRow, 5, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 5;
    } else if(CheckMove(idRow, 6, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 6;
    } else if(CheckMove(idRow, 1, s, NumOfCols, FishArray, AllPengs, PengArray)) {
        d = 1;
    }

    return d;
}

int DummyPengID(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int PengID;

    if(a % 2) {
        PengID = 1;
    }else if(a % 2 == 0) {
        PengID = 2;
    }

    return PengID;
}
