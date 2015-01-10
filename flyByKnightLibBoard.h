//
//FlyByKnightLibBoard.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Contains delcarations of all methods for board manipulation. 
//

#ifndef FLYBYKNIGHTLIBBOARD_H
#define FLYBYKNIGHTLIBBOARD_H
#include "flyByKnightLibDef.h"

//set all squares of board to bx00001110
void emptyBoard(PIECE_T board[STDBOARD]);
//place pieces in a standand new game configuration
void standardBoard(PIECE_T board[STDBOARD]);
//places new piece to specified postition on supplied board.  Returns contents of square repleaced.
PIECE_T placePiece(PIECE_T board[STDBOARD], PIECE_T * newPiece, POS_T * position); 

#endif
