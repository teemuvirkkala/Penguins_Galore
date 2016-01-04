#include <windows.h>
#include <string.h>
#include <stdio.h>

int UserEnterCrdX(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int x;

    printf("Enter row of your penguin: \n");
    scanf("%i", &x);

    return x;
}

int UserEnterCrdY(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int y;

    printf("Enter column of your penguin: \n");
    scanf("%i", &y);

    return y;
}

int UserEnterNumOfSpaces(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int s;

    printf("Enter number of spaces: \n");
    scanf("%i", &s);
    return s;
}

int UserEnterDir(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int d;

    printf("Enter direction of movement: \n");
    scanf("%i", &d);

    return d;
}

int UserEnterPengID(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int PID;

    printf("Enter which penguin you want to use: \n");
    scanf("%i", &PID);

    return PID;
}
