//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014
//

#include <stdio.h>
#include "flyByKnightLib.h"

int main(){
    POS_T testSquare = D4;
    PIECE_T board[STDBOARD];

    emptyBoard(board);

    char output[256];

    PIECE_T p =  (NOTMOVED|ROOK|WHITE);

    placePiece(board, &p, &testSquare);
    //placePiece(board, SPARE|WHITE, G7);


    printBoard(board, output);
    printf("\n%s\n", output); 
    
    MASK64 boardM = boardMask(board);
    MASK64 opponentM = blackMask(board);
    MASK64 mask = moveMask(&board[testSquare], &testSquare,&boardM,&opponentM);

    POS_T target = A4;
    MASK64 whiteM = whiteMask(board);
    MASK64 path = pathMask(&p, &target, &testSquare, &mask, &whiteM);
    printMask(&path, output);
    printf("%s\n", output); 
    
    return 0;
}
