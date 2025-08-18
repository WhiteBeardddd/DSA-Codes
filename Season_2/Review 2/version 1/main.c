#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node * link;
}*charList;

// FindElem return bool if it exist
bool findELem(charList L, char x){
    for(; L != NULL; L = L->link){}
    return (L != NULL)? true : false;
}

// Delete First Occurance LinkList using PPN
void deleteFirstOccurance(charList *L, char x){
    charList *trav, temp;
    for(trav = L; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link){} // looks for x until and checks if trav is null
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
}

void insertFirst(charList *L, char x){
    charList temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->link = *L;
        *L = temp;
    }else{
        printf("Memory Allocation Failed");
    }
}

int main(){


    charList list;

    list = NULL;


    insertFirst(&list, 'b');
    insertFirst(&list, 'a');
    insertFirst(&list, 'h');
    insertFirst(&list, 'o');
    insertFirst(&list, '0');
    insertFirst(&list, '1');
    insertFirst(&list, '0');

    
    for(; list != NULL; list = list->link){
        printf("%c ", list->elem);

    }


    return 0;
}