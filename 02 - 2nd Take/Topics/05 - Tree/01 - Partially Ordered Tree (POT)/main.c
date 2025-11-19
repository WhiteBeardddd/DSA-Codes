#include <stdio.h>
#include "functions.h"

int main (){
    POT T;
    initTree(&T);

    insertChild(&T, 10, 20);  // 10 becomes root first
    insertChild(&T, 10, 30);
    insertChild(&T, 20, 40);
    insertChild(&T, 20, 25);

    printPOT(T);


    return 0;
}