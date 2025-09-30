#include <stdio.h>
#include "functions.h"

int main() {
    SET A, B;
    initSet(&A);
    initSet(&B);

    // A = {0, 4, 6, 7}
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 6);
    insert(&A, 7);

    // B = {1, 4, 5, 6}
    insert(&B, 1);
    insert(&B, 4);
    insert(&B, 5);
    insert(&B, 6);

    // Display sets
    printf("A = ");
    displaySet(A);

    printf("B = ");
    displaySet(B);

    // A UNION B
    SET *Union = getUnion(A, B);
    printf("A u B = ");
    displaySet(*Union);

    // A INTERSECTION B
    SET *Intersection = getIntersection(A, B);
    printf("A n B = ");
    displaySet(*Intersection);

    // A DIFFERENCE B
    SET *Difference = getDifference(A, B);
    printf("A - B = ");
    displaySet(*Difference);

    // free memory
    free(Union);
    free(Intersection);
    free(Difference);

    return 0;
}
