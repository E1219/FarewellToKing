//
//farewell_to_king_types.h
//Farewell To King - Chess Library
//Edward Sandor
//November 2014 - 2020
//
//Contains all type, constant, and structure definitions to be used used by FarewellToKing.
//

#ifndef _FAREWELL_TO_KING_TYPES_H_
#define _FAREWELL_TO_KING_TYPES_H_
#include <stdint.h>

// Game definition 
// Board bit mask
typedef uint64_t   ftk_board_mask_t;
// Piece type
typedef char       PIECE_T;
// Position type
typedef char       POS_T;
// Turn type
typedef char       TURN_T;
// Castle type
typedef char       CASTLE_T;
// Standard board size
#define ftk_std_board_x 8
#define ftk_std_board_y 8
#define STDBOARD   (ftk_std_board_x*ftk_std_board_y)


// Check Definitions
// Check enum
typedef enum
{
    FTK_CHECK_NO_CHECK,
    FTK_CHECK_IN_CHECK,
    FTK_CHECK_UNKNOWN,
} ftk_check_e;

// Check type (to deprecate)
typedef ftk_check_e CHECK_T;
#define NOCHECK    0x00
#define INCHECK    0x01

//color definition table
#define COLORMASK  0x01
#define WHITE      0x00
#define BLACK      0x01
//initial move status
#define MOVEDMASK  0x10
#define NOTMOVED   0x00
#define HASMOVED   0x10  
//castle status
#define CASTLEMASK 0x0F
#define WCKS       0x01
#define WCQS       0x02
#define BCKS       0x04
#define BCQS       0x08
//piece type definition table
#define TYPEMASK   0x0E
#define KING       0x00
#define QUEEN      0x02
#define ROOK       0x04
#define BISHOP     0x06
#define KNIGHT     0x08
#define PAWN       0x0A
#define SPARE      0x0C
#define EMPTY      0x0E

typedef struct Game_s{
   PIECE_T board[STDBOARD]; 

   POS_T wKing;
   POS_T bKing;
   POS_T ep;

   ftk_board_mask_t boardM;
   ftk_board_mask_t whiteM;
   ftk_board_mask_t blackM;
   ftk_board_mask_t pawnM;
   ftk_board_mask_t knightM;
   ftk_board_mask_t bishopM;
   ftk_board_mask_t rookM;
   ftk_board_mask_t queenM;
   ftk_board_mask_t kingM;
   ftk_board_mask_t spareM;
   ftk_board_mask_t moveM[STDBOARD];

   TURN_T turn; 
   int halfmove;
   int fullmove;
}Game;

typedef struct move_s{
    POS_T   target;
    POS_T   source;

    PIECE_T moved;    
    PIECE_T capture;

    POS_T   ep;

    TURN_T  turn;
    int     halfmove;
    int     fullmove;
}Move;

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

