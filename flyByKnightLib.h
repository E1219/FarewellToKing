//
//FlyByKnightLib.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014 - 2015
//

#ifndef FLYBYKNIGHTLIB_H
#define FLYBYKNIGHTLIB_H
#include "flyByKnightLibDef.h"

typedef struct Game_s{
   PIECE_T board[STDBOARD]; 
   POS_T wKing;
   POS_T bKing;
   MASK64 boardM;
   MASK64 whiteM;
   MASK64 blackM;
   MASK64 moveM[STDBOARD];
   TURN_T turn; 
}Game;

//initializes values of Game structure, game, for a standard game of chess 
void beginStandardGame(Game * game);
//call to update all game masks in the proper order after setup, moving piece, or board modification.
void updateMasks(Game * game);
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
