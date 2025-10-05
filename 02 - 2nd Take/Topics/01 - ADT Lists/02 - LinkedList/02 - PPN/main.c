#include <stdio.h>
#include "functions.c"

int main() {
    charList L;
    init(&L);

    printf("=== TEST 1: insertLastUnique ===\n");
    insertLastUnique(&L, 'C');
    insertLastUnique(&L, 'S');
    insertLastUnique(&L, 'U');
    insertLastUnique(&L, 'S'); // Duplicate test
    display(L); // Expected: C S U

    printf("\n=== TEST 2: insertFirst ===\n");
    insertFirst(&L, 'A');
    insertFirst(&L, 'Z');
    display(L); // Expected: Z A C S U

    printf("\n=== TEST 3: insertLast ===\n");
    insertLast(&L, 'X');
    insertLast(&L, 'Y');
    display(L); // Expected: Z A C S U X Y

    printf("\n=== TEST 4: deleteElem (middle element) ===\n");
    deleteElem(&L, 'S');
    display(L); // Expected: Z A C U X Y

    printf("\n=== TEST 5: deleteElem (non-existing) ===\n");
    deleteElem(&L, 'Q'); // Should print “does not exist”
    display(L); // Expected: Z A C U X Y

    printf("\n=== TEST 6: deleteAllOccur ===\n");
    insertLast(&L, 'U');
    insertLast(&L, 'U');
    printf("Before deleteAllOccur: ");
    display(L); // Expected: Z A C U X Y U U
    deleteAllOccur(&L, 'U');
    printf("After deleteAllOccur: ");
    display(L); // Expected: Z A C X Y

    printf("\n=== TEST 7: insertSorted ===\n");
    insertSorted(&L, 'B');
    insertSorted(&L, 'M');
    insertSorted(&L, 'D');
    display(L); // Expected (sorted insert positions): Z A B C D M X Y (unsorted list)

    printf("\n=== TEST 8: sortList ===\n");
    sortList(&L);
    display(L); // Expected: A B C D M X Y Z

    printf("\n=== TEST 9: makenull ===\n");
    makenull(&L);
    display(L); // Expected: List is empty

    printf("\n=== TEST 10: Delete on empty list ===\n");
    deleteElem(&L, 'A'); // Should print: “Nothing to delete List is empty”

    printf("\n=== TEST 11: sortList on empty list ===\n");
    sortList(&L);
    display(L); // Expected: List is empty

    return 0;
}
