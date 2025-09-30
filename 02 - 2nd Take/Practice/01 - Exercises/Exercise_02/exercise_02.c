#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for a singly linked list
typedef struct node {
  char elem;             // element stored in the node
  struct node *link;     // pointer to the next node
}*charList;              // alias for "pointer to node"

// Function Prototypes
void insertFirst(charList *list, char X);
void insertLast(charList *list, char X);
void insertLastUnique(charList *list, char X);
void deleteElem(charList *list, char X);
void deleteAllOccur(charList *list, char X);
void insertSorted(charList *list, char value);
void sortList(charList *list);

// Helper Function Prototypes
bool findElem(charList list, char X);
void init(charList *list);
void display(charList list);
charList createNode(char X);

// Insert at the beginning of the list
void insertFirst(charList *list, char X){
    charList newNode = createNode(X); // create a new node
    if(newNode != NULL){
        newNode->link = *list; // link new node to current head
        *list = newNode;       // update head to new node
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Insert at the end of the list
void insertLast(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // traverse until we reach NULL (end of list)
        for(trav = list; *trav != NULL; trav = &(*trav)->link){}
        *trav = newNode; // insert new node at the end
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Insert at the end of the list, but only if element does not already exist
void insertLastUnique(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // traverse until end OR until we find duplicate
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            // duplicate found
            printf("Element exists in the list, insert is invalid\n");
            free(newNode); // free unused node
        }else{
            *trav = newNode; // insert node at the end
        }
    }
}

// Delete the first occurrence of an element
void deleteElem(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        // traverse until we find X or reach end
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            charList temp = *trav;      // store node to delete
            *trav = (*trav)->link;      // unlink node from list
            free(temp);                 // free memory
        }else{
            printf("Element '%c' does not exist\n", X);
        }
    }else{
        printf("Nothing to delete, list is empty\n");
    }
}

// Delete all occurrences of an element
void deleteAllOccur(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        // traverse list
        for(trav = list; *trav != NULL;){
            if((*trav)->elem == X){
                // found a match, unlink and delete
                charList temp = *trav;
                *trav = temp->link;
                free(temp);
            }else{
                // move to next node
                trav = &(*trav)->link;
            }
        }
    }else{
        printf("Nothing to delete, list is empty\n");
    }
}

// Sort list in ascending order (insertion sort for linked list)
void sortList(charList *list) {
    charList sorted = NULL; // new sorted list

    while (*list != NULL) {
        charList current = *list;      // take node from original list
        *list = (*list)->link;         // advance original list
        charList *trav = &sorted;

        // find correct position in sorted list
        for (; *trav != NULL && (*trav)->elem < current->elem; trav = &(*trav)->link);

        // insert node into sorted list
        current->link = *trav;
        *trav = current;
    }
    *list = sorted; // update head pointer
}

// Insert element in its correct sorted position
void insertSorted(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // find position where X should be inserted
        for(trav = list; *trav != NULL && (*trav)->elem < X; trav = &(*trav)->link){}
        newNode->link = *trav; // insert node
        *trav = newNode;
    }else{
        printf("Memory Allocation Failed\n");
    }
}

// Search for an element in the list
bool findElem(charList list, char X){
    if(list != NULL){
        for(; list != NULL && list->elem != X; list = list->link){}
    }else{
        printf("List is empty");
    }
    // return true if found, false if not
    return(list != NULL)? true: false;
}

// Initialize list (set to empty)
void init(charList *list){
    *list = NULL;
}

// Allocate and initialize a new node
charList createNode(char X){
    charList newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = X;
        newNode->link = NULL;
    }
    return (newNode != NULL)? newNode : NULL;
}

// Display all elements in the list
void display(charList list){
    if(list != NULL){
        for(;list != NULL; list = list->link){
            printf("%c ", list->elem);
        }
    }else{
        printf("List is empty");
    }
}

int main(){
    charList List;
    init(&List); // initialize empty list

    // Insert elements at the beginning
    insertFirst(&List, 'C');
    insertFirst(&List, 'S');
    insertFirst(&List, 'U');
    printf("Original List\n");
    display(List);
    
    printf("\n");
    insertLastUnique(&List, 'C'); // won't insert (duplicate)
    insertLastUnique(&List, 'D'); // inserts at end
    
    printf("Display 1: ");
    display(List);
    printf("\n");

    deleteElem(&List, 'S'); // delete element 'S'

    printf("Display 2: ");
    display(List);

    printf("\n");
    sortList(&List); // sort list
    printf("Display 3: ");
    display(List);

    printf("\n");
    insertSorted(&List, 'E'); // insert in sorted order
    insertSorted(&List, 'Z'); // insert in sorted order
    printf("Display 4: ");
    display(List);

    // Add more at the front
    insertFirst(&List, 'A');
    insertFirst(&List, 'B');
    insertFirst(&List, 'C');
    
    printf("\n");
    printf("Display 5: ");
    display(List);

    printf("\n");
    printf("Display 5 (sorted): ");
    sortList(&List);
    display(List);

    printf("\n");
    printf("Display 5 (with X at end): ");
    insertLast(&List, 'X'); // insert at end
    display(List);

    printf("\n");
    printf("Display 6: ");
    bool catcher = findElem(List, 'V'); // search element
    printf("%d", catcher);

    return 0;
}
