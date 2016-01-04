#include "main.h"

int SaveBoard(int a, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3], int score1, int score2) {

    FILE *fp;
    int i, j;
    int fx;

    fp = fopen("test.map", "w");
    if(fp == NULL) {
        return 0;
    }
    fprintf(fp, "%d %d %d %d %d %d\n", NumOfRows, NumOfCols, AllPengs, a, score1, score2);

    for(i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            fx = FishArray[i][j];
            fprintf(fp, "%d ", fx);
        }
        fprintf(fp, "\n");
    }

    for(i = 0; i < AllPengs; i++) {
        for(j = 0; j < 3; j++) {
            fx = PengArray[i][j];
            fprintf(fp, "%d ", fx);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 1;
}

int LoadBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    FILE *fp;
    int i, j;
    int buff;

    fp = fopen("test.map", "r");

    if(fp == NULL) {
        return 0;
    }

    for(i = 0; i < 6; i++) { //To skip over the first line, board starts from 3rd line
        fscanf (fp, "%d", &buff);
    }

    for(i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            fscanf (fp, "%d", &buff);
            FishArray[i][j] = buff;
        }
    }

    if(AllPengs > 0) {
        for(i = 0; i < AllPengs; i++) {
            for(j = 0; j < 3; j++) {
                fscanf (fp, "%d", &buff);
                PengArray[i][j] = buff;
            }
        }
    }

    fclose(fp);

    return 1;
}

int LoadRoC(int a) {
    //1 rows, 2 cols, 3 penguins, 4 turn, 5 score1, 6 score2

    FILE *fp;
    int output, i;

    fp = fopen("test.map", "r");

    if(fp == NULL) {
        return 0;
    }

    for(i = 0; i < a; i++) {
        fscanf (fp, "%d", &output);
    }

    fclose(fp);

    return output;
}


