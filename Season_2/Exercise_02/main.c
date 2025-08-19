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
void insertSorted(charList *list, char value);
void sortList(charList *list);

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
        printf("Memory Allocation failed\n");
    }
}

void insertLast(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        for(trav = list; *trav != NULL; trav = &(*trav)->link){}
        // newNode->link = NULL;  // No need since it's done in insertLast
        *trav = newNode;
    }else{
        printf("Memory Allocation failedv");
    }
}

void insertLastUnique(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        for(trav = list; *trav != NULL && (*trav)->elem != X; trav = &(*trav)->link){}
        if(*trav != NULL){
            printf("Element Exist in the list, insert is invalid\n");
            free(newNode);
        }else{
            // newNode->link = NULL;  // No need since it's done in insertLast
            *trav = newNode;
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
            printf("Element '%c' does not exist\n", X);
        }
    }else{
        printf("Nothing to delete List is empty\n");
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
        printf("Nothing to delete List is empty\n");
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

// void insertSorted(charList *list, char value) {

//     charList newNode = malloc(sizeof(struct node));
//     newNode->elem = value;
//     newNode->link = NULL;

//     charList *temp;
//     for(temp = list; *temp != NULL && (*temp)->elem < value; temp = &(*temp)->link) {
//         printf("1-");
//     }
//     newNode->link = *temp;
//     *temp = newNode;

// }

void sortList(charList *list) {
    while(*list != NULL || (*list)->link != NULL)
    {
        charList *holdList = list;
        for(charList *temp = (*list)->link; *temp != NULL; temp = &(*temp)->link) {
            if((*holdList)->elem > (*temp)->elem){
                holdList = *temp;
            }
        }

        list = &(*list)->link;
    }
}

void insertSorted(charList *list, char X){
    charList newNode = createNode(X);
    if(newNode != NULL){
        charList *trav;
        for(trav = list; *trav != NULL && (*trav)->elem < X; trav = &(*trav)->link){}
        newNode->link = *trav;
        *trav = newNode;
    }else{
        printf("Memory Allocation Failed");
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
    insertFirst(&List, 'C');
    insertFirst(&List, 'S');
    insertFirst(&List, 'U');
    printf("Original List\n");
    display(List);
    
    printf("\n");
    insertLastUnique(&List, 'C');
    
    insertLastUnique(&List, 'D');
    
    printf("Display 1: ");
    display(List);
    printf("\n");

    deleteElem(&List, 'S');

    printf("Display 2: ");
    display(List);

    printf("\n");
    sortList(&List);
    printf("Display 3: ");
    display(List);

    printf("\n");
    insertSorted(&List, 'E');
    insertSorted(&List, 'Z');
    printf("Display 4: ");
    display(List);

    return 0;
}