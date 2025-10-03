#include <stdio.h>
#include "functions.c"

int main(){
    charList L;
    int capacity = SIZE;
    initList(&L, capacity);

    printf("=== Insert operations ===\n");
    insertLast(&L, 'A', &capacity);
    insertLast(&L, 'B', &capacity);
    insertLast(&L, 'C', &capacity);
    display(L); // A,B,C

    insertFirst(&L, 'X', &capacity);
    display(L); // X,A,B,C

    insertMiddle(&L, 'M', &capacity);
    display(L); // X,A,M,B,C

    printf("\n=== Delete operations ===\n");
    deleteFirstOccurence(&L, 'A');
    display(L); // X,M,B,C

    deleteLast(&L);
    display(L); // X,M,B

    insertLast(&L, 'B', &capacity);
    insertLast(&L, 'B', &capacity);
    display(L); // X,M,B,B,B

    deleteAllOccurence(&L, 'B');
    display(L); // X,M

    deleteFirst(&L);   // <--- Added here
    display(L);        // M

    printf("\n=== Checks ===\n");
    printf("Is empty? %s\n", isEmpty(L) ? "Yes" : "No");
    printf("Is full? %s\n", isFull(L, capacity) ? "Yes" : "No");
    printf("Is 'M' exist? %s\n", isExist(L, 'M') ? "Yes" : "No");
    printf("Locate 'X': %c\n", locate(L, 'X'));
    printf("Locate 'Z': %c (\\0 means not found)\n", locate(L, 'Z'));

    printf("\n=== Expansion Test ===\n");
    for(int i = 0; i < 20; i++){
        insertLast(&L, 'E', &capacity);  // should trigger realloc
    }
    display(L);

    printf("\n=== Makenull ===\n");
    makenull(&L);
    display(L);

    return 0;
}
