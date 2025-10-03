#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10   // Maximum size of the list

// Version 2
// Define a structure representing a list of characters
typedef struct {
    char elem[SIZE];  // fixed-size array to hold characters
    int count;        // number of elements currently in the list
} *charList;          // pointer type alias for the list

// ================== Function Prototypes ==================
void initList(charList *L);
void makeNull(charList L);
bool isFull(charList L);
bool isEmpty(charList L);
bool isExist(charList L, char x);
char locate(charList L, char x);
void display(charList L);
void deleteFirstOccurence(charList L, char x);
void deleteAllOccurence(charList L, char x);
void deleteLast(charList L);
void deleteFirst(charList L);
void insertFirst(charList L, char x);
void insertMiddle(charList L, char x);
void insertLast(charList L, char x);


// ================== Function Definitions ==================

// ======== Memory Management Functions ========

// Initialize the list (allocate memory and set count to 0)
void initList(charList *L){
    *L = (charList)malloc(sizeof(**L));
    if((*L) != NULL){
        printf("Memory allocation successful\n");
        (*L)->count = 0;   // no elements yet
    }else{
        printf("Memory allocation unsuccessful\n");
    }
}

// Reset the list to empty (does not free memory)
void makeNull(charList L){
    L->count = 0;
}

// ======== Helper Functions ========

// Check if list is empty
bool isEmpty(charList L){
    return L->count == 0;
}

// Check if list is full
bool isFull(charList L){
    return L->count == SIZE;
}

// Check if an element exists in the list
bool isExist(charList L, char x){
    int i;
    for(i = 0; i < L->count && L->elem[i] != x; i++){}
    return (i < L->count)? true : false;
}

// Locate element x and return it, or '\0' if not found
char locate(charList L, char x){
    int i;
    for(i = 0; i < L->count && L->elem[i] != x; i++){}
    return (i < L->count)? x : '\0';
}

// Display all elements in the list
void display(charList L){
    if(!isEmpty(L)){
        for(int i = 0; i < L->count; i++){
            printf("%c", L->elem[i]);
            if(i < L->count - 1){
                printf(",");   // print comma between elements
            }
        }
        printf("\n");
    }else{
        printf("Nothing to display, List is empty!\n");
    }
}

// ======== Delete Functions ========

// Delete the first occurrence of x
void deleteFirstOccurence(charList L, char x){
    if(!isEmpty(L)){
        int i;
        // Find the first occurrence of x
        for(i = 0; i < L->count && L->elem[i] != x; i++){}
        if(i < L->count){
            // Shift elements left to fill the gap
            L->count--;
            for(; i < L->count; i++){
                L->elem[i] = L->elem[i + 1]; 
            }
        }else{
            printf("Element does not exist!\n");
        }
    }else{
        printf("List is empty\n");
    }
}

// Delete all occurrences of x
void deleteAllOccurence(charList L, char x){
    if(!isEmpty(L)){
        int i, j;
        bool found = false;
        // Use two indices: i scans, j writes valid elements
        for(i = j = 0; i < L->count; i++){
            if(L->elem[i] != x){
                L->elem[j] = L->elem[i];
                j++;
            }else{
                found = true;  // mark that we found x
            }
        }
        L->count = j;  // new size after removals
        if(!found){
            printf("Element '%c' does not exist in the list!\n", x);
        }
    }else{
        printf("List is empty\n");
    }
}

// Delete the last element in the list
void deleteLast(charList L){
    if(!isEmpty(L)){
        L->count--;   // just decrease count
    }else{
        printf("List is empty\n");
    }
}

// Delete the first element in the list
void deleteFirst(charList L){
    if(!isEmpty(L)){
        // Shift everything left
        for(int i = 0; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }else{
        printf("List is empty\n");
    }
}

// ======== Insert Functions ========

// Insert element at the beginning
void insertFirst(charList L, char x){
    if(!isFull(L)){
        // Shift elements right to make space at index 0
        for(int i = L->count; i > 0; i--){
            L->elem[i] = L->elem[i - 1]; 
        }
        L->elem[0] = x;
        L->count++;
    }else{
        printf("List is Full\n");
    }
}

// Insert element in the middle
void insertMiddle(charList L, char x){
    if(!isFull(L)){
        int middle = L->count / 2;
        // Shift elements to the right from middle
        for(int i = L->count; i > middle; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[middle] = x;
        L->count++;
    }else{
        printf("List is Full\n");
    }
}

// Insert element at the end
void insertLast(charList L, char x){
    if(!isFull(L)){
        L->elem[L->count] = x;
        L->count++;
    }else{
        printf("List is Full\n");
    }
}

