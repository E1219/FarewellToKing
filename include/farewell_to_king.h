/*
 farewell_to_king.h
 FarewellToKing - Chess Library
 Edward Sandor
 November 2014 - 2020
 
 Contains delcarations of all methods for general game manipulation. 
*/

#ifndef _FAREWELL_TO_KING_H_
#define _FAREWELL_TO_KING_H_
#include "farewell_to_king_bitops.h"
#include "farewell_to_king_board.h"
#include "farewell_to_king_mask.h"
#include "farewell_to_king_types.h"

/**
 * @brief Returns name string for Farewell to King Library
 * 
 * @return const char* 
 */
const char * ftk_get_name_string();

/**
 * @brief Returns name with version string for Farewell to King Library
 * 
 * @return const char* 
 */
const char * ftk_get_name_ver_string();

/**
 * @brief Returns into string for Farewell to King Library
 * 
 * @return const char* 
 */
const char * ftk_get_intro_string();

/**
 * @brief Begins a standard game of chess
 * 
 * @param game game to initialize
 */
void ftk_begin_standard_game(ftk_game_s *game);

/**
 * @brief Updates all board bitmasks for a game
 * 
 * @param game game to generate masks for
 */
void ftk_update_board_masks(ftk_game_s *game);

/**
 * @brief Stages a move in a game without modifying the game
 * 
 * @param game Game to move in
 * @param target Position to move piece to
 * @param source Piece position to move
 * @param pawn_promotion Type to convert Pawn to in case of promotion, ignored in other cases (may use 'don't care').  Assumed Queen if not provided or invalid
 * @return Move Description of modifications made to game
 */
ftk_move_s ftk_stage_move(const ftk_game_s *game, ftk_square_e target, ftk_square_e source, ftk_type_e pawn_promotion);

/**
 * @brief Make a move in a game
 * 
 * @param game Game to move in
 * @param target Position to move piece to
 * @param source Piece position to move
 * @param pawn_promotion Type to convert Pawn to in case of promotion, ignored in other cases (may use 'don't care').  Assumed Queen if not provided or invalid
 * @return Move Description of modifications made to game
 */
ftk_move_s ftk_move_piece(ftk_game_s *game, ftk_square_e target, ftk_square_e source, ftk_type_e pawn_promotion);

/**
 * @brief Make a move in a game without generating masks (Masks must be generated via ftk_update_board_masks() before use)
 * 
 * @param game Game to move in
 * @param target Position to move piece to
 * @param source Piece position to move
 * @param pawn_promotion Type to convert Pawn to in case of promotion, ignored in other cases (may use 'don't care').  Assumed Queen if not provided or invalid
 * @return Move Description of modifications made to game
 */
ftk_move_s ftk_move_piece_quick(ftk_game_s *game, ftk_square_e target, ftk_square_e source, ftk_type_e pawn_promotion);

/**
 * @brief Move forward based on move structure
 *
 * @param game game to manipulate
 * @param move description of move to be reversed.
 * @return char 
 */
ftk_result_e ftk_move_forward(ftk_game_s *game, ftk_move_s *move);

/**
 * @brief Move forward based on move structure without generating masks (Masks must be generated via ftk_update_board_masks() before use)
 *
 * @param game game to manipulate
 * @param move description of move to be reversed.
 * @return char 
 */
ftk_result_e ftk_move_forward_quick(ftk_game_s *game, ftk_move_s *move);

/**
 * @brief Move backward based on move structure
 *
 * @param game game to manipulate
 * @param move description of move to be reversed.
 * @return char 
 */
ftk_result_e ftk_move_backward(ftk_game_s *game, ftk_move_s *move);

/**
 * @brief Move backward based on move structure without generating masks (Masks must be generated via ftk_update_board_masks() before use)
 *
 * @param game game to manipulate
 * @param move description of move to be reversed.
 * @return char 
 */
ftk_result_e ftk_move_backward_quick(ftk_game_s *game, ftk_move_s *move);

/**
 * @brief Checks if current turn's player is in check
 * 
 * @param game 
 * @return ftk_check_e 
 */
ftk_check_e ftk_check_for_check(const ftk_game_s *game);

/**
 * @brief Checks if current player has any legal moves
 * 
 * @param game 
 * @return true 
 * @return false 
 */
bool ftk_check_legal_moves(const ftk_game_s *game);

/**
 * @brief Checks if a game end condition has been met
 * 
 * @param game 
 * @return ftk_game_end_e 
 */
ftk_game_end_e ftk_check_for_game_end(const ftk_game_s *game);

/**
 * @brief Get list of legal moves for given game
 * 
 * @param game game to generate list for
 * @param move_list list of legal moves (memory allocated accordingly)
 */
void ftk_get_move_list(const ftk_game_s *game, ftk_move_list_s * move_list);

/**
 * @brief Delete move list
 * 
 * @param move_list list of legal moves to delete (memory deallocated accordingly)
 */
void ftk_delete_move_list(ftk_move_list_s * move_list);

/**
 * @brief Invalidates move structure
 * 
 * @param move Move to be invalidated
 */
void ftk_invalidate_move(ftk_move_s *move);

/**
 * @brief Random uint64 generator.  Based on the C standard rand() function will be used without calling srand() (seed unmodified).

 * 
 * @param void* Unused by this implementation, but present to satisfy ftk_rand64_f type.  Pass as NULL
 * 
 * @return random uint64_t
*/
uint64_t ftk_rand64(void *);

#endif // _FAREWELL_TO_KING_H_