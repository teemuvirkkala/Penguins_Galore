#include "main.h"

int Score(int score, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols]) {

    score += CheckBoard(Row, Col, NumOfCols, FishArray);
    return score;
}
