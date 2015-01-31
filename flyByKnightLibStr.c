//
//FlyByKnightLibStr.h
//FlyByKnightLib 0.0.2 - Chess Library
//Edward Sandor
//January 2015
//
//Contains implementations of all methods that generate formatted strings for human readable output.
//

#include "flyByKnightLibStr.h"
#define true false

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
           return (PAWN   | WHITE | HASMOVED);
           break;
       case 'p':
           return (PAWN   | BLACK | HASMOVED);
           break;
       case 'N':
           return (KNIGHT | WHITE | HASMOVED);
           break;
       case 'n':
           return (KNIGHT | BLACK | HASMOVED);
           break;
       case 'B':
           return (BISHOP | WHITE | HASMOVED);
           break;
       case 'b':
           return (BISHOP | BLACK | HASMOVED);
           break;
       case 'R':
           return (ROOK   | WHITE | HASMOVED);
           break;
       case 'r':
           return (ROOK   | BLACK | HASMOVED);
           break;
       case 'Q':
           return (QUEEN  | WHITE | HASMOVED);
           break;
       case 'q':
           return (QUEEN  | BLACK | HASMOVED);
           break;
       case 'K':
           return (KING   | WHITE | HASMOVED);
           break;
       case 'k':
           return (KING   | BLACK | HASMOVED);
           break;
       case 'S':
           return (SPARE  | WHITE | HASMOVED);
           break;
       case 's':
           return (SPARE  | BLACK | HASMOVED);
           break;
       default:
           return (EMPTY);
           break;
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
            extraT |= WCKS;
        else
            extraT |= WCQS;
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
    *extra=extraT;
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
void getFEN(Game * game, char output[]){
    int i;
    int j;
    for(i = 0; i < 86; i++){
        output[i] = 0;
    }

    int outI  = 0;
    for(i = 7; i >= 0; i--){
        int count = 0;

        for(j = 0; j < 8; j++){
            if((game->board[i*8+j] & TYPEMASK) == EMPTY){
                count++;
            }
            else{
                if(count != 0){
                    output[outI] = '0' + count;
                    outI++;
                }
                count = 0;
                output[outI] = toCharPiece(game->board[i*8+j]);
                outI++;
            }
        }
        if(count != 0){
            output[outI] = '0' + count;
            outI++;
        }
        if(i != 0){
            output[outI] = '/';
            outI++;
        }
    }
    output[outI] = ' ';
    outI++;
    if((game->turn & COLORMASK) == WHITE){
        output[outI] = 'w';
        outI++;
    }
    else{
        output[outI] = 'b';
        outI++;
    }
    output[outI] = ' ';
    outI++;
    char castle = 1;
    if(((game->board[E1] & (TYPEMASK | COLORMASK)) == (KING | WHITE)) && 
       ((game->board[H1] & (TYPEMASK | COLORMASK)) == (ROOK | WHITE))){
        output[outI] = 'K';
        outI++;
        castle = 0;
    }
    if(((game->board[E1] & (TYPEMASK | COLORMASK)) == (KING | WHITE)) && 
       ((game->board[A1] & (TYPEMASK | COLORMASK)) == (ROOK | WHITE))){
        output[outI] = 'Q';
        outI++;
        castle = 0;
    }
    if(((game->board[E8] & (TYPEMASK | COLORMASK)) == (KING | BLACK)) && 
       ((game->board[H8] & (TYPEMASK | COLORMASK)) == (ROOK | BLACK))){
        output[outI] = 'k';
        outI++;
        castle = 0;
    }
    if(((game->board[E8] & (TYPEMASK | COLORMASK)) == (KING | BLACK)) && 
       ((game->board[A8] & (TYPEMASK | COLORMASK)) == (ROOK | BLACK))){
        output[outI] = 'q';
        outI++;
        castle = 0;
    }
    if(castle == 1){
        output[outI] = '-';
        outI++;
    }
    output[outI] = ' ';
    outI++;
    if(game->ep != XX){
        char ep[8];
        toCoordinate(game->ep, ep);
        output[outI] = ep[0];
        outI++;
        output[outI] = ep[1];
        outI++;
    }
    else{
        output[outI] = '-';
        outI++;
    }
    output[outI] = ' ';
    outI++;
    int digits = 0;
    int num = game->halfmove;
    if(game->halfmove != 0){
        while(num != 0){
            digits++;
            num /= 10;
        }
        for(i = 0; i < digits; i++){
            num = game->halfmove;
            for(j = i + 1; j < digits; j++){
                num /= 10;
            }
            output[outI] = num%10 + '0';
            outI++;
        }
    }
    else{
        output[outI] = '0';
        outI++;
    }
    output[outI] = ' ';
    outI++;
    digits = 0;
    if(game->fullmove != 0){
        num = game->fullmove;
        while(num != 0){
            digits++;
            num /= 10;
        }
        for(i = 0; i < digits; i++){
            num = game->fullmove;
            for(j = i + 1; j < digits; j++){
                num /= 10;
            }
            output[outI] = num%10 + '0';
            outI++;
        }
    }
    else{
        output[outI] = '0';
        outI++;
    }
    output[outI] = ' ';
    outI++;
}
void beginFENGame(Game * game, char fen[]){

    int inI = 0;

    POS_T squareI;
    
    int i;

    for(i = 0; i < STDBOARD; i++){
        game->board[i] = EMPTY;
    }

    for(i = 0; i < 8; i++){
        squareI = 56 - 8*i;
        while(fen[inI] != '/' && fen[inI] != ' '){
            if(fen[inI] > '0' && fen[inI] <= '8'){            
                squareI += (fen[inI] - '0');
            }
            else{
                 game->board[squareI] = toPiece(fen[inI]); 
                 if((game->board[squareI] & TYPEMASK) == PAWN){
                     if(((game->board[squareI] & COLORMASK) == WHITE) && i == 6){
                        game->board[squareI] = (game->board[squareI] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                     }
                     else if(((game->board[squareI] & COLORMASK) == BLACK) && i == 1){
                        game->board[squareI] = (game->board[squareI] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                     }
                     else{
                        game->board[squareI] = (game->board[squareI] & (TYPEMASK | COLORMASK)) | HASMOVED;
                     }
                 }
                 squareI++;
            }
            inI++;
        }
        inI++;
    }

    if(fen[inI] == 'w')
        game->turn = WHITE;
    else
        game->turn = BLACK;

    inI += 2;

    if(fen[inI] == '-'){
        inI += 2;
    }
    else{
        while(fen[inI] != ' '){
            switch (fen[inI]){
                case 'K':
                    game->board[E1] = (game->board[E1] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                    game->board[H1] = (game->board[H1] & (TYPEMASK | COLORMASK)) | NOTMOVED;                   
                    break;
                case 'Q':
                    game->board[E1] = (game->board[E1] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                    game->board[A1] = (game->board[A1] & (TYPEMASK | COLORMASK)) | NOTMOVED;                   
                    break;
                case 'k':
                    game->board[E8] = (game->board[E8] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                    game->board[H8] = (game->board[H8] & (TYPEMASK | COLORMASK)) | NOTMOVED;                   
                    break;
                case 'q':
                    game->board[E8] = (game->board[E8] & (TYPEMASK | COLORMASK)) | NOTMOVED;
                    game->board[A8] = (game->board[A8] & (TYPEMASK | COLORMASK)) | NOTMOVED;                   
                    break;
                defualt:
                    break;
            }
            inI++;
        }
    }
    inI++;

    if(fen[inI] != '-'){
        char pos[3];
        pos[0] = fen[inI];
        inI++;
        pos[1] = fen[inI];
        inI++;
        pos[2] = 0;
        game->ep = toPos(pos);
    }
    else{
        inI++;
    }
    inI++;
    int count = 0;
    while(fen[inI] >= '0' && fen[inI] <= '9'){
        count = (count*10) + (fen[inI] - '0');
        inI++;
    }
    game->halfmove = count;

    inI++;

    count = 0;
    while(fen[inI] >= '0' && fen[inI] <= '9'){
        count = (count*10) + (fen[inI] - '0');
        inI++;
    }
    game->fullmove = count;
}






