#include <stdio.h>
#include "functions.h"

// Initializes the list by setting its count to 0
void initList(charList *L){
    L->count = 0; // initializes List
}

// The same with initList sets the count to 0
void makenull(charList *L){
    L->count = 0; // reinitializes List
}

// Displays the contents of the list
void display(charList L){
    if(L.count != 0){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i]); // Print each element
            if (i < L.count - 1 ){ // Print commas between elements
                printf(",");
            }
        }
    }else{
        printf("Nothing to display, List is empty");
    }
}

// Deletes the first occurrence of a given element x in the list
void deleteFirstOccurence(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        int i;
        // Search for the element x in the list
        for(i = 0; i < L->count && L->elem[i] != x; i++){}

        // If found, shift all elements after it one step left
        if(i < L->count){
            L->count--; // reduce list size
            
            //shifting logic
            for(; i < L->count; i++){
                L->elem[i] = L->elem[i + 1];
            }
        }else{
            printf("element does not exist!");
        }
    }else{
        printf("List is empty");
    }
}

// Deletes all occurrences of a given element x in the list
void deleteAllOccurence(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        for(int i = 0; i < L->count; i++){
            if(L->elem[i] == x){
                // Shift elements left to overwrite the found element
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--; // reduce list size
                i--; // recheck current index (since it has new value)
            }
        }
            // printf("element does not exist!");
    }else{
        printf("List is empty");
    }
}

// Deletes the Last element in the given List
void deleteLast(charList *L){
    if(L->count != 0){
        L->count--;
    }else{
        printf("List is empty");
    }
}

// Inserts an element at the beginning of the list
void insertFirst(charList *L, char x){
    if(L->count == 0){ // If list is empty, just place element at 0
        L->elem[0] =  x;
        L->count++;
    }else if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        // Shift elements to the right to make space at the front
        for(int i = L->count; i > 0; i--){
            L->elem[i] = L->elem[i -1];
        }
        L->elem[0] = x; // Place new element at index 0
        L->count++;
    }else{
        printf("The Array is full");
    }
}

// Inserts an element in the middle of the list
void insertMiddle(charList *L, char x){
    if(L->count == 0){ // If empty, just put it at index 0
        L->elem[0] =  x;
        L->count++;
    }else if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        int middle = L->count / 2; // Compute middle index
        // Shift elements to the right starting from the middle
        for(int i = L->count; i > middle; i--){
            L->elem[i] = L->elem[i -1];
        }
        L->elem[middle] = x; // Insert element in middle
        L->count++;
    }else{
        printf("The Array is full");
    }
}

// Inserts an element at the end of the list
void insertLast(charList *L, char x){
    if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        L->elem[L->count] = x; // Place at the end
        L->count++;
    }else{
        printf("The Array is full");
    }
}

// Checks if an element exists in the list
bool isExist(charList L, char x){
    int i;
    // Loop until element is found or end is reached
    for(i = 0; i < L.count && L.elem[i] != x; i++){}
    return (i < L.count)? true : false; // Return true if found
}

// Returns the element if found, otherwise '\0'
char locate(charList L, char x){
    int i;
    for(i = 0; i < L.count && L.elem[i] != x; i++){}
    return(i < L.count)? x : '\0';
}
