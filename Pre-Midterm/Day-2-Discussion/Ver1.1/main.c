#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node * next;
}*List,Node;

void initializeList(List *L);
void insertFirst(List *List, char data);
void display(List L);

int main(){
    List elemList;
    initializeList(&elemList);
    insertFirst(&elemList, 'C');
    display(elemList);
    
    return 0;
}

void initializeList(List *L){
    *L = NULL;
}

void insertFirst(List *L, char data){
    List newNode = malloc(sizeof(Node));
    newNode->elem = data;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}

void display(List L){
    List trav = L;
    while (trav != NULL){
        printf("%c", trav->elem);
    }
    
}