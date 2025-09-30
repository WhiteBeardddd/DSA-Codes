#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10

// version 2
typedef struct {
    char elem[SIZE];
    int count;
} *charList;

// Function prototypes
void initList(charList *L);
void makeNull(charList L);
bool isEmpty(charList L);
void display(charList L);
bool isFull(charList L);
void deleteFirstOccurence(charList L, char x);
void deleteAllOccurence(charList L, char x);
void deleteLast(charList L);
void deleteFirst(charList L);
void insertFirst(charList L, char x);
void insertMiddle(charList L, char x);
void insertLast(charList L, char x);
bool isExist(charList L, char x);
char locate(charList L, char x);


void initList(charList *L){
    *L = (charList)malloc(sizeof(**L));
    if((*L) != NULL){
        printf("Memory allocation successful\n");
        (*L)->count = 0;
    }else{
        printf("Memory allocation unsuccessful\n");
    }
}

void makeNull(charList L){
    L->count = 0;
}

bool isEmpty(charList L){
    return L->count == 0;
}

bool isFull(charList L){
    return L->count == SIZE;
}

void display(charList L){
    if(!isEmpty(L)){
        for(int i = 0; i < L->count; i++){
            printf("%c", L->elem[i]);
            {
                if(i < L->count - 1){
                    printf(",");
                }
            }
        }
        printf("\n");
    }else{
        printf("Nothing no display, List is empty!\n");
    }
}

void deleteFirstOccurence(charList L, char x){
    if(!isEmpty(L)){
        int i;
        for(i = 0; i < L->count && L->elem[i] != x; i++){}
            if(i < L->count){
                L->count--;
                for(; i < L->count; i++){
                    L->elem[i] = L->elem[i + 1]; 
                }
            }else{
                printf("element does not exist!");
            }
    }else{
        printf("List is empty\n");
    }
}

void deleteAllOccurence(charList L, char x){
    if(!isEmpty(L)){
        int i, j;
        bool found = false;
        for(i = j = 0; i < L->count; i++){
            if(L->elem[i] != x){
                L->elem[j] = L->elem[i];
                j++;
            }else{
                found = true;
            }
        }
        L->count = j;
        if(!found){
            printf("Element '%c' does not exist in the list!\n", x); // D - b
        }
    }else{
        printf("List is empty\n");
    }
}

void deleteLast(charList L){
    if(!isEmpty(L)){
        L->count--;
    }else{
        printf("List is empty");
    }
}

void deleteFirst(charList L){
    if(!isEmpty(L)){
        for(int i = 0; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }else{
        printf("List is empty");
    }
}



void insertFirst(charList L, char x){
    if(!isFull(L)){
        for(int i = L->count; i > 0; i--){
            L->elem[i] = L->elem[i - 1]; 
        }
        L->elem[0] = x;
        L->count++;
    }else{
        printf("List is Full\n");
    }
}

void insertMiddle(charList L, char x){
    if(!isFull(L)){
        int middle = L->count / 2;
        for(int i = L->count; i > middle; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[middle] = x;
        L->count++;
    }else{
        printf("The array is full nigga");
    }
}

void insertLast(charList L, char x){
    if(!isFull(L)){
        L->elem[L->count] = x;
        L->count++;
    }else{
        printf("The Array is full");
    }
}

bool isExist(charList L, char x){
    int i;
    for(i = 0; i < L->count && L->elem[i] != x; i++){}
    return (i < L->count)? true : false;
}

char locate(charList L, char x){
    int i;
    for(i = 0; i < L->count && L->elem[i] != x; i++){}
    return (i < L->count)? x : '\0';
}
