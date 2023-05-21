/*
 farewell_to_king_mask.c
 Farewell To King - Chess Library
 Edward Sandor
 January 2015 - 2020
 
 Contains implementation of all methods used to generate and manipulate board masks.
*/

#include <stdlib.h>

#include "farewell_to_king_bitops.h"
#include "farewell_to_king_mask.h"
#include "farewell_to_king_types.h"

ftk_board_mask_t ftk_build_type_mask(const ftk_board_s *board, ftk_type_e type) 
{
  ftk_board_mask_t mask = 0;

  int i;
  ftk_board_mask_t biterator = 1ULL;

  for (i = 0; i < FTK_STD_BOARD_SIZE; i++) {
    if (board->square[i].type == type) {
      mask = mask | biterator;
    }
    biterator = (biterator << 1);
  }

  return mask;
}

ftk_board_mask_t ftk_build_color_mask(const ftk_board_s *board, ftk_color_e color) 
{
  ftk_board_mask_t mask = 0;

  int i;
  ftk_board_mask_t biterator = 1ULL;

  for (i = 0; i < FTK_STD_BOARD_SIZE; i++) {
    if (board->square[i].color == color) {
      mask = mask | biterator;
    }
    biterator = (biterator << 1);
  }

  return mask;
}

ftk_board_mask_t ftk_build_board_mask(const ftk_board_s *board) {
  ftk_board_mask_t mask = 0;

  int i;
  ftk_board_mask_t biterator = 1ULL;
  for (i = 0; i < FTK_STD_BOARD_SIZE; i++) {
    if (board->square[i].type != FTK_TYPE_EMPTY) {
      mask = mask | biterator;
    }
    biterator = (biterator << 1);
  }

  return mask;
}

void ftk_build_all_masks(ftk_board_s *board)
{
  board->board_mask = 0;
  board->white_mask = 0;
  board->black_mask = 0;
  board->pawn_mask = 0;
  board->knight_mask = 0;
  board->bishop_mask = 0;
  board->rook_mask = 0;
  board->queen_mask = 0;
  board->king_mask = 0;

  int i;
  ftk_board_mask_t biterator = 1ULL;
  for(i=0;i<FTK_STD_BOARD_SIZE;i++)
  {
    if(board->square[i].type != FTK_TYPE_EMPTY)
    {
      board->board_mask |= biterator;
      if(board->square[i].color == FTK_COLOR_WHITE)
      {
        board->white_mask |= biterator;
      }
      else
      {
        board->black_mask |= biterator;
      }
      switch(board->square[i].type){
        case FTK_TYPE_PAWN:
          board->pawn_mask   |= biterator;
          break;
        case FTK_TYPE_KNIGHT:
          board->knight_mask |= biterator;
          break;
        case FTK_TYPE_BISHOP:
          board->bishop_mask |= biterator;
          break;
        case FTK_TYPE_ROOK:
          board->rook_mask   |= biterator;
          break;
        case FTK_TYPE_QUEEN:
          board->queen_mask  |= biterator;
          break;
        case FTK_TYPE_KING:
          board->king_mask   |= biterator;
          break;
        default:
            break;
      }
    }
    biterator = biterator << 1;
  }
}

static const ftk_board_mask_t white_pawn_capture_mask[FTK_STD_BOARD_SIZE] = 
{
  0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 
  0x0000000000020000, 0x0000000000050000, 0x00000000000a0000, 0x0000000000140000, 0x0000000000280000, 0x0000000000500000, 0x0000000000a00000, 0x0000000000400000, 
  0x0000000002000000, 0x0000000005000000, 0x000000000a000000, 0x0000000014000000, 0x0000000028000000, 0x0000000050000000, 0x00000000a0000000, 0x0000000040000000, 
  0x0000000200000000, 0x0000000500000000, 0x0000000a00000000, 0x0000001400000000, 0x0000002800000000, 0x0000005000000000, 0x000000a000000000, 0x0000004000000000, 
  0x0000020000000000, 0x0000050000000000, 0x00000a0000000000, 0x0000140000000000, 0x0000280000000000, 0x0000500000000000, 0x0000a00000000000, 0x0000400000000000, 
  0x0002000000000000, 0x0005000000000000, 0x000a000000000000, 0x0014000000000000, 0x0028000000000000, 0x0050000000000000, 0x00a0000000000000, 0x0040000000000000, 
  0x0200000000000000, 0x0500000000000000, 0x0a00000000000000, 0x1400000000000000, 0x2800000000000000, 0x5000000000000000, 0xa000000000000000, 0x4000000000000000, 
  0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 
};

