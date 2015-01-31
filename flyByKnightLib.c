//
//FlyByKnightLib.c
//FlyByKnightLib 0.0.2 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Contains implementations of all methods for general game manipulation. 
//

#include "flyByKnightLib.h"

void beginStandardGame(Game * game){

    standardBoard(game->board);

    game->ep       = XX;
    game->halfmove = 0;
    game->fullmove = 1;

    game->turn = WHITE;
        
    updateMasks(game);
}
void updateMasks(Game * game){
    
    superMask(game->board, &game->boardM, &game->whiteM, &game->blackM, &game->pawnM, &game->knightM, &game->bishopM, &game->rookM, &game->queenM, &game->kingM, &game->spareM);    

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
void movePiece(Game * game, POS_T * target, POS_T * source){
    if((game->moveM[*source] & (1ULL << *target)) != 0 && (game->board[*source] & COLORMASK)==game->turn){

        if((game->turn & COLORMASK) == BLACK)
            game->fullmove++;

        game->halfmove++;

        if(((game->board[*target] & TYPEMASK) != EMPTY) || ((game->board[*source] & TYPEMASK) == PAWN))
            game->halfmove = 0;

        game->ep = XX;
        if((game->board[*source] & TYPEMASK) == PAWN){
            if((*target - *source) / 8 == 2)
                game->ep = *source + 8;
            else if ((*target - *source) / 8 == -2)
                game->ep = *source - 8;
        }

        placePiece(game->board, &game->board[*source], target); 
        PIECE_T empty = EMPTY;
        placePiece(game->board, &empty, source);
        game->turn = game->turn ^ BLACK;
        updateMasks(game);
    }
}

