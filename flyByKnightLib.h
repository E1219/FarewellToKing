//
//FlyByKnightLib.h
//FlyByKnightLib 0.0.2 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Contains delcarations of all methods for general game manipulation. 
//

#ifndef FLYBYKNIGHTLIB_H
#define FLYBYKNIGHTLIB_H
#include "flyByKnightLibDef.h"
#include "flyByKnightLibBoard.h"
#include "flyByKnightLibMask.h"

//initializes values of Game structure, game, for a standard game of chess 
void beginStandardGame(Game * game);
//call to update all game masks in the proper order after setup, moving piece, or board modification.
void updateMasks(Game * game);
//call to move piece
void movePiece(Game * game, POS_T * target, POS_T * source);

#endif
