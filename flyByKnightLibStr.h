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

//method converts chess coordinate to square number
//char input[3]: char array containing chess cordinate
//POS_T return: a number representing a board square  
POS_T toPos(char input[3]);
//method converts square number to chess coordinate
//POS_T square: the square to be converted
//char coordinate[]: the return string containing lowercase coordinate.  To be overwritten >=3
void toCoordinate(POS_T square, char coordinate[]);
//method converts character to piece
//char input: a character representing a piece
//PIECE_T return: the type of piece represented by character
PIECE_T toPiece(char input);
//method converts piece a character.  Uppercase white, lowercase black
//PIECE_T piece: the piece to be represented by a character
//char return: the type of piece represented by character
char toCharPiece(PIECE_T piece);

//method interprets a move string given in the xboard protocol
//char input[]: input string
//POS_T * target: the target square interpreted from input, to be overwritten
//POS_T * source: the source square interpreted from input, to be overwritten
void xboardMove(char input[8], POS_T * target, POS_T * source, char * extra);

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
