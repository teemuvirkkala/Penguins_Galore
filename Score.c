#include "main.h"

int Score(int AllPengs, int idRow, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int PengArray[][3]) {

    static int ScoreP1, ScoreP2;

    if(idRow % 2 == 0) {
        ScoreP1 += CheckBoard(Row, Col, NumOfCols, FishArray);
        return ScoreP1;
    }
    else {
        ScoreP2 += CheckBoard(Row, Col, NumOfCols, FishArray);
        return ScoreP2;
    }
}
