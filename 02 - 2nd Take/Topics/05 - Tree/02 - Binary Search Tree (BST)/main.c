#include <stdio.h>
#include "functions.h"

void main() {
    BST myTree;
    initTree(&myTree);

    insertElem(&myTree, 6);
    insertElem(&myTree, 1);
    insertElem(&myTree, 10);
    insertElem(&myTree, 3);
    insertElem(&myTree, 3);
    insertElem(&myTree, 2);
    insertElem(&myTree, 4);
    insertElem(&myTree, 9);
    insertElem(&myTree, 14);

    printf("\nIn Order: ");
    inOrder(myTree);

    deleteElem(&myTree, 3);
    // deleteElem(&myTree, 14);

    printf("\n[After Delete] In Order: ");
    inOrder(myTree);
}