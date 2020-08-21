/*
 farewell_to_king.h
 FarewellToKing - Chess Library
 Edward Sandor
 November 2014 - 2020
 
 Contains delcarations of all methods for general game manipulation. 
*/

#ifndef FAREWELLTOKING_H
#define FAREWELLTOKING_H
#include "farewell_to_king_types.h"
#include "FarewellToKingBoard.h"
#include "FarewellToKingMask.h"

//initializes values of Game structure, game, for a standard game of chess 
void beginStandardGame(Game * game);
//call to update all game masks in the proper order after setup, moving piece, or board modification.
void updateMasks(Game * game);

//call to move piece
//Game * game: game to manipulate
//POS_T * target: the square to move to
//POS_T * source: the square to move from
//Move: returns move structure describing changes made to game
Move movePiece(Game * game, POS_T * target, POS_T * source);

//move backward based on move structure
//Game * game: game to manipulate
//Move * move: description of move to be reveresed.
char moveBackward(Game * game, Move * move);

#endif
