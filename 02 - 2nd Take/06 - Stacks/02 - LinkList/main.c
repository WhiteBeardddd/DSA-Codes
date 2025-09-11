#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}nameType;

typedef struct{
    nameType studName;
    int id;
    char course[8];
}studType;

typedef struct node{
    studType studRec;
    struct node *link;
}*Stack;


Stack initList(Stack *S){
    S = NULL;
}

void display(Stack *S){

}


/* HELPER FUNCTIONS */

// initialize the Stack
Stack initList(Stack *S);

// display the entire Stack 
void display(Stack *S);

// check if stack is empty //
bool isEmpty(Stack S);

// check if stack is full //
bool isFull(Stack S);

// restarts the stack //
void makeNull(Stack *S);

/* MAIN STACK FUNCTIONS */

//insert at the Top of the Stack
bool push(Stack *S, studType student);

//delete at the Top of the Stack
bool pop(Stack *S);

// return the top of the Stack if no item in the stack return dummy//
studType popReturn(Stack *S);

// display the top of the Stack //
void top(Stack S);