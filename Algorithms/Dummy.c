#include "user.h"
#include <windows.h>
#include <string.h>
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
}

int DummySpaces(int i, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int s;

    if (i % 2 != 0) {
        SetConsoleTextAttribute(hConsole, 14);
        printf("Player1\n");
    } else {
        SetConsoleTextAttribute(hConsole, 12);
        printf("Player2\n");
    }

    printf("Enter number of spaces: \n");
    SetConsoleTextAttribute(hConsole, 7);
    scanf("%i", &s);
    return s;
}

int DummyDir(int i, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int d;

    if (i % 2 != 0) {
        SetConsoleTextAttribute(hConsole, 14);
        printf("Player1\n");
    } else {
        SetConsoleTextAttribute(hConsole, 12);
        printf("Player2\n");
    }

    printf("Enter direction of movement: \n");
    SetConsoleTextAttribute(hConsole, 7);
    scanf("%i", &d);
    return d;
}

int DummyPengID(int i, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int PID;

    if (i % 2 != 0) {
        SetConsoleTextAttribute(hConsole, 14);
        printf("Player1\n");
    } else {
        SetConsoleTextAttribute(hConsole, 12);
        printf("Player2\n");
    }

    printf("Enter which penguin you want to use: \n");
    SetConsoleTextAttribute(hConsole, 7);
    scanf("%i", &PID);
    return PID;
}
