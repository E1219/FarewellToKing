//
//FarewellToKingTest.c
//FarewellToKing 0.0.3 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Main function can be used to test different aspects of FarewellToKing
//

#include <stdio.h>
#include "FarewellToKing.h"
#include "FarewellToKingStr.h"

int main(){
    Game game;
    beginStandardGame(&game);

    char input[128];
    char out[1024];
    for(;;){
        //printBoard(game.board, out);
        printBoardC(game.board, out); 
        printf("%s\r\n", out);

//        printMaskC(&game.moveM[E1], out);
//        printf("%s\r\n", out);

        getFEN(&game,out);
        printf("%s\r\n", out);

        scanf("%s", input);

        if(strcmp("q",input) == 0 || strcmp("quit",input)==0)
            break;

        POS_T t = XX;
        POS_T s = XX;
        POS_T * target = &t;
        POS_T * source = &s;
        char e = 0;
        char * extra = &e;
        xboardMove(input, target, source, extra);
        movePiece(&game, target, source);
    }

    return 0;
}
