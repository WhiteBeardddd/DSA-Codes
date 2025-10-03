#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define SIZE 10   // initial size of the list

// Version 3
// Represents a single element in the list
typedef struct {
    char data;   // stores one character
} Element;

// Represents the dynamic list
typedef struct {
    Element *elem; // pointer to a dynamically allocated array of Elements
    int count;     // number of used elements in the list
} charList;


// ================== Function Prototypes ==================
void initList(charList *L, int capacity);
void makenull(charList *L);
void expandList(charList *L, int *capacity);
bool isEmpty(charList L);
bool isFull(charList L, int capacity);
bool isExist(charList L, char x);
char locate(charList L, char x);
void display(charList L);
void deleteFirstOccurence(charList *L, char x);
void deleteAllOccurence(charList *L, char x);
void deleteLast(charList *L);
void deleteFirst(charList *L);
void insertFirst(charList *L, char x, int *capacity);
void insertMiddle(charList *L, char x, int *capacity);
void insertLast(charList *L, char x, int *capacity);


// ================== Function Definitions ==================

// ======== Memory Management Functions ========

// Initializes the list with a given capacity
// Allocates memory dynamically for "capacity" number of elements
void initList(charList *L, int capacity){
    L->elem = (Element*)malloc(capacity * sizeof(Element));
    if(L->elem != NULL){
        printf("Memory allocation successful!\n");
        L->count = 0;  // initially, list is empty
    }else{
        printf("Memory allocation failed!\n");
    }
}

// Frees the allocated memory and resets the list
void makenull(charList *L){
    free(L->elem);     // free allocated memory
    L->elem = NULL;    // avoid dangling pointer
    L->count = 0;      // reset element count
    printf("Make null function Completed, List is now empty!\n");
}


// Expands the list by doubling its capacity
void expandList(charList *L, int *capacity){
    *capacity *= 2; // double the capacity
    // safer way: use temp variable to avoid losing pointer if realloc fails
    Element *temp = (Element*)realloc(L->elem, *capacity * sizeof(Element));
    if(temp != NULL){
        L->elem = temp;
        printf("Memory reallocation successful! New capacity: %d\n", *capacity);
    }else{
        printf("Memory reallocation failed!\n");
    }
}

// ======== Memory Management Functions ========

// Checks if the list is empty
bool isEmpty(charList L){
    return L.count == 0;
}

// Checks if the list is full given the current capacity
bool isFull(charList L, int capacity){
    return L.count == capacity;
}

// Checks if element x exists in the list
bool isExist(charList L, char x){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i].data == x){
            return true;
        }
    }
    return false;
}

// Locates element x in the list
char locate(charList L, char x){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i].data == x){
            return x;  // found
        }
    }
    return '\0';  // not found
}

// Displays the contents of the list
void display(charList L){
    if(!isEmpty(L)){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i].data);
            if (i < L.count - 1 ){
                printf(","); // comma between elements
            }
        }
        printf("\n");
    }else{
        printf("Nothing to display, List is empty\n");
    }
}

// ======== Memory Management Functions ========

// Deletes the first occurrence of character x
void deleteFirstOccurence(charList *L, char x){
    if(!isEmpty(*L)){
        int i;
        // find the first index where x occurs
        for(i = 0; i < L->count && L->elem[i].data != x; i++){}
        if(i < L->count){  // found
            // shift elements left to overwrite the deleted element
            for(; i < L->count - 1; i++){
                L->elem[i] = L->elem[i + 1];
            }
            L->count--;
        }else{
            printf("Element does not exist!\n");
        }
    }else{
        printf("List is empty\n");
    }
}

// Deletes all occurrences of character x
void deleteAllOccurence(charList *L, char x){
    if(!isEmpty(*L)){
        for(int i = 0; i < L->count; i++){
            if(L->elem[i].data == x){
                // shift elements left to overwrite deleted one
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--;
                i--; // recheck same index since it now holds a new value
            }
        }
    }else{
        printf("List is empty\n");
    }
}

// Deletes the last element
void deleteLast(charList *L){
    if(!isEmpty(*L)){
        L->count--;  // just reduce the count
    }else{
        printf("List is empty\n");
    }
}

// Deletes the first element in the list
void deleteFirst(charList *L){
    if(!isEmpty(*L)){
        // Shift all elements one step left
        for(int i = 0; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;  // reduce the number of elements
    }else{
        printf("List is empty\n");
    }
}
// ======== Memory Management Functions ========

// Inserts an element at the beginning of the list
void insertFirst(charList *L, char x, int *capacity){
    if(isFull(*L, *capacity)){
        expandList(L, capacity);
    }
    // shift everything right to make space at index 0
    for(int i = L->count; i > 0; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[0].data = x; // insert at the start
    L->count++;
}

// Inserts an element in the middle of the list
void insertMiddle(charList *L, char x, int *capacity){
    if(isFull(*L, *capacity)){
        expandList(L, capacity);
    }
    int middle = L->count / 2;  // compute middle index
    // shift elements to the right starting from middle
    for(int i = L->count; i > middle; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[middle].data = x;
    L->count++;
}

// Inserts an element at the end of the list
void insertLast(charList *L, char x, int *capacity){
    if(isFull(*L, *capacity)){
        expandList(L, capacity);
    }
    L->elem[L->count].data = x;  // place at the next free slot
    L->count++;
}
