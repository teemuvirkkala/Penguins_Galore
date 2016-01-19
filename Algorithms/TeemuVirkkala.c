#include "user.h"
#include <stdio.h>

int TeemuCrdX(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, j, x, centerx;
    centerx = NumOfRows / 2;

    for(i = centerx; i < NumOfRows - 1; i++) {
        for(j = NumOfCols / 2; j < NumOfCols - 1; j++) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                x = i;
                return x;
            }
        }
        for(j = NumOfCols / 2; j > 0; j++) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                x = i;
                return x;
            }
        }
    }
    return 0;
}

int TeemuCrdY(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, j, y, centerx, centery;
    centerx = NumOfRows / 2;
    centery = NumOfCols / 2;

    for(i = centerx; i < NumOfRows - 1; i++) {
        for(j = centery; j < NumOfCols - 1; j++) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                y = j;
                return y;
            }
        }
        for(j = centery; j > 0; j--) {
            if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                y = j;
                return y;
            }
        }
    }
    return 0;
}

int TeemuSpaces(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int sp;
    sp = 1;
    return sp;
}

int TeemuDir(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, d, idRow;
    static int turn = 0;
    idRow = WhichPenguin(PID, AllPengs, PengArray);

    if (turn == 0) {
        turn = 1;
        if(a % 2) {
            if(CheckMove(idRow, 2, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 2;
            } else if(CheckMove(idRow, 3, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 3;
            } else if(CheckMove(idRow, 4, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 4;
            } else if(CheckMove(idRow, 5, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 5;
            } else if(CheckMove(idRow, 6, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 6;
            } else if(CheckMove(idRow, 1, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 1;
            } else {
                for(i = 2; i <= 6; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
                return 1;
            }
        } else {
            if(CheckMove(idRow, 2, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 2;
            } else if(CheckMove(idRow, 3, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 3;
            } else if(CheckMove(idRow, 4, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 4;
            } else if(CheckMove(idRow, 5, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 5;
            } else if(CheckMove(idRow, 6, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 6;
            } else if(CheckMove(idRow, 1, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 1;
            } else {
                for(i = 2; i <= 6; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
                return 1;
            }
        }
    } else {
        turn = 0;
        if(a % 2) {
            if(CheckMove(idRow, 5, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 5;
            } else if(CheckMove(idRow, 6, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 6;
            } else if(CheckMove(idRow, 1, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 1;
            } else if(CheckMove(idRow, 2, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 2;
            } else if(CheckMove(idRow, 3, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 3;
            } else if(CheckMove(idRow, 4, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 4;
            } else {
                for(i = 5; i <= 6; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
                for(i = 1; i <= 4; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
            }
        } else {
            if(CheckMove(idRow, 5, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 5;
            } else if(CheckMove(idRow, 6, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 6;
            } else if(CheckMove(idRow, 1, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]-1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 1;
            } else if(CheckMove(idRow, 2, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1], PengArray[idRow][2]+1, NumOfCols, FishArray) == 2)) {
                d = 2;
            } else if(CheckMove(idRow, 3, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2], NumOfCols, FishArray) == 2)) {
                d = 3;
            } else if(CheckMove(idRow, 4, s, NumOfCols, FishArray, AllPengs, PengArray) && (CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 3 || CheckBoard(PengArray[idRow][1]+1, PengArray[idRow][2]-1, NumOfCols, FishArray) == 2)) {
                d = 4;
            } else {
                for(i = 5; i <= 6; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
                for(i = 1; i <= 4; i++) {
                    if(CheckMove(idRow, i, s, NumOfCols, FishArray, AllPengs, PengArray))
                        return i;
                }
            }
        }
    }

    return d;
}

int TeemuPengID(int s, int PID, int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, j;
    static int turn = 0;

    if(a % 2) {
        if(AllPengs == 2) {
            return 1;
        }
        for(i = turn; i < AllPengs; i++) {
            if(i % 2 == 0) {
                for(j = 1; j <= 6; j++) {
                    if(CheckMove(i, j, 1, NumOfCols, FishArray, AllPengs, PengArray)) {
                        if(turn == 0)
                            turn = 2;
                        else
                            turn = 0;
                        return ++i;
                    }
                }
            }
        }
        for(i = turn; i > -1; i--) {
            if(i % 2 == 0) {
                for(j = 1; j <= 6; j++) {
                    if(CheckMove(i, j, 1, NumOfCols, FishArray, AllPengs, PengArray)) {
                        if(turn == 0)
                            turn = 2;
                        else
                            turn = 0;
                        return ++i;
                    }
                }
            }
        }
    }else if(a % 2 == 0) {
        if(AllPengs == 2) {
            return 2;
        }
        for(i = turn; i < AllPengs; i++) {
            if(i % 2) {
                for(j = 1; j <= 6; j++) {
                    if(CheckMove(i, j, 1, NumOfCols, FishArray, AllPengs, PengArray)) {
                        if(turn == 0)
                            turn = 2;
                        else
                            turn = 0;
                        return ++i;
                    }
                }
            }
        }
        for(i = turn; i > -1; i--) {
            if(i % 2) {
                for(j = 1; j <= 6; j++) {
                    if(CheckMove(i, j, 1, NumOfCols, FishArray, AllPengs, PengArray)) {
                        if(turn == 0)
                            turn = 2;
                        else
                            turn = 0;
                        return ++i;
                    }
                }
            }
        }
    }
    return 0;
}
