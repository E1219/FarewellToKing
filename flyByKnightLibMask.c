//
//FlyByKnightLibMask.c
//FlyByKnightLib 0.0.1 - Chess Library
//Edward Sandor
//January 2015
//
//Conatains implementation of all methods used to generate and manipulate board masks.
//

#include "flyByKnightLibMask.h"

MASK64 boardMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) != EMPTY){
            mask = mask |  (1ULL << i);
        }
    }
   
    return mask;
}

MASK64 whiteMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    for(i=A1;i<STDBOARD;i++){
        if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == WHITE)
            mask = mask | (1ULL << i);
    }
    return mask;
}
MASK64 blackMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    for(i=A1;i<STDBOARD;i++){
        if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == BLACK)
            mask = mask | (1ULL << i);
    }
    return mask;
}

MASK64 moveMask(PIECE_T * piece, POS_T * position, MASK64 * boardM, MASK64 * opponentM){
    MASK64 mask = 0;
    if(((*piece)&TYPEMASK) == PAWN){
        int direction = (((*piece)&COLORMASK) == WHITE)?1:-1; //change direction based on color
        int test = *position + direction*8; //forward/back 1

        if(test < STDBOARD && test >= 0 && ((*boardM & 1ULL << test) == 0)){
            mask |= (1ULL << test);
        
        test = *position + direction*16; //forward/back 2

            if((((*piece)&MOVEDMASK) == NOTMOVED) && test < STDBOARD && test >= 0 && ((*boardM & 1ULL << test) == 0)){
                mask |= (1ULL << test);
            }
        }
        test = *position + direction*9; //capture up-right/down-left diagnol
        if(test < STDBOARD && test >=0 && (*opponentM & 1ULL << test) !=0) {
            mask |= (1ULL << test);
        }
        test = *position + direction*7; //capture up-left/down-right diagnol
        if(test < STDBOARD && test >=0 && (*opponentM & 1ULL << test) !=0) {
            mask |= (1ULL << test);
        }

    }
    else if(((*piece)&TYPEMASK) == KNIGHT){  //generate mask if (*piece) is a knight
        int test = *position+17; //up two and right one
        if(test < STDBOARD && test >=0 && (test%8) > (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position-17; //down two and left one
        if(test < STDBOARD && test >=0 && (test%8) < (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position+15; //up two and left one
        if(test < STDBOARD && test >=0 && (test%8) < (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position-15; //down two and right one
        if(test < STDBOARD && test >=0 && (test%8) > (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position+10; //right two and up one
        if(test < STDBOARD && test >=0 && (test%8) > (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position-10; //left two and down one
        if(test < STDBOARD && test >=0 && (test%8) < (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position+ 6; //left two and up one
        if(test < STDBOARD && test >=0 && (test%8) < (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
        test = *position- 6;  //right two and down one
        if(test < STDBOARD && test >=0 && (test%8) > (*position%8) && 
            ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)) {
            mask |= (1ULL << test);
        }
    }
    else if((((*piece)&TYPEMASK)== BISHOP) || (((*piece)&TYPEMASK) == ROOK) || (((*piece)&TYPEMASK) == QUEEN)|| (((*piece)&TYPEMASK) == KING)){
        if(((*piece)&TYPEMASK) != ROOK){
            int test = *position + 9; //up-right diagnol
            while(test < STDBOARD && test >=0 && (test%8) > (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test += 9;
            }
            test = *position - 9; //down-left diagnol
            while(test < STDBOARD && test >=0 && (test%8) < (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test -= 9;
            }
            test = *position + 7; //up-left diagnol
            while(test < STDBOARD && test >=0 && (test%8) < (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test += 7;
            }
            test = *position - 7; //down-right diagnol
            while(test < STDBOARD && test >=0 && (test%8) > (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test -= 7;
            }
        }
        if(((*piece)&TYPEMASK) != BISHOP){
            int test = *position + 1; //right horizontal 
            while(test < STDBOARD && test >=0 && (test%8) > (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test += 1;
            }
            test = *position - 1; //left horizontal 
            while(test < STDBOARD && test >=0 && (test%8) < (*position%8) &&    ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test -= 1;
            }
            test = *position + 8; //up vertical
            while(test < STDBOARD && test >=0 && ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test += 8;
            }
            test = *position - 8; //down vertical 
            while(test < STDBOARD && test >=0 && ((*boardM & 1ULL << test) == 0 || (*opponentM & 1ULL << test) !=0)){
                mask |= (1ULL << test);
                if(((*piece)&TYPEMASK) == KING || (*boardM & 1ULL << test) != 0)
                    break;
                test -= 8;
            }
        }
    }

    return mask;
}

MASK64 pathMask(PIECE_T * piece, POS_T * target, POS_T * source, MASK64 * moves){
    
    MASK64 mask = 0;   

    if((*moves & (1ULL << *target)) != 0){
        switch(*piece & TYPEMASK){
            case PAWN:
                if((*target-*source) == 16){
                    mask=((1ULL << *target) | (1ULL << (*target - 8)));
                }
                else if((*source-*target) == 16){
                    mask=((1ULL << *target) | (1ULL << (*target + 8)));
                }
                else{
                    mask=(1ULL << *target);
                }
                break;
            case KNIGHT:
            case KING:
                mask = (1ULL << *target);
                break;
            case BISHOP:
            case ROOK:
            case QUEEN:
                if((*target-*source)%9==0){
                    char i;
                    for(i = *target; i>*source; i=i-9)
                        mask |= (1ULL << i);
                    
                    for(i = *target; i<*source; i=i+9)
                        mask |= (1ULL << i);
                }
                else if((*target-*source)%7==0){
                    char i;
                    for(i = *target; i>*source; i=i-7)
                        mask |= (1ULL << i);
                    
                    for(i = *target; i<*source; i=i+7)
                        mask |= (1ULL << i);
                }
                else if((*target-*source)%8==0){
                    char i;
                    for(i = *target; i>*source; i=i-8)
                        mask |= (1ULL << i);
                    for(i = *target; i<*source; i=i+8)
                        mask |= (1ULL << i);
                }
                else {
                    char i;
                    for(i = *target; i>*source; i=i-1)
                        mask |= (1ULL << i);
                    
                    for(i = *target; i<*source; i=i+1)
                        mask |= (1ULL << i);
                }
                break;
            default:
                break;
        }
        mask |= (1ULL << *source);
    } 

    return mask;
}

CHECK_T stripCheck(PIECE_T board[STDBOARD], MASK64 moveM[STDBOARD], MASK64 * playerM, POS_T * kingPos){
    CHECK_T check = NOCHECK;
    MASK64 path;
    MASK64 cross;
    POS_T i;
    for(i = 0; i < STDBOARD; i++){
        path = pathMask(&board[i], kingPos, &i, &moveM[i]);
 
        cross = path & *playerM;
          
        if(path != 0){
        
            POS_T block = XX;
           
            POS_T j;
            uint8_t blockCount = 0;
            for(j = 0; j < STDBOARD; j++){

                if((cross & (1ULL << j)) != 0){
                    if(block != XX){
                        block = XX;
                        break; 
                    }
                    if((board[j] & TYPEMASK) != KING){
                        blockCount++; 
                        block = j;
                    }
                }
            }
            if(block != XX){
                moveM[block] = moveM[block] & path;
            }
            else if(blockCount == 0){
                check = INCHECK;
                for(j = 0; j < STDBOARD; j++){
                    if((board[j] & TYPEMASK )!= KING){
                        moveM[j] = (moveM[j] & path);
                    }
                    else{
                        moveM[j] = (moveM[j] & (~path));
                    }
                }
            }
        }
    }
    return check;
}
