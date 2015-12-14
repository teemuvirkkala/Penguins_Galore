int Score (int AllPengs, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols]){

    int ScoreP1=0, ScoreP2=0;

    if(AllPengs%2==0) {ScoreP1+=CheckBoard(Row, Col, NumOfCols, FishArray);
    printf("\nNow Player1 has %i points.\n", ScoreP1);

    }
    else {ScoreP2+=CheckBoard(Row, Col, NumOfCols, FishArray);
printf("\nNow Player2 has %i points.\n", ScoreP2);

    }
}
