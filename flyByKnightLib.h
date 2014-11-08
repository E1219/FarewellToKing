//
//FlyByKnightLib.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014
//

#ifndef FLYBYKNIGHTLIB_H
#define FLYBYKNIGHTLIB_H
#include "flyByKnightLibDef.h"

//set all squares of board to bx00001110
void emptyBoard(PIECE_T board[STDBOARD]);
//place pieces in a standand new game configuration
void standardBoard(PIECE_T board[STDBOARD]);
//places new piece to specified postition on supplied board.  Returns contents of square repleaced.
PIECE_T placePiece(PIECE_T board[STDBOARD], PIECE_T * newPiece, POS_T * position); 
//returns 64 bit integer representing board positions occupied by a piece
MASK64 boardMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a white piece
MASK64 whiteMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a black piece
MASK64 blackMask(PIECE_T board[STDBOARD]);
//return PIECE_T array of formatted printout of board mask 
void printMask(MASK64 * mask, PIECE_T output[]);
//return PIECE_T array of formatted printout drawing board 
void printBoard(PIECE_T board[STDBOARD], char output[]);

//return mask with basic legal moves, no checks for revealed check, castle, or en pasant 
MASK64 moveMask(PIECE_T * piece, POS_T * position, MASK64 * boardM, MASK64 * opponentM);

#endif
