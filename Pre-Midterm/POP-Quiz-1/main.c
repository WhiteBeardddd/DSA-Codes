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

    NodeType *n1 = malloc(sizeof(NodeType));
    NodeType *n2 = malloc(sizeof(NodeType));
    NodeType *n3 = malloc(sizeof(NodeType));

    strcpy(n1->name.FName, "Ivan Kyer");
    strcpy(n1->name.LName, "Jayme");
    n1->name.MI = 'C';
    n1->next = n2;

    strcpy(n2->name.FName, "Godwin");
    strcpy(n2->name.LName, "Monserate");
    n2->name.MI = 'S';
    n2->next = n3;

    strcpy(n3->name.FName, "Charles");
    strcpy(n3->name.LName, "Boki");
    n3->name.MI = 'G';
    n3->next = NULL;

    myList.ptr = n1;

    printf("%s\n", findElem(myList, "Godwin") ? "Found" : "Not Found");
    printf("%s\n", findElem(myList, "Gran") ? "Found" : "Not Found");

    free(n1);
    free(n2);
    free(n3);

    return 0;
}