static const ftk_board_mask_t black_pawn_capture_mask[FTK_STD_BOARD_SIZE] = 
{
  0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 
  0x0000000000000002, 0x0000000000000005, 0x000000000000000a, 0x0000000000000014, 0x0000000000000028, 0x0000000000000050, 0x00000000000000a0, 0x0000000000000040, 
  0x0000000000000200, 0x0000000000000500, 0x0000000000000a00, 0x0000000000001400, 0x0000000000002800, 0x0000000000005000, 0x000000000000a000, 0x0000000000004000, 
  0x0000000000020000, 0x0000000000050000, 0x00000000000a0000, 0x0000000000140000, 0x0000000000280000, 0x0000000000500000, 0x0000000000a00000, 0x0000000000400000, 
  0x0000000002000000, 0x0000000005000000, 0x000000000a000000, 0x0000000014000000, 0x0000000028000000, 0x0000000050000000, 0x00000000a0000000, 0x0000000040000000, 
  0x0000000200000000, 0x0000000500000000, 0x0000000a00000000, 0x0000001400000000, 0x0000002800000000, 0x0000005000000000, 0x000000a000000000, 0x0000004000000000, 
  0x0000020000000000, 0x0000050000000000, 0x00000a0000000000, 0x0000140000000000, 0x0000280000000000, 0x0000500000000000, 0x0000a00000000000, 0x0000400000000000, 
  0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 
};

static const ftk_board_mask_t knight_move_mask[FTK_STD_BOARD_SIZE] = 
{
  0x0000000000020400, 0x0000000000050800, 0x00000000000a1100, 0x0000000000142200, 0x0000000000284400, 0x0000000000508800, 0x0000000000a01000, 0x0000000000402000, 
  0x0000000002040004, 0x0000000005080008, 0x000000000a110011, 0x0000000014220022, 0x0000000028440044, 0x0000000050880088, 0x00000000a0100010, 0x0000000040200020, 
  0x0000000204000402, 0x0000000508000805, 0x0000000a1100110a, 0x0000001422002214, 0x0000002844004428, 0x0000005088008850, 0x000000a0100010a0, 0x0000004020002040, 
  0x0000020400040200, 0x0000050800080500, 0x00000a1100110a00, 0x0000142200221400, 0x0000284400442800, 0x0000508800885000, 0x0000a0100010a000, 0x0000402000204000, 
  0x0002040004020000, 0x0005080008050000, 0x000a1100110a0000, 0x0014220022140000, 0x0028440044280000, 0x0050880088500000, 0x00a0100010a00000, 0x0040200020400000, 
  0x0204000402000000, 0x0508000805000000, 0x0a1100110a000000, 0x1422002214000000, 0x2844004428000000, 0x5088008850000000, 0xa0100010a0000000, 0x4020002040000000, 
  0x0400040200000000, 0x0800080500000000, 0x1100110a00000000, 0x2200221400000000, 0x4400442800000000, 0x8800885000000000, 0x100010a000000000, 0x2000204000000000, 
  0x0004020000000000, 0x0008050000000000, 0x00110a0000000000, 0x0022140000000000, 0x0044280000000000, 0x0088500000000000, 0x0010a00000000000, 0x0020400000000000, 
};

