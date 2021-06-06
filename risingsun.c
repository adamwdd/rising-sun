#include "stdio.h"
#include "defs.h"

int main() {
    allInit();
    int index = 0;
    
    for(index = 0; index < boardSquareNum; ++index) {
        if(index%10==0) printf("\n");
        printf("%5d", convert120To64[index]);
    }

    printf("\n");
    printf("\n");

    for(index=0; index < 64; ++index) {
        if(index%8==0) printf("\n");
        printf("%5d", convert64To120[index]);
    }
    return 0;
}