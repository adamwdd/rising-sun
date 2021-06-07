#include "defs.h"

int convert120To64[boardSquareNum];
int convert64To120[64];

void init120To64() {
    int index = 0;
    int file = fileA;
    int rank = rank1;
    int sq = a1;
    int sq64 = 0;

    for(index = 0; index < boardSquareNum; index++) {
        convert120To64[index] = 65;
    }
        for(index = 0; index < 64; index++) {
        convert64To120[index] = 120;
    }
    for(rank = rank1; rank <= rank8; rank++){
        for(file = fileA; file <= fileH; file++) {
            sq = fileRankToSquare(file, rank);
            convert64To120[sq64] = sq;
            convert120To64[sq] = sq64;
            sq64++;

        }
    }
}

void allInit() {
    init120To64();
}