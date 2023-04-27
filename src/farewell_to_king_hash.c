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

static inline zobrist_hash_piece_type_polyglot_e get_zobrist_hash_piece_type_polyglot(const ftk_square_s *square)
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

static inline bool check_polyglot_book_en_passant(const ftk_board_s *board, ftk_square_e ep_square, ftk_color_e turn)
{
  bool ret_val = false;

  if(ep_square < FTK_XX)
  {
    const unsigned int ep_file = (ep_square % 8);
    if(((turn == FTK_COLOR_WHITE) &&
        (((ep_file < 7) &&
          (board->square[ep_square-7].type  == FTK_TYPE_PAWN) &&
          (board->square[ep_square-7].color == FTK_COLOR_WHITE)) ||
          ((ep_file > 0) &&
          (board->square[ep_square-9].type  == FTK_TYPE_PAWN) &&
          (board->square[ep_square-9].color == FTK_COLOR_WHITE)))) ||
        ((turn == FTK_COLOR_BLACK) &&
        (((ep_file > 0) &&
          (board->square[ep_square+7].type  == FTK_TYPE_PAWN) &&
          (board->square[ep_square+7].color == FTK_COLOR_BLACK)) ||
          ((ep_file < 7) &&
          (board->square[ep_square+9].type  == FTK_TYPE_PAWN) &&
          (board->square[ep_square+9].color == FTK_COLOR_BLACK)))))
    {
      /* Polyglot flavor only counts En Passant square if the current player can capture unlike FEN which is unconditional */
      ret_val = true;
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
    if(check_polyglot_book_en_passant(&game->board, game->ep, game->turn))
    {
      hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_EN_PASSANT_OFFSET+(game->ep % 8)];
    }

    /* White to move */
    if(game->turn == FTK_COLOR_WHITE)
    {
      hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_TURN_OFFSET];
    }
  }

  return hash_key;
}

