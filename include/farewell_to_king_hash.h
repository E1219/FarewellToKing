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

typedef struct
{
  ftk_zobrist_hash_key_t random[FTK_ZOBRIST_RANDOM_ARRAY_SIZE];
} ftk_zobrist_hash_config_s;


typedef enum
{
  FTK_HASH_TYPE_INVALID,
  FTK_HASH_TYPE_ZOBRIST,

} ftk_hash_type_e;

typedef union
{
  ftk_zobrist_hash_key_t zobrist;
} ftk_hash_key_u;

typedef union
{
  const ftk_zobrist_hash_config_s *zobrist;
} ftk_hash_config_u;

typedef struct
{
  ftk_hash_type_e type;
  ftk_hash_key_u  key;
  ftk_hash_key_u  config;

} ftk_hash_data_s;



#endif /* __FAREWELL_TO_KING_HASH_H__ */