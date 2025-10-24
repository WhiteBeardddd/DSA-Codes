#include <stdio.h>

int reverseBits(int n) {
    unsigned int mask = (unsigned int)n; // typecast int to unsigned to safely manipulate bits
    unsigned int retVal = 0;             // accumulator for reversed bits, initially 0

    for(int i = 0; i < 32; i++){
        retVal <<= 1;                     // shift rev left by 1 to make room for next bit
        retVal = retVal | (mask & 1);     // take LSB of mask (rightmost bit) and append to rev
        mask >>= 1;                        // shift mask right by 1 to process next bit in next iteration
    }

    return (int)retVal;                   // cast back to signed int for return
}
