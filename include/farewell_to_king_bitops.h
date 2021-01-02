/*
 farewell_to_king_bitops.h
 Farewell To King - Chess Library
 Edward Sandor
 January 2021
 
 Common bit operations
*/

#ifndef _FAREWELL_TO_KING_BITOPS_H_
#define _FAREWELL_TO_KING_BITOPS_H_

#include "farewell_to_king_types.h"

/**
 * @brief Set bit in mask at index
 * 
 */
#define FTK_SET_BIT(mask, index)   (mask |= (1<<index))
/**
 * @brief Clear bit in mask at index
 * 
 */
#define FTK_CLEAR_BIT(mask, index) (mask &= ~(1<<index))

/**
 * @brief Get number of bits set in mask
 * 
 * @param mask 
 * @return uint8_t number of bits set in mask
 */
uint8_t ftk_get_num_bits_set(ftk_max_mask_size_t mask);

/**
 * @brief 
 * 
 * @param mask Get first set bit (LSB) index from mask
 * @return uint8_t index of first set bit, 0xFF if empty
 */
uint8_t ftk_get_first_set_bit_idx(ftk_max_mask_size_t mask);

#endif //_FAREWELL_TO_KING_BITOPS_H_