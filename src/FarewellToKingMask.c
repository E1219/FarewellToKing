//
//FarewellToKingMask.c
//FarewellToKing 0.0.3 - Chess Library
//Edward Sandor
//January 2015
//
//Conatains implementation of all methods used to generate and manipulate board masks.
//

#include "FarewellToKingMask.h"

MASK64 boardMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) != EMPTY){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
   
    return mask;
}

MASK64 whiteMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == WHITE){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 blackMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if(((board[i] & TYPEMASK) != EMPTY) && (board[i] & COLORMASK) == BLACK){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 pawnMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == PAWN){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 knightMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == KNIGHT){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 bishopMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == BISHOP){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 rookMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == ROOK){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 queenMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == QUEEN){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 kingMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == KING){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
MASK64 spareMask(PIECE_T board[STDBOARD]){

    MASK64 mask = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){
        if((board[i] & TYPEMASK) == SPARE){
            mask = mask |  biterator;
        }
        biterator = (biterator << 1);
    }
    return mask;
}
void superMask(PIECE_T board[STDBOARD], MASK64 * boardMask, MASK64 * whiteMask, MASK64 * blackMask, MASK64 * pawnMask, MASK64 * knightMask, MASK64 * bishopMask, MASK64 * rookMask, MASK64 * queenMask, MASK64 * kingMask, MASK64 * spareMask){
    MASK64 boardMaskW  = 0;
    MASK64 whiteMaskW  = 0;
    MASK64 blackMaskW  = 0;
    MASK64 pawnMaskW   = 0;
    MASK64 knightMaskW = 0;
    MASK64 bishopMaskW = 0;
    MASK64 rookMaskW   = 0;
    MASK64 queenMaskW  = 0;
    MASK64 kingMaskW   = 0;
    MASK64 spareMaskW  = 0;

    int i;
    MASK64 biterator = 1ULL;
    for(i=A1;i<STDBOARD;i++){

        if((board[i] & TYPEMASK) != EMPTY){
            boardMaskW |= biterator;
            if((board[i] & COLORMASK) == WHITE)
                whiteMaskW |= biterator;
            else
                blackMaskW |= biterator;
            switch((board[i] & TYPEMASK)){
                case PAWN:
                    pawnMaskW |= biterator;
                    break;
                case KNIGHT:
                    knightMaskW |= biterator;
                    break;
                case BISHOP:
                    bishopMaskW |= biterator;
                    break;
                case ROOK:
                    rookMaskW |= biterator;
                    break;
                case QUEEN:
                    queenMaskW |= biterator;
                    break;
                case KING:
                    kingMaskW |= biterator;
                    break;
                case SPARE:
                    spareMaskW |= biterator;
                    break;
                default:
                    break;
            }
        }
        biterator = biterator << 1;
    }

    *boardMask  = boardMaskW;
    *whiteMask  = whiteMaskW;
    *blackMask  = blackMaskW;
    *pawnMask   = pawnMaskW;
    *knightMask = knightMaskW;
    *bishopMask = bishopMaskW;
    *rookMask   = rookMaskW;
    *queenMask  = queenMaskW;
    *kingMask   = kingMaskW;
    *spareMask  = spareMaskW;

}

MASK64 moveMask(PIECE_T * piece, POS_T * position, MASK64 * boardM, MASK64 * opponentM, POS_T * ep){
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
        if(test < STDBOARD && test >=0 && ((*opponentM & 1ULL << test) !=0 || test == *ep)) {
            mask |= (1ULL << test);
        }
        test = *position + direction*7; //capture up-left/down-right diagnol
        if(test < STDBOARD && test >=0 && ((*opponentM & 1ULL << test) !=0 || test == *ep)) {
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

void addCastle(PIECE_T board[STDBOARD], MASK64 moveM[STDBOARD], MASK64 * whiteM, MASK64 * blackM, TURN_T * turn){
    char castle = 0;
    MASK64 QS;
    MASK64 KS;
    POS_T i = 0;
    if(*turn == WHITE){
        if(board[E1] == (NOTMOVED | KING | WHITE)){
            castle = WCKS | WCQS;
        }

        QS = (1ULL << C1) | (1ULL << D1);
        KS = (1ULL << F1) | (1ULL << G1);

        if((((1ULL << B1) | QS) & (*whiteM | *blackM)) != 0 || (board[A1] != (NOTMOVED | ROOK | WHITE))){
            castle &= ~WCQS;
        }
        if((KS & (*whiteM | *blackM)) != 0 || (board[H1] != (NOTMOVED | ROOK | WHITE))){
            castle &= ~WCKS;
        }

        for(i = 0; i < STDBOARD && castle != 0; i++){
            if((board[i] & COLORMASK) == BLACK){
                if( (((QS | KS | E8) & moveM[i]) != 0)){
                    POS_T pos = E1;
                    if( (pathMask(&board[i], &pos, &i, &moveM[i]) & *whiteM) == 0){
                        castle &= ~WCKS;
                        castle &= ~WCQS;
                    } 
                    pos = C1;
                    if( (pathMask(&board[i], &pos, &i, &moveM[i]) & *whiteM) == 0){
                        castle &= ~WCQS;
                    } 
                    pos = D1;
                    if( (pathMask(&board[i], &pos, &i, &moveM[i]) & *whiteM) == 0){
                        castle &= ~WCQS;
                    } 
                    pos = F1;
                    if( (pathMask(&board[i], &pos, &i, &moveM[i]) & *whiteM) == 0){
                        castle &= ~WCKS;
                    } 
                    pos = G1;
                    if( (pathMask(&board[i], &pos, &i, &moveM[i]) & *whiteM) == 0){
                        castle &= ~WCKS;
                    } 

                }
            }
        }
    }
    else{
        if(board[E8] == (NOTMOVED | KING | BLACK)){
            castle = BCKS | BCQS;
        }

        QS = (1ULL << C8) | (1ULL << D8);
        KS = (1ULL << F8) | (1ULL << G8);

        if((((1ULL << B8) | QS) & (*whiteM | *blackM)) != 0 || (board[A8] != (NOTMOVED | ROOK | BLACK))){
            castle &= ~BCQS;
        }
        if((KS & (*whiteM | *blackM)) != 0 || (board[H8] != (NOTMOVED | ROOK | BLACK))){
            castle &= ~BCKS;
        }

        for(i = 0; i < STDBOARD && castle != 0; i++){
            if(board[i] & COLORMASK == WHITE){
                if( (((QS | KS | E8) & moveM[i]) != 0)){
                    POS_T pos = E8;
                    if( pathMask(&board[i], &pos, &i, &moveM[i]) & *blackM == 0){
                        castle &= ~BCKS;
                        castle &= ~BCQS;
                    } 
                    pos = C8;
                    if( pathMask(&board[i], &pos, &i, &moveM[i]) & *blackM == 0){
                        castle &= ~BCQS;
                    } 
                    pos = D8;
                    if( pathMask(&board[i], &pos, &i, &moveM[i]) & *blackM == 0){
                        castle &= ~BCQS;
                    } 
                    pos = F8;
                    if( pathMask(&board[i], &pos, &i, &moveM[i]) & *blackM == 0){
                        castle &= ~BCKS;
                    } 
                    pos = G8;
                    if( pathMask(&board[i], &pos, &i, &moveM[i]) & *blackM == 0){
                        castle &= ~BCKS;
                    } 

                }
            }
        }
    }
    if((castle & WCKS) == WCKS){
        moveM[E1] |= (1ULL << G1);
    }
    if((castle & WCQS) == WCQS){
        moveM[E1] |= (1ULL << C1);
    }
    if((castle & BCKS) == BCKS){
        moveM[E8] |= (1ULL << G8);
    }
    if((castle & BCQS) == BCQS){
        moveM[E8] |= (1ULL << C8);
    }
}
