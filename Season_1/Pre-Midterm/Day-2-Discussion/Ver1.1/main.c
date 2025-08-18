#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    char elem;
    struct node *next;
}*List, Node;

void initList(List *L);
void insertFirst(List *L, char data);
void display(List L);

int main(){
    List elemList;
    
    initList(&elemList);
    insertFirst(&elemList, 'U');
    insertFirst(&elemList, 'S');
    insertFirst(&elemList, 'C');

    display(elemList);

    free(elemList);
    return 0;
}

void initList(List *L){
    *L = NULL;
}

void insertFirst(List *L, char data){
    List newNode = malloc(sizeof(Node));
    newNode->elem = data;
    newNode->next = NULL;

    if(*L == NULL){
        *L = newNode;
    }else{
        newNode->next = *L;
        *L = newNode;
    }
}

void display(List L){
    List trav = L;

    while (trav != NULL)
    {
        printf("%c\n", trav->elem);
        trav = trav->next;
    }
    
}