//
//FlyByKnightLibMask.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Conatains declarations of all methods used to generate and manipulate board masks.
//

#ifndef FLYBYKNIGHTLIBMASK_H
#define FLYBYKNIGHTLIBMASK_H
#include "flyByKnightLibDef.h"

//returns 64 bit integer representing board positions occupied by a piece
MASK64 boardMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a white piece
MASK64 whiteMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a black piece
MASK64 blackMask(PIECE_T board[STDBOARD]);

//returns mask with basic legal moves, no checks for revealed check, castle, or en pasant.
MASK64 moveMask(PIECE_T * piece, POS_T * position, MASK64 * boardM, MASK64 * opponentM);

//returns mask describing a path to a specified square clear of pieces of the color of the piece moving.  
//PIECE_T piece:  the piece of interest
//POS_T   target: the destination square for piece of interest
//POS_T   source: the current square of the piece of interest
//MASK64  moves:  a mask describing possible moves of the piece of interest
MASK64 pathMask(PIECE_T * piece, POS_T * target, POS_T * source, MASK64 * moves);

//method strips moves from the move mask for any piece whose movment would result in exposed check
//PIECE_T board: array of the board size that contains a description of each piece on 
//MASK64  moveM[STDBOARD]: an array for everyboard positions describing potential moves, will be overwritten by this method
CHECK_T stripCheck(PIECE_T board[STDBOARD], MASK64 moveM[STDBOARD], MASK64 * playerM, POS_T * kingPos); 

#endif
