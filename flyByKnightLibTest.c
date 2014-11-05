//
//FlyByKnightLibTest.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//November 2014
//

#include "flyByKnightLib.h"

int main(){
	char testSquare = B4;
	char board[STDBOARD];

	emptyBoard(board);

	char output[256];
	placePiece(board, KNIGHT|WHITE, testSquare);
	placePiece(board, PAWN  |WHITE, C2);

	printBoard(board, output);
	printf("%s\n", output); 
	
	MASK64 boardM = boardMask(board);
	MASK64 opponentM = blackMask(board);
	MASK64 mask = moveMask(board[testSquare], testSquare,boardM,opponentM);
	printMask(mask, output);
	printf("%s\n", output); 
	
	return 0;
}
