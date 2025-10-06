#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "StackArray.h"
// #include "StackLinkList.h"
// #include "StackDoublyLinkList.h"
// #include "StackCursorBased.h"

#define MAX 10

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}nameType;

typedef struct{
    nameType studName;
    int id;
    char course;
}studType;

typedef struct{
    int top;
    studType studRec[MAX];
}Stack;

// initialize the Stack
void initList(Stack *S);
//insert at the Top of the Stack
bool push(Stack *S, studType student);
//delete at the Top of the Stack
bool pop(Stack *S);
// return the top of the Stack if no item in the stack return dummy//
studType popReturn(Stack *S);
// display the top of the Stack //
void top(Stack *S);
// check if stack is empty //
bool isEmpty(Stack *S);
// check if stack is full //
bool isFull(Stack *S);
// restarts the stack //
bool makeNull(Stack *S);