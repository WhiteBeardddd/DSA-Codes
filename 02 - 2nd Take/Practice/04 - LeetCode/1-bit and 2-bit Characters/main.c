#include <stdio.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    for (; i < bitsSize - 1;) {
        if(bits[i] == 1){
            i = i + 2; // skip 2 indeces
        }else{
            i = i + 1; // when its zero
        }
    }

    return i == bitsSize - 1;
}