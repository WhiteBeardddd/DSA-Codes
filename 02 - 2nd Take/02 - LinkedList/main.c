#include <stdio.h>
#include "functions.c"

// Main Functions
int main(){
    charList List;
    init(&List);

    
    // make first, second, third
    insertLastUnique(&List, 'C');
    insertLastUnique(&List, 'S');
    insertLastUnique(&List, 'U');
    insertLastUnique(&List, 'V');
    insertLastUnique(&List, 'E');
    insertLastUnique(&List, 'O');
    insertLastUnique(&List, 'N');
    insertLastUnique(&List, 'Z');
    insertLastUnique(&List, 'K');
    printf("Original List\n");
    display(List);
    
    printf("\nAfter Sortlint wsadsdas called\n");
    sortList(&List);
    display(List);

    printf("\n");
    makenull(&List);
    display(List);
    


    return 0;
}
