/*
 farewell_to_king_board.h
 Farewell To King - Chess Library
 Edward Sandor
 January 2015 - 2020
 
 Contains delcarations of all methods for board manipulation. 
*/

#ifndef _FAREWELL_TO_KING_BOARD_H_
#define _FAREWELL_TO_KING_BOARD_H_
#include "farewell_to_king_types.h"

/**
 * @brief Resets board so all squares empty
 * 
 * @param board board to clear
 */
void ftk_clear_board(ftk_board_s *board);

/**
 * @brief Clears and sets up board for a traditional game
 * 
 * @param board board to set
 */
void ftk_set_standard_board(ftk_board_s *board);

/**
 * @brief Sets a square with the given content
 * 
 * @param board Board to configure a square
 * @param new_content New square content
 * @param position position to modify
 * @return ftk_square_s previous contents of square
 */
ftk_square_s ftk_set_square(ftk_board_s *board, ftk_square_s new_content, ftk_position_t *position);

#endif //_FAREWELL_TO_KING_BOARD_H_