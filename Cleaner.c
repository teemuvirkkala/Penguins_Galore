#include "main.h"

void Cleaner(int iLimit, int jLimit, int Array[iLimit][jLimit]) {
    int i,j;

    for (i = 0; i < iLimit; i++) {
        for(j = 0; j < jLimit; j++) {
            Array[i][j] = 0;
        }
    }
}
