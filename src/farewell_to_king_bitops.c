/*
 farewell_to_king_bitops.c
 FarewellToKing - Chess Library
 Edward Sandor
 January 2021
 
 Common bit operations
*/

#include "farewell_to_king_bitops.h"

/**
 * @brief Return number of bits set in mask
 * 
 * @param mask 
 */
uint_fast8_t ftk_get_num_bits_set(ftk_max_mask_size_t mask)
{
  uint_fast8_t ret_val = 0;

  while(mask != 0)
  {
    if(mask & 0x1)
    {
      ret_val++;
    }

    mask >>= 1;
  }

  return ret_val;
}

/**
 * @brief 
 * 
 * @param mask Get first set bit (LSB) index from mask
 * @return uint8_t index of first set bit, 0xFF if empty
 */
uint_fast8_t ftk_get_first_set_bit_idx(ftk_max_mask_size_t mask)
{
  uint_fast8_t ret_val = 0;

  if(mask != 0)
  {
    if(0 == (mask & ((1ULL<<48)-1)))
    {
      /* Shortcut the first 48 bits */
      ret_val   = 48;
      mask    >>= 48;
    }
    else if(0 == (mask & ((1ULL<<32)-1)))
    {
      /* Shortcut the first 32 bits */
      ret_val   = 32;
      mask    >>= 32;
    }
    else if(0 == (mask & ((1ULL<<16)-1)))
    {
      /* Shortcut the first 16 bits */
      ret_val   = 16;
      mask    >>= 16;
    }

    while(0 == (mask & 0x1))
    {
      ret_val++;
      mask >>= 1;
    }
  }
  else
  {
    ret_val = 0xFF;
  }

  return ret_val;
}