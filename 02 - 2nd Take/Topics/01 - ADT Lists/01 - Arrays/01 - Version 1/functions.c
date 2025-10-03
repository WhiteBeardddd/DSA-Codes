#include <stdio.h>
#include <stdbool.h>
#define SIZE 10   // Maximum size of the list

// Version 1
// Define a structure representing a list of characters
typedef struct {
    char elem[SIZE];  // fixed-size array to hold characters
    int count;        // number of elements currently in the list
} charList;           // value type (not a pointer, unlike version 2)

// ================== Function Prototypes ==================
void initList(charList *L);
void makenull(charList *L);
bool isEmpty(charList L);
bool isFull(charList L);
bool isExist(charList L, char x);
char locate(charList L, char x);
void display(charList L);
void deleteFirstOccurence(charList *L, char x);
void deleteAllOccurence(charList *L, char x);
void deleteLast(charList *L);
void insertFirst(charList *L, char x);
void insertMiddle(charList *L, char x);
void insertLast(charList *L, char x);

// ================== Function Definitions ==================

// ======== Initialization Functions ========

// Initialize the list by setting its count to 0
void initList(charList *L){
    L->count = 0;  // no elements yet
}

// Reset the list to empty (same as initList)
void makenull(charList *L){
    L->count = 0;
}

// ======== Helper Functions ========

// Check if list is empty
bool isEmpty(charList L){
    return L.count == 0;
}

// Check if list is full
bool isFull(charList L){
    return L.count == SIZE;
}

// Check if an element exists in the list
bool isExist(charList L, char x){
    int i;
    for(i = 0; i < L.count && L.elem[i] != x; i++){}
    return (i < L.count)? true : false;
}

// Locate element x and return it, or '\0' if not found
char locate(charList L, char x){
    int i;
    for(i = 0; i < L.count && L.elem[i] != x; i++){}
    return (i < L.count)? x : '\0';
}

// Display all elements in the list
void display(charList L){
    if(!isEmpty(L)){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i]);   // print each element
            if(i < L.count - 1){
                printf(",");           // print comma between elements
            }
        }
        printf("\n");
    }else{
        printf("Nothing to display, List is empty\n");
    }
}

// ======== Delete Functions ========

// Delete the first occurrence of x
void deleteFirstOccurence(charList *L, char x){
    if(!isEmpty(*L)){
        int i;
        // Find the first occurrence of x
        for(i = 0; i < L->count && L->elem[i] != x; i++){}

        if(i < L->count){
            L->count--; // shrink list size
            // Shift elements left to fill the gap
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
void deleteAllOccurence(charList *L, char x){
    if(!isEmpty(*L)){
        for(int i = 0; i < L->count; i++){
            if(L->elem[i] == x){
                // Shift elements left to overwrite the found element
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--; // shrink list size
                i--;        // recheck current index (new element shifted in)
            }
        }
    }else{
        printf("List is empty\n");
    }
}

// Delete the last element in the list
void deleteLast(charList *L){
    if(!isEmpty(*L)){
        L->count--;   // simply reduce the count
    }else{
        printf("List is empty\n");
    }
}

// Deletes the first element in the list
void deleteFirst(charList *L){
    if(!isEmpty(*L)){
        // shift all elements left
        for(int i = 0; i < L->count; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;   
    }else{
        printf("List is empty\n");
    }
}

// ======== Insert Functions ========

// Insert element at the beginning
void insertFirst(charList *L, char x){
    if(!isFull(*L)){
        // Shift elements right to make space at index 0
        for(int i = L->count; i > 0; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[0] = x;
        L->count++;
    }else{
        printf("The Array is full\n");
    }
}

// Insert element in the middle
void insertMiddle(charList *L, char x){
    if(!isFull(*L)){
        int middle = L->count / 2;  // middle index
        // Shift elements right from the middle onwards
        for(int i = L->count; i > middle; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[middle] = x; // place at middle
        L->count++;
    }else{
        printf("The Array is full\n");
    }
}

// Insert element at the end
void insertLast(charList *L, char x){
    if(!isFull(*L)){
        L->elem[L->count] = x; // place at last position
        L->count++;
    }else{
        printf("The Array is full\n");
    }
}