ftk_zobrist_hash_key_t ftk_hash_game_zobrist_incremental(const ftk_game_s *game, const ftk_zobrist_hash_config_s *hash_config, const ftk_move_s *move, ftk_zobrist_hash_key_t prev_hash_key)
{
  ftk_zobrist_hash_key_t new_hash_key = prev_hash_key;

  /* Remove Castle Rights */
  if((FTK_E1 == move->source) && (game->board.square[FTK_E1].moved == FTK_MOVED_NOT_MOVED))
  {
    /* White king is moving, remove castle rights for rooks which have not moved */
    if(game->board.square[FTK_H1].moved == FTK_MOVED_NOT_MOVED)
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_KING_SIDE];
    }
    if(game->board.square[FTK_A1].moved == FTK_MOVED_NOT_MOVED)
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_QUEEN_SIDE];
    }
  }
  else if((FTK_E8 == move->source) && (game->board.square[FTK_E8].moved == FTK_MOVED_NOT_MOVED))
  {
    /* Black king is moving, remove castle rights for rooks which have not moved */
    if(game->board.square[FTK_H8].moved == FTK_MOVED_NOT_MOVED)
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_KING_SIDE];
    }
    if(game->board.square[FTK_A8].moved == FTK_MOVED_NOT_MOVED)
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_QUEEN_SIDE];
    }
  }
  if(game->board.square[FTK_E1].moved == FTK_MOVED_NOT_MOVED)
  {
    /* White king has not moved, remove castle rights if white rook is moving */
    if((FTK_H1 == move->source) && (game->board.square[FTK_H1].moved == FTK_MOVED_NOT_MOVED))
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_KING_SIDE];
    }
    else if((FTK_A1 == move->source) && (game->board.square[FTK_A1].moved == FTK_MOVED_NOT_MOVED))
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_WHITE_QUEEN_SIDE];
    }
  }
  if(game->board.square[FTK_E8].moved == FTK_MOVED_NOT_MOVED)
  {
    /* Black king has not moved, remove castle rights if black rook is moving */
    if((FTK_H8 == move->source) && (game->board.square[FTK_H8].moved == FTK_MOVED_NOT_MOVED))
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_KING_SIDE];
    }
    else if((FTK_A8 == move->source) && (game->board.square[FTK_A8].moved == FTK_MOVED_NOT_MOVED))
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_CASTLE_BLACK_QUEEN_SIDE];
    }
  }

  if(check_polyglot_book_en_passant(&game->board, game->ep, game->turn))
  {
    new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_EN_PASSANT_OFFSET+(game->ep % 8)];
  }
  if( (game->board.square[move->source].type == FTK_TYPE_PAWN) &&
      ((move->target-move->source) == ((game->turn == FTK_COLOR_WHITE)?16:-16)) )
 {
    ftk_square_e ep_square = move->target - ((game->turn == FTK_COLOR_WHITE)?8:-8);
    if(check_polyglot_book_en_passant( &game->board, 
        (ep_square), 
        ((game->turn == FTK_COLOR_WHITE)?FTK_COLOR_BLACK:FTK_COLOR_WHITE)) )
    {
      new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_EN_PASSANT_OFFSET+(ep_square % 8)];
    }
  }

  if(move->target == game->ep)
  {
    /* Remove en passant pawn */
    ftk_square_e ep_square = move->target - ((game->turn == FTK_COLOR_WHITE)?8:-8);
    new_hash_key ^= hash_config->random[ep_square + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[ep_square])];
  }
  else
  {
    /* Remove contents from previous target square */
    if(game->board.square[move->target].type != FTK_TYPE_EMPTY)
    {
      new_hash_key ^= hash_config->random[move->target + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[move->target])];
    }
  }
  /* Add contests for new target square */
  ftk_square_s new_target_square = game->board.square[move->source];
  if((move->pawn_promotion > FTK_TYPE_PAWN) && (move->pawn_promotion < FTK_TYPE_DONT_CARE))
  {
    new_target_square.type = move->pawn_promotion;
  }
  new_hash_key ^= hash_config->random[move->target + 64*get_zobrist_hash_piece_type_polyglot(&new_target_square)];
  /* Remove previous source square */
  new_hash_key ^= hash_config->random[move->source + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[move->source])];

  if((move->source == FTK_E1) && (move->target == FTK_G1) && (game->board.square[FTK_E1].type == FTK_TYPE_KING))
  {
    /* Move Rook */
    new_hash_key ^= hash_config->random[FTK_F1 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_H1])];
    new_hash_key ^= hash_config->random[FTK_H1 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_H1])];
  }
  else if((move->source == FTK_E1) && (move->target == FTK_C1) && (game->board.square[FTK_E1].type == FTK_TYPE_KING))
  {
    /* Move Rook */
    new_hash_key ^= hash_config->random[FTK_D1 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_A1])];
    new_hash_key ^= hash_config->random[FTK_A1 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_A1])];
  }
  else if((move->source == FTK_E8) && (move->target == FTK_G8) && (game->board.square[FTK_E8].type == FTK_TYPE_KING))
  {
    /* Move Rook */
    new_hash_key ^= hash_config->random[FTK_F8 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_H8])];
    new_hash_key ^= hash_config->random[FTK_H8 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_H8])];
  }
  else if((move->source == FTK_E8) && (move->target == FTK_C8) && (game->board.square[FTK_E8].type == FTK_TYPE_KING))
  {
    /* Move Rook */
    new_hash_key ^= hash_config->random[FTK_D8 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_A8])];
    new_hash_key ^= hash_config->random[FTK_A8 + 64*get_zobrist_hash_piece_type_polyglot(&game->board.square[FTK_A8])];
  }

  /* Toggle color to move */
  new_hash_key ^= hash_config->random[FTK_ZOBRIST_HASH_POLYGLOT_TURN_OFFSET];

  return new_hash_key;
}