/*
 farewell_to_king_test.c
 FarewellToKing - Chess Library
 Edward Sandor
 November 2014 - 2020
 
 Main function can be used to test different aspects of FarewellToKing
*/
#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "farewell_to_king.h"
#include "farewell_to_king_strings.h"
#include "farewell_to_king_types.h"
#include "farewell_to_king_polyglot_book.h"

int main(int argc, char * const argv[]){
  ftk_game_s game;
  ftk_game_end_e game_end;
  ftk_begin_standard_game(&game);
  ftk_zobrist_hash_key_t incremental_hash_key = ftk_hash_game_zobrist_polyglot_book(&game);

  char input[128];
  char out[1024];
  ftk_move_s move = {0};

  int opt;
  bool print_hash = false;
  while ((opt = getopt(argc, argv, "h")) != -1) 
  {
    switch (opt) {
      case 'h':
      {
        print_hash = true;
        break;
      }
      default:
      {
        exit(-1);
      }
    }
  }

  ftk_zobrist_hash_config_s hash_config;
  assert(FTK_SUCCESS == ftk_zobrist_hash_generate_config(FTK_ZOBRIST_HASH_FLAVOR_DEFAULT, &hash_config));

  for(;;){

    game_end = ftk_check_for_game_end(&game);
    if(FTK_END_NOT_OVER == game_end)
    {
      if(FTK_CHECK_IN_CHECK == ftk_check_for_check(&game))
      {
        printf("CHECK!\r\n\r\n");
      }
    }
    else if (FTK_END_CHECKMATE == game_end) 
    {
      printf("CHECKMATE!\r\n\r\n");
    }
    else if (FTK_END_DRAW_STALEMATE == game_end) 
    {
      printf("STALEMATE!\r\n\r\n");
    }
    else {
      printf("GAME OVER! Reason %u\r\n\r\n", game_end);
    }

    ftk_game_to_fen_string(&game, out);
    printf("%s\r\n", out);
    ftk_zobrist_hash_key_t hash_key = ftk_hash_game_zobrist_polyglot_book(&game);
    if(print_hash)
    {
      printf("Raw: 0x%016lx\r\n", hash_key);
      printf("Inc: 0x%016lx\r\n", incremental_hash_key);
    }
    assert(incremental_hash_key == hash_key);

    int ret = scanf("%s", input);

    if(EOF == ret || strcmp("q",input) == 0 || strcmp("quit",input)==0)
        break;

    if(strcmp("u",input) == 0)
    {
      ftk_move_backward(&game, &move);
    }
    else if(strcmp("r",input) == 0)
    {
      ftk_move_forward(&game, &move);
    }
    else if(strcmp("n",input) == 0)
    {
      ftk_begin_standard_game(&game);
    }
    else if(strcmp("p",input) == 0)
    {
      ftk_board_to_string_with_coordinates(&game.board, out);
      printf("%s\r\n", out);
    }
    else 
    {
      ftk_square_e target = FTK_XX;
      ftk_square_e source = FTK_XX;

      ftk_type_e   pawn_promo_type = FTK_TYPE_EMPTY;
      ftk_castle_e castle_type     = FTK_CASTLE_NONE;
      ftk_xboard_move(input, &target, &source, &pawn_promo_type, &castle_type);

      move = ftk_move_piece(&game, target, source, pawn_promo_type);
      ftk_move_backward(&game, &move);
      incremental_hash_key = ftk_hash_game_zobrist_incremental_polyglot_book(&game, &move, incremental_hash_key);
      ftk_move_forward(&game, &move);
    }
  }

  return 0;
}
