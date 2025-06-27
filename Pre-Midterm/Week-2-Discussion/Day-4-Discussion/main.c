#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct{
    char data;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int Avail;
}VirtualHeap;