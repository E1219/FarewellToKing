#include "flyByKnightLib.h"
#include "stdio.h"

int main(){
	char board[STDBOARD];

	standardBoard(board);

	char output[256];
	printBoard(board, output);
	printf("%s", output); 
	
	return 0;
}
