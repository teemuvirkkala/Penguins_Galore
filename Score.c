#include "main.h"

int Score (int AllPengs, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int PengArray[AllPengs][3]){

    int ScoreP1=1, ScoreP2=1;

if(CheckEnd(NumOfCols, FishArray, AllPengs, PengArray)==0){

    if(AllPengs%2==0) {ScoreP1+=CheckBoard(Row, Col, NumOfCols, FishArray);
    printf("\nNow Player1 has %i points.\n", ScoreP1);

    }
    else {ScoreP2+=CheckBoard(Row, Col, NumOfCols, FishArray);
printf("\nNow Player2 has %i points.\n", ScoreP2);

    }
}
else{
    if (ScoreP1>ScoreP2) {
            printf("Player1 won! with %i points!", ScoreP1);
    }
    else if(ScoreP1==ScoreP2) printf("It's a tie! Both players have %i points!", ScoreP1);
    else printf("Player1 won! with %i points!", ScoreP1);

}
}
