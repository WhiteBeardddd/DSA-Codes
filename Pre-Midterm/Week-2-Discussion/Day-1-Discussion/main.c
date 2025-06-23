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



