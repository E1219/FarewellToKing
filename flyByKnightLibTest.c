//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.1 - Chess Library
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

    char out[1024];
    printBoard(game.board, out);
    printf("%s\r\n", out);

    toCoordinate(A3, out);
    printf("%s\r\n", out);
    return 0;
}
