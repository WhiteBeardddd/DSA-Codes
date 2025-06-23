#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 24

typedef char string[MAX];

typedef struct{
    string LName;
    string FName;
    char MI;
}NameType;

typedef struct node{
    NameType name;
    struct node *next;
}NodeType, *NodePtr;

typedef struct {
    NodeType *ptr;
    int cnt;
}List;

bool findElem(List A, char first[]){
    NodePtr trav;
    for(trav = A.ptr; trav != NULL && strcmp(trav->name.FName,first) != 0; trav = trav->next){}
    return (trav != NULL)? true : false;
}

