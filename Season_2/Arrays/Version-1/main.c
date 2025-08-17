#include <stdio.h>
#include "functions.h"

int main() {
    charList list;
    initList(&list);

    insertLast(&list, 'A');
    insertLast(&list, 'B');
    insertLast(&list, 'C');
    insertLast(&list, 'D');

    printf("Original List: ");
    display(list);

    printf("Delete all 'B': ");
    deleteAllOccurence(&list, 'B');
    display(list);

    return 0;
}
