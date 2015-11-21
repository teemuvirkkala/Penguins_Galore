#include "main.h"

/*Basic movement commands in order of NE,E,SE,SW,W,NW

-Currently only checking for Penguin ID and then move the Penguin for amount of Spaces
-Checking function needs to be implemented
-Amount of arguments? Do we need to pass FishArray for the check function?*/

void MovePengNE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows; j++) {
            if(PengArray[j][0] == ID) {
                if(PengArray[j][1] % 2)
                    (PengArray[j][2])++;
                (PengArray[j][1])--;
            }
        }
    }
}


void MovePengE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows ;j++) {
            if(PengArray[j][0] == ID) {
                (PengArray[j][2])++;
            }
        }
    }
}

void MovePengSE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows; j++) {
            if(PengArray[j][0] == ID) {
                if(PengArray[j][1] % 2)
                    (PengArray[j][2])++;
                (PengArray[j][1])++;
            }
        }
    }
}

void MovePengSW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows; j++) {
            if(PengArray[j][0] == ID) {
                if(PengArray[j][1] % 2 == 0)
                    (PengArray[j][2])--;
                (PengArray[j][1])++;
            }
        }
    }
}

void MovePengW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows; j++) {
            if(PengArray[j][0] == ID) {
                (PengArray[j][2])--;
            }
        }
    }
}

void MovePengNW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;

    for(i=0; i < Spaces; i++) {
        //We should always check step-by-step if the player can actually move
        for(j=0; j < PengRows; j++) {
            if(PengArray[j][0] == ID) {
                if(PengArray[j][1] % 2 == 0)
                    (PengArray[j][2])--;
                (PengArray[j][1])--;
            }
        }
    }
}
