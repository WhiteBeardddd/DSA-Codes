#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char SET;   // 8-bit set (0–7)

// Initialize set to empty
void initSet(SET *x) {
    *x = 0;
}

// Insert element into set
void insert(SET *x, int data) {
    if (data < (sizeof(char) * 8)) {
        unsigned char maskValue = 1 << data;
        *x |= maskValue;   // shorthand assignment
    } else {
        printf("Value out of range (0–7)\n");
    }
}

// Delete element from set
void deleteElem(SET *x, int data) {
    if (data < (sizeof(char) * 8)) {
        unsigned char maskValue = 1 << data;
        *x &= ~maskValue;   // clear bit
    }
}

// Check membership
bool isMember(SET x, int data) {
    return (x & (1 << data)) != 0;
}

// Set operations (malloc version)
SET* getUnion(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET));
    *C = A | B;
    return C;
}

SET* getIntersection(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET));
    *C = A & B;
    return C;
}

SET* getDifference(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET));
    *C = A & ~B;
    return C;
}

// Display set elements
void displaySet(SET x) {
    printf("{");
    bool first = true;

    for (int i = 0; i < (sizeof(char) * 8); i++) {
        if (x & (1 << i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }

    printf("}\n");
}

#endif
