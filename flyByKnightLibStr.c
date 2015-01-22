//
//FlyByKnightLibStr.h
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Contains implementations of all methods that generate formatted strings for human readable output.
//

#include "flyByKnightLibStr.h"

POS_T toPos(char input[3]){
    if(input[0] >= 'A' && input[0] <= 'H' && input[1] >= '1' && input[1] <= '8')
        return (input[1] - '1')*8 + (input[0] - 'A');
    else if(input[0] >= 'a' && input[0] <= 'h' && input[1] >= '1' && input[1] <= '8')
        return (input[1] - '1')*8 + (input[0] - 'a');
    else
        return XX;
}
void toCoordinate(POS_T square, char coordinate[]){
    if(square != XX){
        coordinate[0] = (square % 8) + 'a';
        coordinate[1] = (square / 8) + '1';
        coordinate[2] = 0;
    }
    else{
        coordinate[0] = 'X';
        coordinate[1] = 'X';
        coordinate[2] =  0 ;
    }
}
PIECE_T toPiece(char input){
   switch(input){
       case 'P':
       case 'p':
           return PAWN;
           break;
       case 'N':
       case 'n':
           return KNIGHT;
           break;
       case 'B':
       case 'b':
           return BISHOP;
           break;
       case 'R':
       case 'r':
           return ROOK;
           break;
       case 'Q':
       case 'q':
           return QUEEN;
           break;
       case 'K':
       case 'k':
           return KING;
           break;
       case 'S':
       case 's':
           return SPARE;
       default:
           return EMPTY;
   } 
}
char toCharPiece(PIECE_T piece){
    switch((piece & TYPEMASK)){
        case PAWN:
            return (piece & COLORMASK)==WHITE?'P':'p';
            break;
        case KNIGHT:
            return (piece & COLORMASK)==WHITE?'N':'n';
            break;
        case BISHOP:
            return (piece & COLORMASK)==WHITE?'B':'b';
            break;
        case ROOK:
            return (piece & COLORMASK)==WHITE?'R':'r';
            break;
        case QUEEN:
            return (piece & COLORMASK)==WHITE?'Q':'q';
            break;
        case KING:
            return (piece & COLORMASK)==WHITE?'K':'k';
            break;
        case SPARE:
            return (piece & COLORMASK)==WHITE?'S':'s';
            break;
  }
}

void xboardMove(char input[8], POS_T * target, POS_T * source, char * extra){

    char extraT = 0;
    int inputSize = 0;

    for(inputSize = 0; input[inputSize] != 0; inputSize++);
    if(input[0] == '0'){
        if(inputSize == 3)
            extraT |= CASTLEKS;
        else
            extraT |= CASTLEQS;
    }
    else if(input[1] == '@'){
        *source = XX;
        if(input[0] == '@'){
            *target = XX;
        }
        else{
            char coord[3];
            coord[0]= input[2];
            coord[1]= input[3];
            coord[2]= 0;
            *target = toPos(coord);
        }
        extraT |= toPiece(input[0]);
    }
    else if(inputSize >= 4){
        char coord[5];
        coord[0] = input[0];
        coord[1] = input[1];
        coord[2] = 0;
        *source  = toPos(coord); 

        coord[0] = input[2];
        coord[1] = input[3];
        coord[2] = 0;
        *target  = toPos(coord); 
        if(inputSize == 5)
            extraT |= toPiece(input[4]);
    }
    else{
        extraT=0xFF;
    }
    extra=&extraT;
}

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

