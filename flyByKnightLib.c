//
//FlyByKnightLib.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Contains implementations of all methods for general game manipulation. 
//

#include "flyByKnightLib.h"

void beginStandardGame(Game * game){

    standardBoard(game->board);

    game->turn = WHITE;
    
    updateMasks(game);
}
void updateMasks(Game * game){
    
    MASK64 tmp;
    
    game->boardM = boardMask(game->board);
    game->whiteM = whiteMask(game->board);    
    game->blackM = blackMask(game->board);

    POS_T i;
    for(i = 0; i < STDBOARD; i++){
        TURN_T colorp = (game->board[i] & COLORMASK);
        if((game->board[i] & TYPEMASK) == KING){

            if((game->board[i] & COLORMASK) == WHITE){
                game->wKing = i;
            }
            else{
                game->bKing = i;
            }
        }
        game->moveM[i] = moveMask(&game->board[i], &i, (colorp == game->turn || ((game->board[i] & TYPEMASK) == PAWN))?(&game->boardM):((colorp != WHITE)?(&game->blackM):(&game->whiteM)), (colorp == WHITE)?(&game->blackM):(&game->whiteM));
    }

    stripCheck(game->board, game->moveM, (game->turn == WHITE)?(&game->whiteM):(&game->blackM), (game->turn == WHITE)?(&game->wKing):(&game->bKing));
}

