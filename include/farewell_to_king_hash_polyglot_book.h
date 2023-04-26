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

ftk_zobrist_hash_key_t ftk_hash_game_zobrist_polyglot_book(const ftk_game_s *game);

#endif /* __FAREWELL_TO_KING_HASH_POLYGLOT_BOOK_H__ */