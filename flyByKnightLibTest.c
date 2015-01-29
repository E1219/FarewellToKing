//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.2 - Chess Library
//Edward Sandor
//November 2014 - 2015
//
//Main function can be used to test different aspects of FlyByKnightLib
//

#include <stdio.h>
#include "flyByKnightLib.h"
#include "flyByKnightLibStr.h"

int main(){
    Game game;
    beginStandardGame(&game);

    char input[128];
    char out[1024];
    for(;;){
        printBoard(&game, out);
        printf("%s\r\n%d\n\n", out,game.turn);

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
