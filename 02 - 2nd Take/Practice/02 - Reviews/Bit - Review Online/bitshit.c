#include <stdio.h>
#include <math.h>

// Helper function to invert a bit character
char invert(char bit) {
    return (bit == '0') ? '1' : '0';
}

// Recursive function to find the kth bit in S_n
char findKthBit(int n, int k) {
    // Base case: S1 = "0"
    if (n == 1)
        return '0';

    int mid = pow(2, n - 1); // middle position = 2^(n-1)
    int length = pow(2, n) - 1; // total length of S_n = 2^n - 1

    if (k == mid)
        return '1'; // middle bit is always 1

    else if (k < mid)
        return findKthBit(n - 1, k); // on the left side

    else {
        // mirrored position from right side
        int mirror = length - k + 1;
        char bit = findKthBit(n - 1, mirror);
        return invert(bit); // invert the mirrored bit
    }
}

// --- MAIN TEST PROGRAM ---
int main() {
    int n, k;

    // Example 1:
    n = 3;
    k = 1;
    printf("Example 1: n=%d, k=%d -> %c\n", n, k, findKthBit(n, k));

    // Example 2:
    n = 4;
    k = 11;
    printf("Example 2: n=%d, k=%d -> %c\n", n, k, findKthBit(n, k));

    // You can test more cases:
    n = 4;
    k = 8;
    printf("Middle bit test: n=%d, k=%d -> %c\n", n, k, findKthBit(n, k));

    return 0;
}