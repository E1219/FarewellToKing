//
//FlyByKnightLibDef.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Contains all type, constant, and structure definitions to be used used by FlyByKnightLib.
//

#ifndef FLYBYKNIGHTLIBDEF_H
#define FLYBYKNIGHTLIBDEF_H
#include <stdint.h>

//game definition table
#define MASK64    uint64_t
#define PIECE_T   char
#define POS_T     char
#define TURN_T    char
#define STDBOARD  64
//check definition table
#define CHECK_T   char
#define NOCHECK   0x00
#define INCHECK   0x01
//color definition table
#define COLORMASK 0x01
#define WHITE     0x00
#define BLACK     0x01
//initial move status
#define MOVEDMASK 0x10
#define NOTMOVED  0x00
#define HASMOVED  0x10  
//flags
#define EXTRAMASK 0xC0
#define CASTLEKS  0x80
#define CASTLEQS  0x40
//piece type definition table
#define TYPEMASK  0x0E
#define KING      0x00
#define QUEEN     0x02
#define ROOK      0x04
#define BISHOP    0x06
#define KNIGHT    0x08
#define PAWN      0x0A
#define SPARE     0x0C
#define EMPTY     0x0E

typedef struct Game_s{
   PIECE_T board[STDBOARD]; 
   POS_T wKing;
   POS_T bKing;
   MASK64 boardM;
   MASK64 whiteM;
   MASK64 blackM;
   MASK64 moveM[STDBOARD];
   TURN_T turn; 
}Game;

//square value table
#define A1  0
#define B1  1
#define C1  2
#define D1  3
#define E1  4
#define F1  5
#define G1  6
#define H1  7
#define A2  8
#define B2  9
#define C2 10
#define D2 11
#define E2 12
#define F2 13
#define G2 14
#define H2 15
#define A3 16
#define B3 17
#define C3 18
#define D3 19
#define E3 20
#define F3 21
#define G3 22
#define H3 23
#define A4 24
#define B4 25
#define C4 26
#define D4 27
#define E4 28
#define F4 29
#define G4 30
#define H4 31
#define A5 32
#define B5 33
#define C5 34
#define D5 35
#define E5 36
#define F5 37
#define G5 38
#define H5 39
#define A6 40
#define B6 41
#define C6 42
#define D6 43
#define E6 44
#define F6 45
#define G6 46
#define H6 47
#define A7 48
#define B7 49
#define C7 50
#define D7 51
#define E7 52
#define F7 53
#define G7 54
#define H7 55
#define A8 56
#define B8 57
#define C8 58
#define D8 59
#define E8 60
#define F8 61
#define G8 62
#define H8 63
#define XX 64

#endif

