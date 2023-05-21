/*
 farewell_to_king_mask.h
 Farewell To King - Chess Library
 Edward Sandor
 January 2015 - 2020
 
 Contains declarations of all methods used to generate and manipulate board masks.
*/

#ifndef _FAREWELL_TO_KING_MASK_H_
#define _FAREWELL_TO_KING_MASK_H_
#include "farewell_to_king_types.h"

/**
 * @brief Build a board bitmask for all squares of given type
 * 
 * @param board 
 * @param type 
 * @return ftk_board_mask_t 
 */
ftk_board_mask_t ftk_build_type_mask(const ftk_board_s *board, ftk_type_e type);
/**
 * @brief Build a board bitmask for all squares of given color
 * 
 * @param board 
 * @param color 
 * @return ftk_board_mask_t 
 */
ftk_board_mask_t ftk_build_color_mask(const ftk_board_s *board,
                                      ftk_color_e color);
/**
 * @brief Build a board bitmask for all non-empty squares
 * 
 * @param board 
 * @return ftk_board_mask_t 
 */
ftk_board_mask_t ftk_build_board_mask(const ftk_board_s *board);

/**
 * @brief Generates all masks representing basic properties of the board
 * 
 * @param board Board to build masks for
 */
void ftk_build_all_masks(ftk_board_s *board);

/**
 * @brief Build mask of basic legal moves, no checks for check or castling.
 * 
 * @param board Board information
 * @param position Position to build move mask for
 * @param ep Output indicating en passant square if valid
 * @return ftk_board_mask_t Mask of basic legal moves
 */
ftk_board_mask_t ftk_build_move_mask(const ftk_board_s *board, ftk_square_e position, ftk_square_e *ep);

/**
 * @brief Builds mask describing a path to a specified square 
 * 
 * @param square The source square contents
 * @param target The destination square for piece of interest
 * @param source The current square of the piece of interest
 * @param moves A mask describing possible moves of the piece of interest
 * @return ftk_board_mask_t 
 */
ftk_board_mask_t ftk_build_path_mask(ftk_square_s     square,
                                     ftk_square_e   target,
                                     ftk_square_e   source,
                                     ftk_board_mask_t moves);

/**
 * @brief Strips moves from the move mask for any piece whose movement would result in exposed check
 * 
 * @param board Board to strip check moves
 * @param turn  Current turn player color
 * @param ep    Current en passant target square
 * @return ftk_check_e 
 */
ftk_check_e ftk_strip_check(ftk_board_s *board, ftk_color_e turn, ftk_square_e ep);

/**
 * @brief Adds castling to move masks for current player if castling is legal
 * 
 * @param board Board to add castling to
 * @param turn Current turn player color
 */
void ftk_add_castle(ftk_board_s *board, ftk_color_e turn);

/**
 * @brief Converts a mask bit to position index (Returns mask MSB if multiple bits are set)
 * 
 */
ftk_square_e ftk_mask_to_position(ftk_board_mask_t mask);

#endif //_FAREWELL_TO_KING_MASK_H_