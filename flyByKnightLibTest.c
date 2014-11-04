#include "flyByKnightLib.h"
#include "stdio.h"
#include <stdint.h>

int main(){
	char board[STDBOARD];

	standardBoard(board);

	char output[256];
	placePiece(board, KNIGHT|WHITE, A4);

	printBoard(board, output);
	printf("%s\n", output); 
	
	MASK64 mask = blackMask(board);
	printf("%llu \r\n", mask);
	printMask(mask, output);
	printf("%s\n", output); 
	
	return 0;
}
