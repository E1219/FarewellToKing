/*
  farewell_to_king_hash.h
  Farewell To King - Chess Library
  Edward Sandor
  April 2023

  Contains declarations of all functions and types for hashing chess games
*/

#ifndef __FAREWELL_TO_KING_HASH_H__
#define __FAREWELL_TO_KING_HASH_H__

#include "farewell_to_king_types.h"

/* Zobrist Hash:
https://web.archive.org/web/20230315030129/https://www.chessprogramming.org/Zobrist_Hashing

" At program initialization, we generate an array of pseudorandom numbers [11] [12]:
    One number for each piece at each square
    One number to indicate the side to move is black
    Four numbers to indicate the castling rights, though usually 16 (2^4) are used for speed
    Eight numbers to indicate the file of a valid En passant square, if any 
  This leaves us with an array with 781 (12*64 + 1 + 4 + 8) random numbers "
    
*/
#define FTK_ZOBRIST_RANDOM_ARRAY_SIZE 781
typedef uint_fast64_t ftk_zobrist_hash_key_t;

/**
 * Enum of different Zobrist hashing function flavors
*/
typedef enum
{
  FTK_ZOBRIST_HASH_FLAVOR_DEFAULT,
  FTK_ZOBRIST_HASH_FLAVOR_POLYGLOT = FTK_ZOBRIST_HASH_FLAVOR_DEFAULT

} ftk_zobrist_hash_flavor_e;

/**
 * Configuration for Zobrist hashing functions
*/
typedef struct
{
  ftk_zobrist_hash_flavor_e flavor;
  ftk_zobrist_hash_key_t    random[FTK_ZOBRIST_RANDOM_ARRAY_SIZE];
} ftk_zobrist_hash_config_s;

/**
 * @brief Logic to hash a chess game with the Zobrist hashing function
 * 
 * @param game   Game to be hashed
 * @param config Zobrist hashing function configuration
 * 
 * @return hash key representing the given game or 0 if error
*/
ftk_zobrist_hash_key_t ftk_hash_game_zobrist(const ftk_game_s *game, const ftk_zobrist_hash_config_s *hash_config);


#endif /* __FAREWELL_TO_KING_HASH_H__ */