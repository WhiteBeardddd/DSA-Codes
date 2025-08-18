#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char elem;
  struct node *link;
}*charList; 

// C - 1
void deleteElem(charList *list, char X);
void insertFirst(charList *list, char X);
void init(charList *list);
void display(charList list);

void deleteElem(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        for(trav = list; (*trav)->link != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            charList temp;
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }
    }
}

void init(charList *list){
    *list = NULL;
}

void insertFirst(charList *list, char X){
    charList newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = X;
        newNode->link = *list;
        *list = newNode;
    }else{
        printf("Memory Allocation failed");
    }
}

void display(charList list){
    if(list != NULL){
        for(;list != NULL; list = list->link){
            printf("%c ", list->elem);
        }
    }else{
        printf("List is empty");
    }
}

int main(){
    charList List;
    init(&List);

    // make first, second, third
    insertFirst(&List, 'U');
    insertFirst(&List, 'S');
    insertFirst(&List, 'C');

    deleteElem(&List, 'S');

    display(List);

    return 0;
}