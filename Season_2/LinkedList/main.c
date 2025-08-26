#include <stdio.h>
#include "functions.h"

<<<<<<< HEAD
// Main Functions
=======
>>>>>>> 03894d1dd56a1c3bf92549bac1967ccf8bcba18c
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
    
    printf("\nAfter Sortlint was called\n");
    sortList(&List);
    display(List);
    


    return 0;
}
