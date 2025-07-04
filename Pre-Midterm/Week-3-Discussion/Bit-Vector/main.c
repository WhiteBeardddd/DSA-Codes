#include <stdio.h>

#define SIZE 8

int main() {
    unsigned char bitVector = 0b00000000;

    // Set the 3rd bit (counting from 0)
    bitVector |= (1 << 3);

    // Check if 3rd bit is set
    if (bitVector & (1 << 3)) {
        printf("Bit 3 is set!\n");
    }

    // Clear the 3rd bit
    bitVector &= ~(1 << 3);

    // Toggle the 2nd bit
    bitVector ^= (1 << 2);

    return 0;
}