static const ftk_board_mask_t king_move_mask[FTK_STD_BOARD_SIZE] = 
{
  0x0000000000000302, 0x0000000000000705, 0x0000000000000e0a, 0x0000000000001c14, 0x0000000000003828, 0x0000000000007050, 0x000000000000e0a0, 0x000000000000c040, 
  0x0000000000030203, 0x0000000000070507, 0x00000000000e0a0e, 0x00000000001c141c, 0x0000000000382838, 0x0000000000705070, 0x0000000000e0a0e0, 0x0000000000c040c0, 
  0x0000000003020300, 0x0000000007050700, 0x000000000e0a0e00, 0x000000001c141c00, 0x0000000038283800, 0x0000000070507000, 0x00000000e0a0e000, 0x00000000c040c000, 
  0x0000000302030000, 0x0000000705070000, 0x0000000e0a0e0000, 0x0000001c141c0000, 0x0000003828380000, 0x0000007050700000, 0x000000e0a0e00000, 0x000000c040c00000, 
  0x0000030203000000, 0x0000070507000000, 0x00000e0a0e000000, 0x00001c141c000000, 0x0000382838000000, 0x0000705070000000, 0x0000e0a0e0000000, 0x0000c040c0000000, 
  0x0003020300000000, 0x0007050700000000, 0x000e0a0e00000000, 0x001c141c00000000, 0x0038283800000000, 0x0070507000000000, 0x00e0a0e000000000, 0x00c040c000000000, 
  0x0302030000000000, 0x0705070000000000, 0x0e0a0e0000000000, 0x1c141c0000000000, 0x3828380000000000, 0x7050700000000000, 0xe0a0e00000000000, 0xc040c00000000000, 
  0x0203000000000000, 0x0507000000000000, 0x0a0e000000000000, 0x141c000000000000, 0x2838000000000000, 0x5070000000000000, 0xa0e0000000000000, 0x40c0000000000000, 
};

static inline ftk_board_mask_t ftk_build_move_mask_raw(ftk_square_s square, ftk_board_mask_t board_mask, ftk_board_mask_t opponent_mask, ftk_square_e position, ftk_square_e *ep)
{
  ftk_board_mask_t mask = 0;

  if (square.type == FTK_TYPE_PAWN) 
  {
    int direction = (square.color == FTK_COLOR_WHITE)
                        ? 1
                        : -1;             // change direction based on color
    int test = position + (direction << 3); // forward/back 1

    if (test < FTK_STD_BOARD_SIZE && test >= 0 &&
        ((board_mask & 1ULL << test) == 0)) {
      mask |= (1ULL << test);

      test = position + (direction << 4); // forward/back 2

      if ((square.moved == FTK_MOVED_NOT_MOVED) && test < FTK_STD_BOARD_SIZE &&
          test >= 0 && ((board_mask & 1ULL << test) == 0)) {
        mask |= (1ULL << test);
      }
    }

    const ftk_board_mask_t capture_mask = (square.color == FTK_COLOR_WHITE)?white_pawn_capture_mask[position]:black_pawn_capture_mask[position];
    mask |= (capture_mask & (opponent_mask | FTK_POSITION_TO_MASK(*ep)));
  } 
  else if (square.type == FTK_TYPE_KNIGHT) 
  {
    mask |= (knight_move_mask[position] & ((~board_mask) | opponent_mask));
  } 
  else if (square.type == FTK_TYPE_KING)
  {
    mask |= (king_move_mask[position] & ((~board_mask) | opponent_mask));
  }
  else if ( (square.type == FTK_TYPE_BISHOP) ||
            (square.type == FTK_TYPE_ROOK)   ||
            (square.type == FTK_TYPE_QUEEN) )
  {
    const ftk_board_mask_t movable_mask = ((~board_mask) | opponent_mask);
    if (square.type != FTK_TYPE_ROOK) 
    {
      int test = position + 9; // up-right diagonal
      ftk_board_mask_t test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) > (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test += 9;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position - 9; // down-left diagonal
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) < (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test -= 9;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position + 7; // up-left diagonal
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) < (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test += 7;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position - 7; // down-right diagonal
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) > (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test -= 7;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
    }
    if (square.type != FTK_TYPE_BISHOP) {
      int test = position + 1; // right horizontal
      ftk_board_mask_t test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) > (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test += 1;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position - 1; // left horizontal
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             (test % 8) < (position % 8) &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test -= 1;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position + 8; // up vertical
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test += 8;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
      test = position - 8; // down vertical
      test_mask = FTK_POSITION_TO_MASK(test);
      while (test < FTK_STD_BOARD_SIZE && test >= 0 &&
             ((test_mask & movable_mask) != 0))
      {
        mask |= test_mask;
        if ((board_mask & test_mask) != 0)
          break;
        test -= 8;
        test_mask = FTK_POSITION_TO_MASK(test);
      }
    }
  }

  return mask;
}
ftk_board_mask_t ftk_build_move_mask(const ftk_board_s *board, ftk_square_e position, ftk_square_e *ep)
{
  ftk_square_s     square        = board->square[position];
  ftk_board_mask_t opponent_mask = (FTK_COLOR_WHITE == square.color) ? board->black_mask : board->white_mask;

  return ftk_build_move_mask_raw(square, board->board_mask, opponent_mask, position, ep);
}

