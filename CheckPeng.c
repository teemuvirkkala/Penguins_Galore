#include "main.h"

//Returns 0 if there's a penguin in given coordinates and 1 if the space is free

int CheckPeng(int Row, int Col, int PengRows, int PengArray[PengRows][3]) {

    int i;

    for(i=0; i < PengRows; i++) {
        if(PengArray[i][1] == Row && PengArray[i][2] == Col) {
            return 0;
        }
    }
    return 1;
}

