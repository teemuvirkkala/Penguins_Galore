#include <stdio.h>
#include <stdlib.h>

int SaveBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    FILE *fp;
    int i, j;
    int fx;

    fp = fopen("test.map", "w");
    if(fp == NULL) {
        return 0;
    }
    fprintf(fp, "%d\ %d\n", NumOfRows, NumOfCols);

    for(i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            fx = FishArray[i][j];
            fprintf(fp, "%d ", fx);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 1;
}

int LoadBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {

    FILE *fp;
    int i, j;
    int buff;

    fp = fopen("test.map", "r");

    if(fp == NULL) {
        return 0;
    }

    fscanf (fp, "%d", &buff); //To skip over row and col, board starts from 3rd line
    fscanf (fp, "%d", &buff);

    for(i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            fscanf (fp, "%d", &buff);
            FishArray[i][j] = buff;
        }
    }

    fclose(fp);

    return 1;
}

int LoadRoC(int a) {

    FILE *fp;
    int output;

    fp = fopen("test.map", "r");

    if(fp == NULL) {
        return 0;
    }

    if(a == 1) { //To read number of rows
        fscanf (fp, "%d", &output);
    } else if(a == 2) { //To read the number of columns
        fscanf (fp, "%d", &output);
        fscanf (fp, "%d", &output);
    }

    fclose(fp);

    return output;
}


