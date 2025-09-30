#include <stdio.h>
#include "functions.h"

//* Helper Functions for LinkList *//

// Initializes the linked list by setting the head pointer to NULL
void initLList(LinkList *L){
    *L = NULL;
}

// Frees all nodes in the linked list (makes the list empty)
void makeNullLinkedList(LinkList *L){
    LinkList temp;
    while(*L != NULL){
        temp = *L;            // store current node
        *L = (*L)->link;      // move to next node
        free(temp);           // free the stored node
    }
    *L = NULL;                // ensure list head is NULL after deletion
}

// Displays all students in the linked list
void displayLList(LinkList L) {
    if (L != NULL) {
        printf("\n%-10s %-10s %-5s %-30s\n", "ID", "Course", "Year", "Name");
        printf("--------------------------------------------------------------\n");
        while (L != NULL) {
            // Print each field of the student
            printf("%-10s %-10s %-5d %s %c. %s\n",
                   L->stud.ID,
                   L->stud.course,
                   L->stud.yrlevel,
                   L->stud.name.FN,
                   L->stud.name.MI,
                   L->stud.name.LN);
            L = L->link;  // move to the next node
        }
    } else {
        printf("List is empty\n");
    }
}

// Creates a new node with the given student data
LinkList createStud(studtype newStud){
    LinkList newNode = malloc(sizeof(struct cell));
    if(newNode != NULL){
        newNode->link = NULL;  // initialize link to NULL
        // Copy each field manually (deep copy)
        strcpy(newNode->stud.name.FN, newStud.name.FN);
        strcpy(newNode->stud.name.LN, newStud.name.LN);
        newNode->stud.name.MI = newStud.name.MI;
        strcpy(newNode->stud.course, newStud.course);
        strcpy(newNode->stud.ID, newStud.ID);
        newNode->stud.yrlevel = newStud.yrlevel;
    }
    return (newNode != NULL)? newNode: NULL;
}

//* Main Functions for LinkList *//

// Inserts a student at the beginning of the list
void inserFirstLinkList(LinkList *L, studtype newStud){
    LinkList newNode = createStud(newStud);
    if(newNode != NULL){
        newNode->link = *L;    // point new node to old head
        *L = newNode;          // update head to new node
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Inserts a student at the end of the list
void inserLastLinkList(LinkList *L, studtype newStud){
    LinkList newNode = createStud(newStud);
    if(newNode != NULL){
        LinkList *trav;
        // Traverse to the end of the list
        for(trav = L; *trav != NULL; trav = &(*trav)->link){}
        *trav = newNode;  // link new node at the end
    }else{
        printf("Memory Allocation failed\n");
    }
}

// Inserts a student at the end only if the ID is unique
void insertLastUniqueLinkList(LinkList *L, studtype newStud) {
    LinkList newNode = createStud(newStud);
    if (newNode != NULL) {
        LinkList *trav;
        // Traverse while list has nodes and no duplicate found
        for (trav = L; *trav != NULL && strcmp((*trav)->stud.ID, newStud.ID) != 0; trav = &(*trav)->link) {}
        
        if (*trav != NULL) { 
            // Duplicate ID found
            printf("Element exists in the list, insert is invalid\n");
            free(newNode);
        } else {
            // Reached end, safe to insert
            *trav = newNode;
        }
    } else {
        printf("Memory Allocation failed\n");
    }
}

// Inserts a student at a specific position in the list
// Position starts at 1 (head is position 1)
void inserAtPositionLinkList(LinkList *L, studtype newStud, int pos){
    if(*L != NULL){
        LinkList newNode = createStud(newStud);
        if(newNode != NULL){
            int count = 1;
            LinkList *trav;
            // Traverse until position is reached or end of list
            for(trav = L; *trav != NULL && count < pos; trav = &(*trav)->link, count++){}
            // Insert new node at position
            newNode->link = *trav;
            *trav = newNode;
        }
    }else{
        printf("List is empty");
    }
}

// Deletes a student by ID from the list
// Returns a dummy student if not found
studtype deleteElemLinkList(LinkList *L, char ID[]){
    studtype dummy = {"XXXXX", {"XXXXX", "XXXXX", 'X'}, "XXXXX", 0};
    
    if(*L != NULL){
        LinkList *trav, temp;
        // Find the node with matching ID
        for(trav = L; *trav != NULL && strcmp((*trav)->stud.ID, ID) != 0; trav = &(*trav)->link){}
        if(*trav != NULL){
            // Found node, remove it
            temp = *trav;
            *trav = (*trav)->link;  // bypass the node
            free(temp);             // free memory
        }else{
            printf("Element does not exist!\n");
        }
    }else{
        printf("List is empty\n");
    }
    
    return dummy;  // currently always returns dummy (you could return deleted student for completeness)
}

// Separates all students of a given course into a new list
// Adds them to the new list but does NOT remove them from the original
LinkList separateCourseLinkList(LinkList *L, char course[]){
    LinkList newList;
    initLList(&newList);   // initialize new list as empty
    if(*L != NULL){
        LinkList *trav;
        // Traverse the list
        for(trav = L; *trav != NULL; trav = &(*trav)->link){
            if(strcmp((*trav)->stud.course , course) == 0){
                // Insert matching students to the new list (at the front)
                inserFirstLinkList(&newList, (*trav)->stud);
            }
        }
    }else{
        printf("List is empty");
    }

    return newList;
}