ftk_board_mask_t ftk_build_path_mask(ftk_square_s square, ftk_square_e target, ftk_square_e source, ftk_board_mask_t moves) 
{
  ftk_board_mask_t mask = 0;

  if ((moves & (1ULL << target)) != 0) 
  {
    switch (square.type) 
    {
      case FTK_TYPE_PAWN:
      {
        if ((target - source) == 16) 
        {
          mask = ((1ULL << target) | (1ULL << (target - 8)));
        } 
        else if ((source - target) == 16) 
        {
          mask = ((1ULL << target) | (1ULL << (target + 8)));
        } 
        else 
        {
          mask = (1ULL << target);
        }
        break;
      }
      case FTK_TYPE_KNIGHT:
      case FTK_TYPE_KING:
      {
        mask = (1ULL << target);
        break;
      }
      case FTK_TYPE_BISHOP:
      case FTK_TYPE_ROOK:
      case FTK_TYPE_QUEEN:
      {
        if (((target/8) != (source/8)) &&
            ((target%8) != (source%8)) &&
            (abs(target - source) % 9 == 0))
        {
          /* Same diagonal (up/right or down/left) */
          char i;
          for (i = target; i > source; i = i - 9)
            mask |= (1ULL << i);

          for (i = target; i < source; i = i + 9)
            mask |= (1ULL << i);
        } 
        if (((target/8) != (source/8)) &&
            ((target%8) != (source%8)) &&
            (abs(target - source) % 7 == 0))
        {
          /* Same diagonal (up/left or down/right) */
          char i;
          for (i = target; i > source; i = i - 7)
            mask |= (1ULL << i);

          for (i = target; i < source; i = i + 7)
            mask |= (1ULL << i);
        } 
        if ((target%8) == (source%8))
        {
          /* Same file */
          char i;
          for (i = target; i > source; i = i - 8)
            mask |= (1ULL << i);
          for (i = target; i < source; i = i + 8)
            mask |= (1ULL << i);
        } 
        if((target/8) == (source/8))
        {
          /* Same rank */
          char i;
          for (i = target; i > source; i = i - 1)
            mask |= (1ULL << i);

          for (i = target; i < source; i = i + 1)
            mask |= (1ULL << i);
        }
        break;
      }
      default:
      {
        break;
      }
    }
  }

  return mask;
}

