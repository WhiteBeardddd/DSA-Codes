#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
typedef struct node {
  char elem;            // Character data stored in each node
  struct node *link;    // Pointer to the next node
} *charList;            // Alias for pointer to struct node

// Function Prototypes
void insertFirst(charList *list, char X);
void insertLast(charList *list, char X);
void insertLastUnique(charList *list, char X);
void deleteElem(charList *list, char X);
void deleteAllOccur(charList *list, char X);
void insertSorted(charList *list, char value);
void sortList(charList *list);

// Helper Function Prototypes
void init(charList *list);
void display(charList list);
void makenull(charList *List);
charList createNode(char X);

//==============================//
//        MAIN FUNCTIONS        //
//==============================//

// Inserts a new node at the beginning of the list
void insertFirst(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        newNode->link = *list; // Point new node to current head
        *list = newNode;       // Update head
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Inserts a new node at the end of the list
void insertLast(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // Traverse until the end of the list
        for(trav = list; *trav != NULL; trav = &(*trav)->link){}
        *trav = newNode; // Attach the new node at the end
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Inserts a node at the end only if it does not already exist
void insertLastUnique(charList *L, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // Traverse until end or until duplicate found
        for(trav = L; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            printf("Element Exist in the list, insert is invalid\n");
            free(newNode);
        }else{
            *trav = newNode;
        }
    }
}

// Deletes the first occurrence of a given element
void deleteElem(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        // Traverse until element is found
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            charList temp = *trav;
            *trav = (*trav)->link; // Remove node from chain
            free(temp);
        }else{
            printf("Element '%c' does not exist\n", X);
        }
    }else{
        printf("Nothing to delete, List is empty\n");
    }
}

// Deletes all occurrences of a specific element
void deleteAllOccur(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        for(trav = list; *trav != NULL;){
            if((*trav)->elem == X){
                charList temp = *trav;
                *trav = temp->link;
                free(temp);
            }else{
                trav = &(*trav)->link;
            }
        }
    }else{
        printf("Nothing to delete, List is empty\n");
    }
}

// Sorts the list in ascending order
void sortList(charList *list) {
    charList sorted = NULL;
    while (*list != NULL) {
        charList current = *list;
        *list = (*list)->link;
        charList *trav = &sorted;

        // Find the proper place in the sorted list
        for (; *trav != NULL && (*trav)->elem < current->elem; trav = &(*trav)->link);
        current->link = *trav;
        *trav = current;
    }
    *list = sorted;
}

// Inserts element in sorted order (used for maintaining sorted lists)
void insertSorted(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        // Traverse until correct position found
        for(trav = list; *trav != NULL && (*trav)->elem < X; trav = &(*trav)->link){}
        newNode->link = *trav;
        *trav = newNode;
    }else{
        printf("Memory Allocation Failed\n");
    }
}

//==============================//
//       HELPER FUNCTIONS       //
//==============================//

// Initializes list to empty
void init(charList *list){
    *list = NULL;
}

// Deletes all nodes and makes the list empty
void makenull(charList *List){
    if(*List != NULL){
        charList temp;
        for(; *List != NULL;){
            temp = *List;
            *List = (*List)->link;
            free(temp);
        }
        *List = NULL;
    }else{
        printf("List is empty\n");
    }
}

// Creates and returns a new node
charList createNode(char X){
    charList newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = X;
        newNode->link = NULL;
    }
    return newNode;
}

// Displays all elements in the list
void display(charList list){
    if(list != NULL){
        for(; list != NULL; list = list->link){
            printf("%c ", list->elem);
        }
        printf("\n");
    }else{
        printf("List is empty\n");
    }
}
