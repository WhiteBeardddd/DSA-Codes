#include <stdio.h>
#include "functions.c"


int main(){
    int capacity = SIZE;
    charList *List = initList(capacity); // list created dynamically

    printf("=== Insert operations ===\n");
    insertLast(List, 'A', &capacity);
    insertLast(List, 'B', &capacity);
    insertLast(List, 'C', &capacity);
    display(List); // A,B,C

    insertFirst(List, 'X', &capacity);
    display(List); // X,A,B,C

    insertMiddle(List, 'M', &capacity);
    display(List); // X,A,M,B,C

    printf("\n=== Delete operations ===\n");
    deleteFirstOccurence(List, 'A');
    display(List); // X,M,B,C

    deleteLast(List);
    display(List); // X,M,B

    insertLast(List, 'B', &capacity);
    insertLast(List, 'B', &capacity);
    display(List); // X,M,B,B,B

    deleteAllOccurence(List, 'B');
    display(List); // X,M

    deleteFirst(List);
    display(List); // M

    printf("\n=== Checks ===\n");
    printf("Is empty? %s\n", isEmpty(List) ? "Yes" : "No");
    printf("Is full? %s\n", isFull(List, capacity) ? "Yes" : "No");
    printf("Is 'M' exist? %s\n", isExist(List, 'M') ? "Yes" : "No");
    printf("Locate 'X': %c\n", locate(List, 'X'));
    printf("Locate 'Z': %c (\\0 means not found)\n", locate(List, 'Z'));

    printf("\n=== Expansion Test ===\n");
    for(int i = 0; i < 20; i++){
        insertLast(List, 'E', &capacity); // triggers realloc
    }
    display(List);

    printf("\n=== Makenull ===\n");
    makenull(List);
    display(List);

    free(List); // free main list struct
    return 0;
}
