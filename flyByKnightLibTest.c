//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014 - 2015
//

#include <stdio.h>
#include "flyByKnightLib.h"

int main(){
    Game game;
    beginStandardGame(&game);

    char out[1024];
    printBoard(game.board, out);
    printf("%s\r\n", out);

    printMask(&game.moveM[D7], out);
    printf("%s", out);

    return 0;
}
