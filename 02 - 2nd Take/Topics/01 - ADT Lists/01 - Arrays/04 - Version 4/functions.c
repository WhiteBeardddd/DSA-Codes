#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define SIZE 10  // initial size of the list

// Version 3
// Represents a single element in the list
typedef struct {
    char data;   // stores one character
} Element;

// Represents the dynamic list (stored as a pointer in main)
typedef struct node {
    Element *Elements;  // dynamically allocated array of Elements
    int count;          // number of used elements in the list
} charList;


// ================== Function Prototypes ==================
charList *initList(int capacity);
void makenull(charList *List);
void expandList(charList *List, int *capacity);
bool isEmpty(charList *List);
bool isFull(charList *List, int capacity);
bool isExist(charList *List, char x);
char locate(charList *List, char x);
void display(charList *List);
void deleteFirstOccurence(charList *List, char x);
void deleteAllOccurence(charList *List, char x);
void deleteLast(charList *List);
void deleteFirst(charList *List);
void insertFirst(charList *List, char x, int *capacity);
void insertMiddle(charList *List, char x, int *capacity);
void insertLast(charList *List, char x, int *capacity);


// ================== Function Definitions ==================

// ======== Memory Management Functions ========

// Initializes the list dynamically using malloc
// Returns a pointer to the newly created list
charList *initList(int capacity){
    charList *List = (charList *)malloc(sizeof(charList));  // allocate memory for the list struct
    if(List != NULL){
        List->Elements = (Element *)malloc(capacity * sizeof(Element)); // allocate memory for elements
        if(List->Elements != NULL){
            printf("Memory allocation successful!\n");
            List->count = 0;  // initialize empty list
        }else{
            printf("Memory allocation failed for elements!\n");
            free(List);  // free struct if element allocation fails
            return NULL;
        }
    }else{
        printf("Memory allocation failed for list!\n");
    }
    return List;
}

// Frees all allocated memory and resets the list
void makenull(charList *List){
    free(List->Elements);     // free allocated memory for elements
    List->Elements = NULL;    // avoid dangling pointer
    List->count = 0;          // reset count
    printf("Make null function completed, List is now empty!\n");
}

// Expands the list by doubling its capacity using realloc
void expandList(charList *List, int *capacity){
    *capacity *= 2; // double the capacity
    Element *temp = (Element*)realloc(List->Elements, *capacity * sizeof(Element));
    if(temp != NULL){
        List->Elements = temp;
        printf("Memory reallocation successful! New capacity: %d\n", *capacity);
    }else{
        printf("Memory reallocation failed!\n");
    }
}


// ======== Check Functions ========

// Checks if the list is empty
bool isEmpty(charList *List){
    return List->count == 0;
}

// Checks if the list is full given the current capacity
bool isFull(charList *List, int capacity){
    return List->count == capacity;
}

// Checks if element x exists in the list
bool isExist(charList *List, char x){
    for(int i = 0; i < List->count; i++){
        if(List->Elements[i].data == x){
            return true;
        }
    }
    return false;
}

// Locates and returns element x if found
char locate(charList *List, char x){
    for(int i = 0; i < List->count; i++){
        if(List->Elements[i].data == x){
            return x;
        }
    }
    return '\0';  // not found
}


// ======== Display Function ========

// Displays the contents of the list
void display(charList *List){
    if(!isEmpty(List)){
        for(int i = 0; i < List->count; i++){
            printf("%c", List->Elements[i].data);
            if (i < List->count - 1 ){
                printf(","); // add comma between elements
            }
        }
        printf("\n");
    }else{
        printf("Nothing to display, List is empty\n");
    }
}


// ======== Delete Functions ========

// Deletes the first occurrence of character x
void deleteFirstOccurence(charList *List, char x){
    if(!isEmpty(List)){
        int i;
        // find first index of x
        for(i = 0; i < List->count && List->Elements[i].data != x; i++){}
        if(i < List->count){  // found
            // shift elements left
            for(; i < List->count - 1; i++){
                List->Elements[i] = List->Elements[i + 1];
            }
            List->count--;
        }else{
            printf("Element does not exist!\n");
        }
    }else{
        printf("List is empty\n");
    }
}

// Deletes all occurrences of character x
void deleteAllOccurence(charList *List, char x){
    if(!isEmpty(List)){
        for(int i = 0; i < List->count; i++){
            if(List->Elements[i].data == x){
                for(int j = i; j < List->count - 1; j++){
                    List->Elements[j] = List->Elements[j + 1];
                }
                List->count--;
                i--; // recheck same index
            }
        }
    }else{
        printf("List is empty\n");
    }
}

// Deletes the last element
void deleteLast(charList *List){
    if(!isEmpty(List)){
        List->count--;
    }else{
        printf("List is empty\n");
    }
}

// Deletes the first element in the list
void deleteFirst(charList *List){
    if(!isEmpty(List)){
        for(int i = 0; i < List->count - 1; i++){
            List->Elements[i] = List->Elements[i + 1];
        }
        List->count--;
    }else{
        printf("List is empty\n");
    }
}


// ======== Insert Functions ========

// Inserts an element at the beginning of the list
void insertFirst(charList *List, char x, int *capacity){
    if(isFull(List, *capacity)){
        expandList(List, capacity);
    }
    // shift elements to the right
    for(int i = List->count; i > 0; i--){
        List->Elements[i] = List->Elements[i-1];
    }
    List->Elements[0].data = x;
    List->count++;
}

// Inserts an element in the middle of the list
void insertMiddle(charList *List, char x, int *capacity){
    if(isFull(List, *capacity)){
        expandList(List, capacity);
    }
    int middle = List->count / 2;  // compute middle index
    for(int i = List->count; i > middle; i--){
        List->Elements[i] = List->Elements[i-1];
    }
    List->Elements[middle].data = x;
    List->count++;
}

// Inserts an element at the end of the list
void insertLast(charList *List, char x, int *capacity){
    if(isFull(List, *capacity)){
        expandList(List, capacity);
    }
    List->Elements[List->count].data = x;
    List->count++;
}

