#include <stdio.h>
#include "functions.c"

int main(){
    charList L;
    initList(&L);

    printf("=== Insert operations ===\n");
    insertLast(&L, 'A');
    insertLast(&L, 'B');
    insertLast(&L, 'C');
    display(L); // A,B,C

    insertFirst(&L, 'X');
    display(L); // X,A,B,C

    insertMiddle(&L, 'M');
    display(L); // X,A,M,B,C

    printf("\n=== Delete operations ===\n");
    deleteFirstOccurence(&L, 'A');
    display(L); // X,M,B,C

    deleteLast(&L);
    display(L); // X,M,B

    insertLast(&L, 'B');
    insertLast(&L, 'B');
    display(L); // X,M,B,B,B

    deleteAllOccurence(&L, 'B');
    display(L); // X,M

    printf("\n=== Checks ===\n");
    printf("Is empty? %s\n", isEmpty(L) ? "Yes" : "No");
    printf("Is full? %s\n", isFull(L) ? "Yes" : "No");
    printf("Is 'M' exist? %s\n", isExist(L, 'M') ? "Yes" : "No");
    printf("Locate 'X': %c\n", locate(L, 'X'));
    printf("Locate 'Z': %c (\\0 means not found)\n", locate(L, 'Z'));

    printf("\n=== Makenull ===\n");
    makenull(&L);
    display(L);

    return 0;
}