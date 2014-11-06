//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014
//

#include "flyByKnightLib.h"

int main(){
	char testSquare = D4;
	char board[STDBOARD];

	standardBoard(board);

	char output[256];
	placePiece(board, NOTMOVED|QUEEN|WHITE, testSquare);
	//placePiece(board, SPARE|WHITE, G7);

	printBoard(board, output);
	printf("\n%s\n", output); 
	
	MASK64 boardM = boardMask(board);
	MASK64 opponentM = blackMask(board);
	MASK64 mask = moveMask(board[testSquare], testSquare,boardM,opponentM);
	printMask(mask, output);
	printf("%s\n", output); 
	
	return 0;
}
