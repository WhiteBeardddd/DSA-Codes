#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    char elem;
    struct Node *next;
}*List;

bool searchElem(List A, char x);

bool searchElem(List A, char x){
    List p;
    for(p = A; p != NULL && p->elem != x; p = p->next){}
    return (p != NULL) ? true : false;   
}

int main (){
    List node1 = malloc(sizeof(List));
    List node2 = malloc(sizeof(List));
    List node3 = malloc(sizeof(List));

    List A = malloc(sizeof(List));

    A->next = node1;

    node1->elem = 'u';
    node1->next = node2;

    node2->elem = 's';
    node2->next = node3;

    node3->elem = 'c';
    node3->next = NULL;

    bool isHere = searchElem(A, 'c');

    printf("%s", isHere? "true": "false");

    return 0;
}