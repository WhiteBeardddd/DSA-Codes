#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    char elem;
    struct Node *next;
}*List;

bool searchElem(List *A, char x);
void insertElem(List *A, char x);
void display(List A);

int main (){
    List node1 = malloc(sizeof(struct Node));
    List node2 = malloc(sizeof(struct Node));
    List node3 = malloc(sizeof(struct Node));

    List A = malloc(sizeof(struct Node));
    A->elem=' ';
    A->next = node1;

    node1->elem = 'u';
    node1->next = node2;

    node2->elem = 's';
    node2->next = node3;

    node3->elem = 'c';
    node3->next = NULL;

    if (!node1 || !node2 || !node3 || !A) {
    printf("Memory allocation failed\n");
    return 1;
}


    insertElem(&A,'B');
    bool isHere = searchElem(&A, 'B');
    printf("%s", isHere? "true": "false");
    display(A);

    return 0;
}


bool searchElem(List *A, char x){
    List p;
    for(p = *A; p != NULL && p->elem != x; p = p->next){}
    return (p != NULL) ? true : false;   
}

void insertElem(List *A, char x){
    List temp = malloc(sizeof(struct Node));
    // temp = *A; 
    temp->elem = x;
    temp->next = (*A)->next;
    (*A)->next = temp;
}

void display(List A){
    // for(trav = A; trav->next != NULL; trav = trav->next){
    //     printf("%c \n", trav->elem);
    // }
    List trav = A->next;
    while (trav != NULL)
    {
        printf("%c ", trav->elem);
        trav = trav->next;
    }
    printf("\n");
    
}