#include <stdio.h>
#include <stdbool.h>

typedef unsigned int BIT;


bool isEvenBit(BIT x){
    return (x & 1) == 0;
}

bool isPowerOfTwo(BIT x){
    return x != 0 && (x & (x & 1)) == 0;
}

// 1️⃣ Check if the k-th bit is set
bool isKthBitSet(BIT x, int k) {
    return (x & (1 << k)) != 0;
}

// 2️⃣ Set the k-th bit
BIT setKthBit(BIT x, int k) {
    return x | (1 << k);
}

// 3️⃣ Unset (clear) the k-th bit
BIT unsetKthBit(BIT x, int k) {
    return x & ~(1 << k);
}

// 4️⃣ Toggle (flip) the k-th bit
BIT toggleKthBit(BIT x, int k) {
    return x ^ (1 << k);
}



