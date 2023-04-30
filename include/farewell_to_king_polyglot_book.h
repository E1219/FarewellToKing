/*
  farewell_to_king_hash_polyglot_book.h
  Farewell To King - Chess Library
  Edward Sandor
  April 2023

  Contains logic for all functions and types for hashing chess games in the polyglot book format
*/


#ifndef __FAREWELL_TO_KING_HASH_POLYGLOT_BOOK_H__
#define __FAREWELL_TO_KING_HASH_POLYGLOT_BOOK_H__

#include "farewell_to_king_hash.h"

const ftk_zobrist_hash_config_s * ftk_get_zobrist_hash_config_polyglot_book();

/**
 * @brief Logic to hash a chess game with the Zobrist hashing function with the standard polyglot book config
 * 
 * @param game   Game to be hashed
 * 
 * @return hash key representing the given game
*/
ftk_zobrist_hash_key_t ftk_hash_game_zobrist_polyglot_book(const ftk_game_s *game);

/**
 * @brief Logic to hash a chess game with the Zobrist hashing function with the standard polyglot book config
 * 
 * @param game          Game to be hashed in the current state (i.e. 'move' is not applied)
 * @param move          Move to incrementally update hash with
 * @param prev_hash_key Previous hash to be updated by 'move'
 * 
 * @return hash key representing the given game
*/
ftk_zobrist_hash_key_t ftk_hash_game_zobrist_incremental_polyglot_book(const ftk_game_s *game, const ftk_move_s *move, ftk_zobrist_hash_key_t prev_hash_key);


#endif /* __FAREWELL_TO_KING_HASH_POLYGLOT_BOOK_H__ */