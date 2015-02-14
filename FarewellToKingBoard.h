//
//FarewellToKingBoard.h
//FarewellToKing 0.0.2 - Chess Library
//Edward Sandor
//January 2015
//
//Contains delcarations of all methods for board manipulation. 
//

#ifndef FAREWELLTOKINGBOARD_H
#define FAREWELLTOKINGBOARD_H
#include "FarewellToKingDef.h"

//set all squares of board to bx00001110
void emptyBoard(PIECE_T board[STDBOARD]);
//place pieces in a standand new game configuration
void standardBoard(PIECE_T board[STDBOARD]);
//places new piece to specified postition on supplied board.  Returns contents of square repleaced.
PIECE_T placePiece(PIECE_T board[STDBOARD], PIECE_T * newPiece, POS_T * position); 

#endif
