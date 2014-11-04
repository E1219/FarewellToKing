#include "flyByKnightLib.h"

void emptyBoard(char board [STDBOARD]){
	int i;
	for(i = 0; i < STDBOARD; i++){
		board[i] = EMPTY;
	}

	return;
}
void standardBoard(char board [STDBOARD]){
	int i;
	for(i = A1; i < STDBOARD; i++){
		board[i] = EMPTY;
	}
	for(i = A2; i<=H2; i++){
		board[i]=PAWN|WHITE;	
	}
	for(i = A7; i<=H7; i++){
		board[i]=PAWN|BLACK;
	}
	
	board[A1] = ROOK   |WHITE;
	board[B1] = KNIGHT |WHITE;
	board[C1] = BISHOP |WHITE;
	board[D1] = QUEEN  |WHITE;
	board[E1] = KING   |WHITE;
	board[F1] = BISHOP |WHITE;
	board[G1] = KNIGHT |WHITE;
	board[H1] = ROOK   |WHITE;

	board[A8] = ROOK   |BLACK;
	board[B8] = KNIGHT |BLACK;
	board[C8] = BISHOP |BLACK;
	board[D8] = QUEEN  |BLACK;
	board[E8] = KING   |BLACK;
	board[F8] = BISHOP |BLACK;
	board[G8] = KNIGHT |BLACK;
	board[H8] = ROOK   |BLACK;

	return;
}

char placePiece(char board[STDBOARD], char newPiece, char position){
	char old = board[position];
	board[position] = newPiece;

	return old;
}

MASK64 boardMask(char board[STDBOARD]){

	MASK64 mask = 0;

	int i;
	for(i=A1;i<STDBOARD;i++){
		if((board[i] & TYPEMASK) != EMPTY){
			mask = mask |  (1ULL << i);
		}
	}
	return mask;
}

MASK64 whiteMask(char board[STDBOARD]){

	MASK64 mask = 0;

	int i;
	for(i=A1;i<STDBOARD;i++){
		if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == WHITE)
			mask = mask | (1ULL << i);
	}
	return mask;
}

MASK64 blackMask(char board[STDBOARD]){

	MASK64 mask = 0;

	int i;
	for(i=A1;i<STDBOARD;i++){
		if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == BLACK)
			mask = mask | (1ULL << i);
	}
	return mask;
}
void printMask(long long int mask, char output[]){
	char ret[144];	//(2*8 columns + '\r\n')*8rows 
	
	int i;
	for(i = 0; i<144; i++)
		ret[i] = ' ';
	for(i = 0; i<8; i++){
		ret[(i*(17)+15)] = '\r';
		ret[(i*(17)+16)] = '\n';
	}	

	for(i = A1; i<STDBOARD; i++){
		char name = ' ';
		if((mask & (1ULL<<i)) != 0)
			name = '1';
		else
			name = (((i+(i/8))%2)?'.':'#');

		int j = STDBOARD-i-1;
		int k = (-(j%8)+7);
		j= j + (k-(j%8));
		ret[((j*2) + (j/8))] = name;
	
	}
	ret[143] = '\0';
	for(i = 0; i < 144; i++)
		output[i]=ret[i];
}
void printBoard(char board [STDBOARD], char output[]){
	char ret[144];	//(2*8 columns + '\r\n')*8rows 
	
	int i;
	for(i = 0; i<144; i++)
		ret[i] = ' ';
	for(i = 0; i<8; i++){
		ret[(i*(17)+15)] = '\r';
		ret[(i*(17)+16)] = '\n';
	}	

	for(i = A1; i<STDBOARD; i++){
		char name;	
		switch ((board[i] & (TYPEMASK | COLORMASK))){
			case (KING | WHITE):
				name = 'K';
				break;
			case (KING | BLACK):
				name = 'k';
				break;
			case (QUEEN | WHITE):
				name = 'Q';
				break;
			case (QUEEN | BLACK):
				name = 'q';
				break;
			case (ROOK | WHITE):
				name = 'R';
				break;
			case (ROOK | BLACK):
				name = 'r';
				break;
			case (BISHOP | WHITE):
				name = 'B';
				break;
			case (BISHOP | BLACK):
				name = 'b';
				break;
			case (KNIGHT | WHITE):
				name = 'N';
				break;
			case (KNIGHT | BLACK):
				name = 'n';
				break;
			case (PAWN | WHITE):
				name = 'P';
				break;
			case (PAWN | BLACK):
				name = 'p';
				break;
			case (SPARE | WHITE):
				name = 'S';
				break;
			case (SPARE | BLACK):
				name = 's';
				break;
			case (EMPTY | WHITE):
			case (EMPTY | BLACK):
			default:
				name = (((i+(i/8))%2)?'.':'#');
				break;
		}
		int j = STDBOARD-i-1;
		int k = (-(j%8)+7);
		j= j + (k-(j%8));
		ret[((j*2) + (j/8))] = name;
	}
	ret[143] = '\0';
	for(i = 0; i < 144; i++)
		output[i]=ret[i];
}
