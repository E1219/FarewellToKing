/*
 farewell_to_king_board.c
 FarewellToKing - Chess Library
 Edward Sandor
 January 2015 - 2020
 
 Contains implementation of all methods for board manipulation. 
*/

#include "farewell_to_king_board.h"

void ftk_clear_board(ftk_board_s *board) {
  int i;

  for(i = 0; i < FTK_STD_BOARD_SIZE; i++){
      FTK_SQUARE_CLEAR(board->square[i]);
  }

  return;
}

void ftk_board_set_pawns(ftk_board_s *board)
{
  int i;

  for(i = FTK_A2; i <= FTK_H2; i++){
    FTK_SQUARE_SET(board->square[i], FTK_TYPE_PAWN, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);    
  }
  for(i = FTK_A7; i <= FTK_H7; i++){
    FTK_SQUARE_SET(board->square[i], FTK_TYPE_PAWN, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  }
  return;
}

void ftk_set_standard_board(ftk_board_s *board) {

  ftk_clear_board(board);

  ftk_board_set_pawns(board);

  FTK_SQUARE_SET(board->square[FTK_A1], FTK_TYPE_ROOK,   FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_B1], FTK_TYPE_KNIGHT, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_C1], FTK_TYPE_BISHOP, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_D1], FTK_TYPE_QUEEN,  FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_E1], FTK_TYPE_KING,   FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_F1], FTK_TYPE_BISHOP, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_G1], FTK_TYPE_KNIGHT, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_H1], FTK_TYPE_ROOK,   FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED);

  FTK_SQUARE_SET(board->square[FTK_A8], FTK_TYPE_ROOK,   FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_B8], FTK_TYPE_KNIGHT, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_C8], FTK_TYPE_BISHOP, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_D8], FTK_TYPE_QUEEN,  FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_E8], FTK_TYPE_KING,   FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_F8], FTK_TYPE_BISHOP, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_G8], FTK_TYPE_KNIGHT, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);
  FTK_SQUARE_SET(board->square[FTK_H8], FTK_TYPE_ROOK,   FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED);

  return;
}

ftk_square_s ftk_place_piece(ftk_board_s *board, ftk_square_s newPiece, ftk_position_t *position) 
{
  ftk_square_s old = board->square[*position];
  board->square[*position] = newPiece;

  return old;
}
