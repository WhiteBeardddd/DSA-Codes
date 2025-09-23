// main.c
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    charList list;
    initList(&list);

    // Insert some elements
    insertLast(list, 'A');
    insertLast(list, 'B');
    insertLast(list, 'C');
    insertLast(list, 'D');
    printf("Original List: ");
    display(list);

    // Test insertFirst
    printf("Insert 'X' at First: ");
    insertFirst(list, 'X');
    display(list);

    // Test insertMiddle
    printf("Insert 'Y' in Middle: ");
    insertMiddle(list, 'Y');
    display(list);

    // Test deleteFirstOccurrence
    printf("Delete first occurrence of 'B': ");
    deleteFirstOccurence(list, 'B');
    display(list);

    // Test deleteAllOccurrence
    insertLast(list, 'A'); // Add duplicate 'A'
    insertLast(list, 'A'); // Add another duplicate
    printf("After inserting duplicates of 'A': ");
    display(list);

    printf("Delete all occurrences of 'A': ");
    deleteAllOccurence(list, 'A');
    display(list);

    // Test deleteLast
    printf("Delete last element: ");
    deleteLast(list);
    display(list);

    // Test isExist
    printf("Is 'C' in the list? %s\n", isExist(list, 'C') ? "Yes" : "No");
    printf("Is 'Z' in the list? %s\n", isExist(list, 'Z') ? "Yes" : "No");

    // Test locate
    printf("Locate 'Y': %c\n", locate(list, 'Y'));
    printf("Locate 'Z': %c\n", locate(list, 'Z'));

    // Test makenull
    printf("Make null (clear list):\n");
    makeNull(list);
    display(list);

    free(list); // cleanup memory
    return 0;
}
