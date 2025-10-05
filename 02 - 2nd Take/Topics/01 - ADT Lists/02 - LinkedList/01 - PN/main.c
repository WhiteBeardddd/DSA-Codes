#include <stdio.h>
#include "functions.c"  // Include your PN version of functions

int main() {
    PN list;  // Declare a pointer to node
    init(&list);  // Initialize list

    printf("=== Insert First ===\n");
    insertFirst(&list, 'C');
    insertFirst(&list, 'B');
    insertFirst(&list, 'A');
    display(list); // Expected: A B C

    printf("\n=== Insert Last ===\n");
    insertLast(&list, 'D');
    insertLast(&list, 'E');
    display(list); // Expected: A B C D E

    printf("\n=== Insert Last Unique ===\n");
    insertLastUnique(&list, 'F');
    insertLastUnique(&list, 'B'); // duplicate
    display(list); // Expected: A B C D E F

    printf("\n=== Delete Element ===\n");
    deleteElem(&list, 'C');  // Delete middle element
    deleteElem(&list, 'Z');  // Nonexistent
    display(list); // Expected: A B D E F

    printf("\n=== Delete All Occurrences ===\n");
    insertLast(&list, 'B');
    insertLast(&list, 'B');
    display(list); // Before deleteAllOccur
    deleteAllOccur(&list, 'B');
    display(list); // Expected: A D E F

    printf("\n=== Insert Sorted ===\n");
    insertSorted(&list, 'C');
    insertSorted(&list, 'G');
    insertSorted(&list, 'B');
    display(list); // Expected: A B C D E F G (sorted insert)

    printf("\n=== Sort List ===\n");
    insertLast(&list, 'Z');
    insertLast(&list, 'M');
    insertLast(&list, 'X');
    display(list); // Before sorting
    sortList(&list);
    display(list); // Expected: A B C D E F G M X Z (sorted)

    printf("\n=== Make Null ===\n");
    makenull(&list);
    display(list); // Expected: List is empty

    return 0;
}
