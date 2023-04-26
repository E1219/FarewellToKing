/*
  farewell_to_king_hash.c
  Farewell To King - Chess Library
  Edward Sandor
  April 2023

  Contains logic for all functions and types for hashing chess games
*/

#include <stddef.h>

#include "farewell_to_king_hash.h"

#define FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_OFFSET     768
#define FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_KING_SIDE  FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_OFFSET + 0
#define FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_QUEEN_SIDE FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_OFFSET + 1
#define FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_KING_SIDE  FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_OFFSET + 2
#define FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_QUEEN_SIDE FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_OFFSET + 3
#define FTK_ZOBRIST_HASH_POLYGLOT_EN_PASSANT_OFFSET 772
#define FTK_ZOBRIST_HASH_POLYGLOT_TURN_OFFSET       780

typedef enum
{
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_PAWN   =  0,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_PAWN   =  1,
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_KNIGHT =  2,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_KNIGHT =  3,
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_BISHOP =  4,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_BISHOP =  5,
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_ROOK   =  6,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_ROOK   =  7,
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_QUEEN  =  8,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_QUEEN  =  9,
  FTK_ZOBRIST_HASH_POLYGLOT_BLACK_KING   = 10,
  FTK_ZOBRIST_HASH_POLYGLOT_WHITE_KING   = 11
} zobrist_hash_piece_type_polyglot_e;

zobrist_hash_piece_type_polyglot_e get_zobrist_hash_piece_type_polyglot(const ftk_square_s *square)
{
  zobrist_hash_piece_type_polyglot_e ret_val = 0;

  if(square->color == FTK_COLOR_WHITE)
  {
    switch(square->type)
    {
      case FTK_TYPE_PAWN:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_PAWN;
        break;
      case FTK_TYPE_KNIGHT:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_KNIGHT;
        break;
      case FTK_TYPE_BISHOP:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_BISHOP;
        break;
      case FTK_TYPE_ROOK:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_ROOK;
        break;
      case FTK_TYPE_QUEEN:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_QUEEN;
        break;
      case FTK_TYPE_KING:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_WHITE_KING;
        break;
      default:
        break;
    }
  }
  else
  {
    switch(square->type)
    {
      case FTK_TYPE_PAWN:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_PAWN;
        break;
      case FTK_TYPE_KNIGHT:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_KNIGHT;
        break;
      case FTK_TYPE_BISHOP:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_BISHOP;
        break;
      case FTK_TYPE_ROOK:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_ROOK;
        break;
      case FTK_TYPE_QUEEN:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_QUEEN;
        break;
      case FTK_TYPE_KING:
        ret_val = FTK_ZOBRIST_HASH_POLYGLOT_BLACK_KING;
        break;
      default:
        break;
    }
  }

  return ret_val;
}

ftk_zobrist_hash_key_t ftk_hash_game_zobrist(const ftk_game_s *game, const ftk_zobrist_hash_config_s * hash_config)
{
  ftk_zobrist_hash_key_t hash_key = 0;

  if((game != NULL) && (hash_config != NULL))
  {
    /* Individual Squares */
    for(unsigned int i = 0; i < FTK_STD_BOARD_SIZE; i ++)
    {
      if(game->board.square[i].type != FTK_TYPE_EMPTY)
      {
        hash_key ^= hash_config->random[i + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[i])];
      }
    }

    /* Castle Rights */
    if(game->board.square[FTK_E1].moved == FTK_MOVED_NOT_MOVED)
    {
      if(game->board.square[FTK_H1].moved == FTK_MOVED_NOT_MOVED)
      {
        hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_KING_SIDE];
      }
      if(game->board.square[FTK_A1].moved == FTK_MOVED_NOT_MOVED)
      {
        hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_QUEEN_SIDE];
      }
    }
    if(game->board.square[FTK_E8].moved == FTK_MOVED_NOT_MOVED)
    {
      if(game->board.square[FTK_H8].moved == FTK_MOVED_NOT_MOVED)
      {
        hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_KING_SIDE];
      }
      if(game->board.square[FTK_A8].moved == FTK_MOVED_NOT_MOVED)
      {
        hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_QUEEN_SIDE];
      }
    }

    /* En Passant Square */
    if(game->ep < FTK_XX)
    {
      const unsigned int ep_file = (game->ep % 8);
      if(((game->turn == FTK_COLOR_WHITE) &&
          (((ep_file < 7) &&
            (game->board.square[game->ep-7].type  == FTK_TYPE_PAWN) &&
            (game->board.square[game->ep-7].color == FTK_COLOR_WHITE)) ||
           ((ep_file > 0) &&
            (game->board.square[game->ep-9].type  == FTK_TYPE_PAWN) &&
            (game->board.square[game->ep-9].color == FTK_COLOR_WHITE)))) ||
         ((game->turn == FTK_COLOR_BLACK) &&
          (((ep_file > 0) &&
            (game->board.square[game->ep+7].type  == FTK_TYPE_PAWN) &&
            (game->board.square[game->ep+7].color == FTK_COLOR_BLACK)) ||
           ((ep_file < 7) &&
            (game->board.square[game->ep+9].type  == FTK_TYPE_PAWN) &&
            (game->board.square[game->ep+9].color == FTK_COLOR_BLACK)))))
      {
        /* Polyglot flavor only counts En Passant square if the current player can capture unlike FEN which is unconditional */
        hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_EN_PASSANT_OFFSET+ep_file];
      }
    }

    /* White to move */
    if(game->turn == FTK_COLOR_WHITE)
    {
      hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_TURN_OFFSET];
    }
  }

  return hash_key;
}