ftk_check_e ftk_strip_check(ftk_board_s *board, ftk_color_e turn)
{
  ftk_check_e check = FTK_CHECK_NO_CHECK;
  ftk_square_e   i,j;
  ftk_square_e   ep;
  ftk_board_mask_t temp_mask;
  ftk_board_mask_t path;
  ftk_board_mask_t cross;
  ftk_board_mask_t turn_mask = (FTK_COLOR_WHITE == turn) ? board->white_mask : board->black_mask;
  ftk_board_mask_t opponent_mask = (FTK_COLOR_WHITE == turn) ? board->black_mask : board->white_mask;
  ftk_board_mask_t move_mask_no_opponent;
  ftk_board_mask_t king_moves_temp;
  ftk_square_e   protecting;
  ftk_square_e   king_position;
  ftk_square_e   move_under_test;
  int              pawn_direction, pawn_test_square;
  ftk_board_s      board_copy;
  king_position = ftk_mask_to_position(board->king_mask & turn_mask);

  /* Remove moves cause check or do not resolve check */
  for (i = 0; i < FTK_STD_BOARD_SIZE; i++) 
  {
    /* Walk through moves of the entire board */
    if(board->square[i].type != FTK_TYPE_EMPTY && board->square[i].color != turn)
    {
      /* Remove squares that enter check from King's move mask */
      if(FTK_TYPE_PAWN == board->square[i].type)
      {
        /* Ignore forward moves for Pawns as they can only capture diagonally */
        temp_mask = 0;

        pawn_direction = (board->square[i].color == FTK_COLOR_WHITE) ? 1 : -1; // change direction based on color

        pawn_test_square= i + pawn_direction * 9; // capture up-right/down-left diagonal
        if (pawn_test_square< FTK_STD_BOARD_SIZE && pawn_test_square>= 0 &&
            (1 == abs((pawn_test_square/8) - (i/8)))) 
        {
          temp_mask |= (1ULL << pawn_test_square);
        }
        pawn_test_square= i + pawn_direction * 7; // capture up-left/down-right diagonal
        if (pawn_test_square< FTK_STD_BOARD_SIZE && pawn_test_square>= 0 &&
            (1 == abs((pawn_test_square/8) - (i/8)))) 
        {
          temp_mask |= (1ULL << pawn_test_square);
        }

        /* Do not allow King to move into a valid opponent's piece valid move */
        board->move_mask[king_position] &= ~temp_mask;
      }
      else
      {
        /* Do not allow King to move into a valid opponent's piece valid move*/
        board->move_mask[king_position] &= ~board->move_mask[i];
      }

      /* Square under test is opponents piece */
      if (board->move_mask[i] & FTK_POSITION_TO_MASK(king_position)) 
      {
        /* If opponents piece can move to the King's square, the King is in check */
        check = FTK_CHECK_IN_CHECK;

        /* Consider opponent's path to king */
        path = ftk_build_path_mask(board->square[i], king_position, i, board->move_mask[i]);
        for (j = 0; j < FTK_STD_BOARD_SIZE; j++) 
        {
          if(board->square[j].type != FTK_TYPE_EMPTY && board->square[j].type != FTK_TYPE_KING && board->square[j].color == turn)
          {
            /* Walk entire board and clear all moves that do not clear check */
            /* If piece is not the king, remove all moves that do not block check or capture attacker */
            board->move_mask[j] &= (path | FTK_POSITION_TO_MASK(i));
          }
        }
      }
      /*Build opponents move mask as if current-turn player's pieces do not exist */
      move_mask_no_opponent = ftk_build_move_mask_raw(board->square[i], opponent_mask, turn_mask, i, &ep);

      if(move_mask_no_opponent & FTK_POSITION_TO_MASK(king_position))
      {
        /* Get opponent's path to players king */
        path = ftk_build_path_mask(board->square[i], king_position, i, move_mask_no_opponent);

        /* Overlap between piece's path to King and current player's pieces */
        cross = path & turn_mask;
        
        /* Assume no protecting piece */
        protecting = FTK_XX;

        for (j = 0; j < FTK_STD_BOARD_SIZE; j++) 
        {
          if ((cross & FTK_POSITION_TO_MASK(j)) && (board->square[j].type != FTK_TYPE_KING) )
          {
            if (protecting != FTK_XX) 
            {
              /* If a piece is already blocking, this is the second blocking piece.
                This is not a potential uncovered check, clear blocking square and break loop */
              protecting = FTK_XX;
              break;
            }
            /* Piece is protecting King */
            protecting = j;
          }
        }
        if (protecting != FTK_XX) 
        {
          /* If piece is blocking check, only allow moves on the pieces path */
          board->move_mask[protecting] = board->move_mask[protecting] & (path | FTK_POSITION_TO_MASK(i));
        }
      }
    }
  }

  /* Verify King cannot move into check with remaining moves */
  king_moves_temp = board->move_mask[king_position];
  while(king_moves_temp)
  {
    move_under_test = ftk_get_first_set_bit_idx(king_moves_temp);
    FTK_CLEAR_BIT(king_moves_temp, move_under_test);

    board_copy = *board;
    board_copy.square[move_under_test] = board_copy.square[king_position];
    FTK_SQUARE_CLEAR(board_copy.square[king_position]);

    ftk_build_all_masks(&board_copy);

    /* Check all potential (simple) moves to king position after move under test */
    for(j = 0; j < FTK_STD_BOARD_SIZE; j++)
    {
      board_copy.move_mask[j] = ftk_build_move_mask(&board_copy, j, &(ep));
      if(board_copy.move_mask[j] & FTK_POSITION_TO_MASK(move_under_test))
      {
        /* If opponent can move to test square, remove it from King's legal moves */
        FTK_CLEAR_BIT(board->move_mask[king_position], move_under_test);
      }
    }
  }

  return check;
}

