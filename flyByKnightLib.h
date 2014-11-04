#ifndef FLYBYKNIGHTLIB_H
#define FLYBYKNIGHTLIB_H
#include "flyByKnightLibDef.h"

//set all squares of board to bx00001110
void emptyBoard(char board[STDBOARD]);
//place pieces in a standand new game configuration
void standardBoard(char board[STDBOARD]);
//places new piece to specified postition on supplied board.  Returns contents of square repleaced.
char placePiece(char board[STDBOARD], char newPiece, char position); 
//returns 64 bit integer representing board positions occupied by a piece
MASK64 boardMask(char board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a white piece
MASK64 whiteMask(char board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a black piece
MASK64 blackMask(char board[STDBOARD]);
//return char array of formatted printout of board mask 
void printMask(long long int mask, char output[]);
//return char array of formatted printout drawing board 
void printBoard(char board[STDBOARD], char output[]);

#endif
