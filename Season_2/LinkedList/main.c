#include <stdio.h>
#include "functions.h"

// Main Functions
int main(){
    charList List;
    init(&List);

    // make first, second, third
    insertFirst(&List, 'C');
    insertFirst(&List, 'S');
    insertFirst(&List, 'U');
    insertFirst(&List, 'V');
    insertFirst(&List, 'E');
    insertFirst(&List, 'O');
    insertFirst(&List, 'N');
    insertFirst(&List, 'Z');
    insertFirst(&List, 'K');
    printf("Original List\n");
    display(List);
    
    printf("\nAfter Sortlint was called\n");
    sortList(&List);
    display(List);
    


    return 0;
}