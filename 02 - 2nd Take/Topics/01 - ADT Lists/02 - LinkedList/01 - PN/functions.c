#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct node {
    char elem;            // Data stored in the node
    struct node *link;    // Pointer to next node
} *PN;                    // PN = Pointer to Node

// Function Prototypes
void init(PN *list);
void display(PN list);
void makenull(PN *list);
PN createNode(char X);
void insertFirst(PN *list, char X);
void insertLast(PN *list, char X);
void insertLastUnique(PN *list, char X);
void deleteElem(PN *list, char X);
void deleteAllOccur(PN *list, char X);
void insertSorted(PN *list, char X);
void sortList(PN *list);

//==============================//
//       FUNCTION DEFINITIONS   //
//==============================//

// Initializes an empty list
void init(PN *list) {
    *list = NULL;
}

// Creates a new node with the given element
PN createNode(char X) {
    PN newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->elem = X;
        newNode->link = NULL;
    }
    return newNode;
}

// Displays all elements of the list
void display(PN list) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    for (PN trav = list; trav != NULL; trav = trav->link) {
        printf("%c ", trav->elem);
    }
    printf("\n");
}

// Inserts element at the start of the list
void insertFirst(PN *list, char X) {
    PN newNode = createNode(X);
    if (newNode != NULL) {
        newNode->link = *list;
        *list = newNode;
    } else {
        printf("Memory allocation failed\n");
    }
}

// Inserts element at the end of the list
void insertLast(PN *list, char X) {
    PN newNode = createNode(X);
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    if (*list == NULL) {
        *list = newNode;
    } else {
        PN trav = *list;
        while (trav->link != NULL)
            trav = trav->link;
        trav->link = newNode;
    }
}

// Inserts element at the end only if it is unique
void insertLastUnique(PN *list, char X) {
    PN newNode = createNode(X);
    if (newNode == NULL) return;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    PN trav = *list;
    // Traverse list and check for duplicates
    while (trav->link != NULL) {
        if (trav->elem == X) {
            printf("Element exists, insert invalid\n");
            free(newNode);
            return;
        }
        trav = trav->link;
    }

    // Final check for the last node
    if (trav->elem == X) {
        printf("Element exists, insert invalid\n");
        free(newNode);
        return;
    }

    trav->link = newNode;
}

// Deletes the first occurrence of an element
void deleteElem(PN *list, char X) {
    if (*list == NULL) {
        printf("Nothing to delete, list is empty\n");
        return;
    }

    PN curr = *list, prev = NULL;
    while (curr != NULL && curr->elem != X) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("Element '%c' does not exist\n", X);
        return;
    }

    // Adjust links depending on position
    if (prev == NULL)
        *list = curr->link;
    else
        prev->link = curr->link;

    free(curr);
}

// Deletes all occurrences of a specific element
void deleteAllOccur(PN *list, char X) {
    if (*list == NULL) {
        printf("Nothing to delete, list is empty\n");
        return;
    }

    PN curr = *list, prev = NULL;
    while (curr != NULL) {
        if (curr->elem == X) {
            PN temp = curr;
            if (prev == NULL)
                *list = curr->link;
            else
                prev->link = curr->link;

            curr = curr->link;
            free(temp);
        } else {
            prev = curr;
            curr = curr->link;
        }
    }
}

// Inserts an element in sorted position (ascending)
void insertSorted(PN *list, char X) {
    PN newNode = createNode(X);
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Insert at head if empty or smaller
    if (*list == NULL || (*list)->elem >= X) {
        newNode->link = *list;
        *list = newNode;
        return;
    }

    // Traverse until correct position found
    PN trav = *list;
    while (trav->link != NULL && trav->link->elem < X)
        trav = trav->link;

    newNode->link = trav->link;
    trav->link = newNode;
}

// Sorts the list in ascending order using insertion sort logic
void sortList(PN *list) {
    PN sorted = NULL;
    PN curr = *list;

    while (curr != NULL) {
        PN next = curr->link; // Save next node
        // Insert node into sorted portion
        if (sorted == NULL || curr->elem < sorted->elem) {
            curr->link = sorted;
            sorted = curr;
        } else {
            PN trav = sorted;
            while (trav->link != NULL && trav->link->elem < curr->elem)
                trav = trav->link;
            curr->link = trav->link;
            trav->link = curr;
        }
        curr = next;
    }

    *list = sorted;
}

// Deletes all nodes (frees memory)
void makenull(PN *list) {
    PN temp;
    while (*list != NULL) {
        temp = *list;
        *list = (*list)->link;
        free(temp);
    }
    *list = NULL;
}
