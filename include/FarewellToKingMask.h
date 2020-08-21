/*
 FarewellToKingMask.h
 Farewell To King - Chess Library
 Edward Sandor
 January 2015 - 2020
 
 Conatains declarations of all methods used to generate and manipulate board masks.
*/

#ifndef FAREWELLTOKINGMASK_H
#define FAREWELLTOKINGMASK_H
#include "farewell_to_king_types.h"

//returns 64 bit integer representing board positions occupied by a piece
ftk_board_mask_t boardMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a white piece
ftk_board_mask_t whiteMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a black piece
ftk_board_mask_t blackMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a pawn
ftk_board_mask_t pawnMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a knight
ftk_board_mask_t knightMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a bishop
ftk_board_mask_t bishopMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a rook 
ftk_board_mask_t rookMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a queen
ftk_board_mask_t queenMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a king
ftk_board_mask_t kingMask(PIECE_T board[STDBOARD]);
//returns 64 bit integer representing board positions occupied by a spare
ftk_board_mask_t spareMask(PIECE_T board[STDBOARD]);

//generates all masks representing the board in one iteration as opposed to separate iterations for each mask.  Replaces values of pointers:
//boardMask
//whiteMask
//blackMask
//pawnMask
//knightMask
//bishopMask
//rookMask
//queenMask
//kingMask
//spareMask
void superMask(PIECE_T board[STDBOARD], ftk_board_mask_t * boardMask, ftk_board_mask_t * whiteMask, ftk_board_mask_t * blackMask, ftk_board_mask_t * pawnMask, ftk_board_mask_t * knightMask, ftk_board_mask_t * bishopMask, ftk_board_mask_t * rookMask, ftk_board_mask_t * queenMask, ftk_board_mask_t * kingMask, ftk_board_mask_t * spareMask);

//returns mask with basic legal moves, no checks for revealed check, castle, or en pasant.
ftk_board_mask_t moveMask(PIECE_T * piece, POS_T * position, ftk_board_mask_t * boardM, ftk_board_mask_t * opponentM, POS_T * ep);

//returns mask describing a path to a specified square clear of pieces of the color of the piece moving.  
//PIECE_T piece:  the piece of interest
//POS_T   target: the destination square for piece of interest
//POS_T   source: the current square of the piece of interest
//ftk_board_mask_t  moves:  a mask describing possible moves of the piece of interest
ftk_board_mask_t pathMask(PIECE_T * piece, POS_T * target, POS_T * source, ftk_board_mask_t * moves);

//method strips moves from the move mask for any piece whose movment would result in exposed check
//PIECE_T board: array size of a standard board containing a description of each piece on each square 
//ftk_board_mask_t  moveM[STDBOARD]: an array for everyboard positions describing potential moves, will be modified by this method
CHECK_T stripCheck(PIECE_T board[STDBOARD], ftk_board_mask_t moveM[STDBOARD], ftk_board_mask_t * playerM, POS_T * kingPos); 

//method adds castling to move masks if castling is legal
//PIECE_T board: array of the board size that contains descriptons of each piece on each square
//ftk_board_mask_t  moveM[STDBOARD]: an array for everyboard positions describing potential moves, will be modified by this method
//ftk_board_mask_t * whiteM: a mask describing the position of all white pieces
//ftk_board_mask_t * blackM: a mask describing the position of all black pieces
//TURN_T * turn: descriptor of whose turn it is
void addCastle(PIECE_T board[STDBOARD], ftk_board_mask_t moveM[STDBOARD], ftk_board_mask_t * whiteM, ftk_board_mask_t * blackM, TURN_T * turn);

#endif
