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

Stack initList(Stack *S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void makeNull(Stack *S);
bool push(Stack *S, studType student);
bool pop(Stack *S);
studType popReturn(Stack *S);
void top(Stack S);
void display1(Stack S);
void display2(Stack S);
void display3(Stack S);
void display4(Stack S);

Stack initList(Stack *S){
    S = NULL;
}

bool isEmpty(Stack S){
    return(!S)? true: false;
}

bool isFull(Stack S){

}

void makeNull(Stack *S){

}

bool push(Stack *S, studType student){

}

bool pop(Stack *S){

}

studType popReturn(Stack *S){
    
}

void top(Stack S){

}

void display1(Stack S){
    
} 

void display2(Stack S){
    
} 

void display3(Stack S){
    
} 

void display4(Stack S){
    
} 