//
//FarewellToKingStr.h
//FarewellToKing - Chess Library
//Edward Sandor
//January 2015 - 2020
//
//Contains declarations of all methods that generate formatted strings for human readable output.
//

#ifndef FAREWELLTOKINGSTR_H
#define FAREWELLTOKINGSTR_H
#include "farewell_to_king_types.h"

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
void printMask(ftk_board_mask_t * mask, char output[]);
//char output[] size >= 144 (18x8).  Lines ended with "\r\n".
//fills output with formatted printout of board without board coordinates
void printBoard(PIECE_T board[STDBOARD], char output[]);
//char output[] size >= 210 (20x10).  Lines ended with "\r\n". 
//fills output with formatted printout of mask including board coordinates
void printMaskC(ftk_board_mask_t * mask, char output[]);
//char output[] size >= 210 (20x10).  Lines ended with "\r\n".
//fills output with formatted printout of board including board coordinates
void printBoardC(PIECE_T board[STDBOARD], char output[]);

//char output[] size >= 86.
//fills output with Forsyth-Edwards Notation representation of 'game'.
void getFEN(Game * game, char output[]);

//load game settings from FEN file
//Game * game: game to store game data
//char fen[]:  character array containing FEN data.
void beginFENGame(Game * game, char fen[]);

#endif