/* Masks of King's Path for Castling */
#define WHITE_QS_PATH (FTK_POSITION_TO_MASK(FTK_C1) | FTK_POSITION_TO_MASK(FTK_D1))
#define WHITE_KS_PATH (FTK_POSITION_TO_MASK(FTK_F1) | FTK_POSITION_TO_MASK(FTK_G1))
#define BLACK_QS_PATH (FTK_POSITION_TO_MASK(FTK_C8) | FTK_POSITION_TO_MASK(FTK_D8))
#define BLACK_KS_PATH (FTK_POSITION_TO_MASK(FTK_F8) | FTK_POSITION_TO_MASK(FTK_G8))

void ftk_add_castle(ftk_board_s *board, ftk_color_e turn) 
{
  ftk_square_e i = 0;

  if ((turn == FTK_COLOR_WHITE) && (FTK_SQUARE_IS(board->square[FTK_E1], FTK_TYPE_KING, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED)))
  {
    /* White King has not moved, consider for castling */
    ftk_castle_mask_t castle = FTK_CASTLE_KING_SIDE_WHITE | FTK_CASTLE_QUEEN_SIDE_WHITE;

    if (((FTK_POSITION_TO_MASK(FTK_B1) | WHITE_QS_PATH) & (board->white_mask | board->black_mask)) != 0 ||
        !FTK_SQUARE_IS(board->square[FTK_A1], FTK_TYPE_ROOK, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED)) 
    {
      /* Rook has moved or squared between Rook and King are not emtpy (Queen
      * side) */
      castle &= ~FTK_CASTLE_QUEEN_SIDE_WHITE;
    }
    if ((WHITE_KS_PATH & (board->white_mask | board->black_mask)) != 0 ||
        !FTK_SQUARE_IS(board->square[FTK_H1], FTK_TYPE_ROOK, FTK_COLOR_WHITE, FTK_MOVED_NOT_MOVED))
    {
      /* Rook has moved or squared between Rook and King are not emtpy (King
      * side) */
      castle &= ~FTK_CASTLE_KING_SIDE_WHITE;
    }

    for(i = 0; (i < FTK_STD_BOARD_SIZE) && (castle != 0); i++)
    {
      /* Check move mask of all black squares if they conflict with white castling */
      if(board->square[i].color == FTK_COLOR_BLACK)
      {
        if (board->move_mask[i] & FTK_POSITION_TO_MASK(FTK_E1))
        {
          /* King is in check */
          castle &= ~FTK_CASTLE_KING_SIDE_WHITE;
          castle &= ~FTK_CASTLE_QUEEN_SIDE_WHITE;
        }
        if (board->move_mask[i] & WHITE_QS_PATH)
        {
          /* King passes through check (Queen side) */
          castle &= ~FTK_CASTLE_QUEEN_SIDE_WHITE;
        }
        if (board->move_mask[i] & WHITE_KS_PATH)
        {
          /* King passes through check (King side) */
          castle &= ~FTK_CASTLE_KING_SIDE_WHITE;
        }
      }
    }
    /* Add castling to King's valid move masks if allowed (Rook already has mask set implicitly) */
    if(castle & FTK_CASTLE_KING_SIDE_WHITE)
    {
        board->move_mask[FTK_E1] |= FTK_POSITION_TO_MASK(FTK_G1);
    }
    if(castle & FTK_CASTLE_QUEEN_SIDE_WHITE)
    {
        board->move_mask[FTK_E1] |= FTK_POSITION_TO_MASK(FTK_C1);
    }
  }
  else if((turn == FTK_COLOR_BLACK) && ( FTK_SQUARE_IS(board->square[FTK_E8], FTK_TYPE_KING, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED) ) )
  {
    /* Black King has not moved, consider for castling */
    ftk_castle_mask_t castle = FTK_CASTLE_KING_SIDE_BLACK | FTK_CASTLE_QUEEN_SIDE_BLACK;

    if (((FTK_POSITION_TO_MASK(FTK_B8) | BLACK_QS_PATH) & (board->white_mask | board->black_mask)) != 0 ||
        !FTK_SQUARE_IS(board->square[FTK_A8], FTK_TYPE_ROOK, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED)) 
    {
      /* Rook has moved or squared between Rook and King are not emtpy (Queen
      * side) */
      castle &= ~FTK_CASTLE_QUEEN_SIDE_BLACK;
    }
    if ((BLACK_KS_PATH & (board->white_mask | board->black_mask)) != 0 ||
        !FTK_SQUARE_IS(board->square[FTK_H8], FTK_TYPE_ROOK, FTK_COLOR_BLACK, FTK_MOVED_NOT_MOVED))
    {
      /* Rook has moved or squared between Rook and King are not emtpy (King
      * side) */
      castle &= ~FTK_CASTLE_KING_SIDE_BLACK;
    }

    for(i = 0; (i < FTK_STD_BOARD_SIZE) && (castle != 0); i++)
    {
      /* Check move mask of all white squares if they conflict with black castling */
      if(board->square[i].color == FTK_COLOR_WHITE)
      {
        if (board->move_mask[i] & FTK_POSITION_TO_MASK(FTK_E8))
        {
          /* King is in check */
          castle &= ~FTK_CASTLE_KING_SIDE_BLACK;
          castle &= ~FTK_CASTLE_QUEEN_SIDE_BLACK;
        }
        if (board->move_mask[i] & BLACK_QS_PATH)
        {
          /* King passes through check (Queen side) */
          castle &= ~FTK_CASTLE_QUEEN_SIDE_BLACK;
        }
        if (board->move_mask[i] & BLACK_KS_PATH)
        {
          /* King passes through check (King side) */
          castle &= ~FTK_CASTLE_KING_SIDE_BLACK;
        }
      }
    }
    if(castle & FTK_CASTLE_KING_SIDE_BLACK)
    {
        board->move_mask[FTK_E8] |= FTK_POSITION_TO_MASK(FTK_G8);
    }
    if(castle & FTK_CASTLE_QUEEN_SIDE_BLACK)
    {
        board->move_mask[FTK_E8] |= FTK_POSITION_TO_MASK(FTK_C8);
    }
  }
}

ftk_square_e ftk_mask_to_position(ftk_board_mask_t mask)
{ 
  ftk_square_e position    = 0; 
  ftk_board_mask_t temp_mask = mask; 
  while(temp_mask)
  {
    temp_mask >>= 1; 
    if(temp_mask)
    {
      position++;
    } 
  }
  return position;
}