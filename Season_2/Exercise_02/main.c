#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char elem;
  struct node *link;
}*charList; 

// C - 1
void insertFirst(charList *list, char X);
void insertLast(charList *list, char X);
void insertLastUnique(charList *list, char X);
void deleteElem(charList *list, char X);
void deleteAllOccur(charList *list, char X);


// Helper Function Prototypes
void init(charList *list);
void display(charList list);
charList createNode(char X);

// Main Functions
void insertFirst(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        newNode->link = *list;
        *list = newNode;
    }else{
        printf("Memory Allocation failed");
    }
}

void insertLast(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        for(trav = list; *trav != NULL; trav = &(*trav)->link){}
        // newNode->link = NULL;  // No need since it's done in insertLast
        *list = newNode;
    }else{
        printf("Memory Allocation failed");
    }
}

void insertLastUnique(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(trav != NULL){
            printf("Element Exist in the list, insert is invalid");
        }else{
            *list = newNode;
        }
    }

}

void deleteElem(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            charList temp;
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }else{
            printf("Element '%c' does not exist", X);
        }
    }else{
        printf("Nothing to delete List is empty");
    }
}

void deleteAllOccur(charList *list, char X){
    if(*list != NULL){
        charList *trav;
        for(trav = list; *trav != NULL;){
            if((*trav)->elem == X){
                charList temp = *trav;
                *trav = temp->link;
                free(temp);
            }else{
                trav = &(*trav)->link;
            }
        }
    }else{
        printf("Nothing to delete List is empty");
    }
}

// Helper Functions
void init(charList *list){
    *list = NULL;
}

charList createNode(char X){
    charList newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = X;
        newNode->link = NULL;
    }
    return (newNode != NULL)? newNode : NULL;
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