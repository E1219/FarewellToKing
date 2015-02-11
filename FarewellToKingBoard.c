//
//FarewellToKingBoard.c
//FarewellToKing 0.0.2 - Chess Library
//Edward Sandor
//January 2015
//
//Contains implementation of all methods for board manipulation. 
//

#include "FarewellToKingBoard.h"

void emptyBoard(PIECE_T board [STDBOARD]){
    int i;

    for(i = 0; i < STDBOARD; i++){
        board[i] = EMPTY;
    }
    
    return;
}

void standardBoard(PIECE_T board [STDBOARD]){
    int i;
    for(i = A1; i < STDBOARD; i++){
        board[i] = EMPTY;
    }
    for(i = A2; i<=H2; i++){
        board[i]=PAWN|WHITE;    
    }
    for(i = A7; i<=H7; i++){
        board[i]=PAWN|BLACK;
    }
    
    board[A1] = ROOK   |WHITE;
    board[B1] = KNIGHT |WHITE;
    board[C1] = BISHOP |WHITE;
    board[D1] = QUEEN  |WHITE;
    board[E1] = KING   |WHITE;
    board[F1] = BISHOP |WHITE;
    board[G1] = KNIGHT |WHITE;
    board[H1] = ROOK   |WHITE;

    board[A8] = ROOK   |BLACK;
    board[B8] = KNIGHT |BLACK;
    board[C8] = BISHOP |BLACK;
    board[D8] = QUEEN  |BLACK;
    board[E8] = KING   |BLACK;
    board[F8] = BISHOP |BLACK;
    board[G8] = KNIGHT |BLACK;
    board[H8] = ROOK   |BLACK;

    return;
}

PIECE_T placePiece(PIECE_T board[STDBOARD], PIECE_T * newPiece, POS_T * position){
    PIECE_T old = board[*position];
    board[*position] =(* newPiece);

    return old;
}

