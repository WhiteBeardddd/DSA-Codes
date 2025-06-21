#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    char elem;
    struct node *next;
}*List, Node;

void initList(List *L);
void insertFirst(List *L, char data);

int main(){
    List elemList;
    
    initList(&elemList);
    insertNode(&elemList, 'U');
    insertNode(&elemList, 'S');
    insertNode(&elemList, 'C');

    printf("%c", elemList->elem);
    printf("%c", elemList->next->elem);
    printf("%c", elemList->next->next->elem);

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