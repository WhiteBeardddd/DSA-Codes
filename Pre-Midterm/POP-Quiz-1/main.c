#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
}person;

typedef struct node{
    person name;
    struct node *next;
}NodeType;

typedef struct{
    NodeType *ptr;
    int cnt;
}LIST;

bool findElem(LIST L, char fname[]);
bool findElem(LIST L, char fname[]){
    NodeType *trav;
    for(trav = L.ptr; trav != NULL && strcmp(trav->name.FName, fname) != 0; trav = trav->next){}
    return (trav != NULL)? true : false;
}


int main() {
    LIST myList;
    myList.ptr = NULL;
    myList.cnt = 0;

    // Manually allocate and assign nodes
    NodeType *n1 = malloc(sizeof(NodeType));
    NodeType *n2 = malloc(sizeof(NodeType));
    NodeType *n3 = malloc(sizeof(NodeType));

    strcpy(n1->name.FName, "John");
    strcpy(n1->name.LName, "Doe");
    n1->name.MI = 'A';
    n1->next = n2;

    strcpy(n2->name.FName, "Alice");
    strcpy(n2->name.LName, "Smith");
    n2->name.MI = 'B';
    n2->next = n3;

    strcpy(n3->name.FName, "Charlie");
    strcpy(n3->name.LName, "Brown");
    n3->name.MI = 'C';
    n3->next = NULL;

    myList.ptr = n1;
    myList.cnt = 3;

    // Sample search calls
    printf("Searching for 'Alice': %s\n", findElem(myList, "Alice") ? "Found" : "Not Found");
    printf("Searching for 'Bob': %s\n", findElem(myList, "Bob") ? "Found" : "Not Found");

    // Free memory
    free(n1);
    free(n2);
    free(n3);

    return 0;
}