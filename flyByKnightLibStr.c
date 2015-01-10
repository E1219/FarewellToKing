//
//FlyByKnightLibStr.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Contains implementations of all methods that generate formatted strings for human readable output.
//

#include "flyByKnightLibStr.h"

void printMask(MASK64 * mask, char output[]){
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
 		if((*mask & (1ULL<<i)) != 0)
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
void printBoard(PIECE_T board [STDBOARD], char output[]){
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

void printMaskC(MASK64 * mask, char output[]){
    char ret[210];   //('a  ' + 2*8 columns + '\r\n')*10rows 
    
    int i;
    for(i = 0; i<210; i++)
        ret[i] = ' ';
    for(i = 0; i<10; i++){
        ret[(i*(20)+18)] = '\r';
        ret[(i*(20)+19)] = '\n';
        if(i<8)
            ret[(i*20)] = '8' - i;
    }   

    for(i = A1; i<STDBOARD; i++){
        char name = ' ';
        if((* mask & (1ULL<<i)) != 0)
            name = '1';
        else
            name = (((i+(i/8))%2)?'.':'#');

        int j = STDBOARD-i-1;
        int k = (-(j%8)+7);
        j= j + (k-(j%8));
        ret[((j*2) + (j/8)+(j/8+1)*3)] = name;
    
    }
    for(i = STDBOARD+8; i < STDBOARD+16; i++){
        ret[((i*2) + (i/8)+(i/8+1)*3)] = 'a' + i-8-STDBOARD;
    }
    ret[209] = '\0';
    for(i = 0; i < 210; i++)
        output[i]=ret[i];
}
void printBoardC(PIECE_T board [STDBOARD], char output[]){
    char ret[210];  //('a  ' + 2*8 columns + '\r\n')*10rows 
    
    int i;
    for(i = 0; i<210; i++)
        ret[i] = ' ';
    for(i = 0; i<10; i++){
        ret[(i*(20)+18)] = '\r';
        ret[(i*(20)+19)] = '\n';
        if(i<8)
            ret[(i*20)] = '8' - i;
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
        ret[((j*2) + (j/8)+(j/8+1)*3)] = name;
    }
    for(i = STDBOARD+8; i < STDBOARD+16; i++){
ret[((i*2) + (i/8)+(i/8+1)*3)] = 'a' + i-8-STDBOARD;
    }
    ret[209] = '\0';
    for(i = 0; i < 210; i++)
        output[i]=ret[i];
}

