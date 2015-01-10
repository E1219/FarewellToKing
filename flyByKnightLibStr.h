//
//FlyByKnightLibStr.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Contains declarations of all methods that generate formatted strings for human readable output.
//

#ifndef FLYBYKNIGHTLIBSTR_H
#define FLYBYKNIGHTLIBSTR_H
#include "flyByKnightLibDef.h"

//char output[] size >= 144 (18x8).  Lines ended with "\r\n".
//fills output with formatted printout of mask without board coordinates
void printMask(MASK64 * mask, char output[]);
//char output[] size >= 144 (18x8).  Lines ended with "\r\n".
//fills output with formatted printout of board without board coordinates
void printBoard(PIECE_T board[STDBOARD], char output[]);
//char output[] size >= 210 (20x10).  Lines ended with "\r\n". 
//fills output with formatted printout of mask including board coordinates
void printMaskC(MASK64 * mask, char output[]);
//char output[] size >= 210 (20x10).  Lines ended with "\r\n".
//fills output with formatted printout of board including board coordinates
void printBoardC(PIECE_T board[STDBOARD], char output[]);

#endif
