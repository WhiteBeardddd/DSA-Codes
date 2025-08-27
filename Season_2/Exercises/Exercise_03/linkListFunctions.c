#include <stdio.h>
#include "functions.h"

//* Helper Functions for ArrayList *//
void initLList(LinkList *L){
    *L = NULL;
}

void makeNullLinkedList(LinkList *L){
    LinkList temp;
    while(*L != NULL){
        temp = *L;
        *L = (*L)->link;
        free(temp);
    }
    *L = NULL;
}

void displayLList(LinkList L) {
    if (L != NULL) {
        printf("\n%-10s %-10s %-5s %-30s\n", "ID", "Course", "Year", "Name");
        printf("--------------------------------------------------------------\n");
        while (L != NULL) {
            printf("%-10s %-10s %-5d %s %c. %s\n",
                   L->stud.ID,
                   L->stud.course,
                   L->stud.yrlevel,
                   L->stud.name.FN,
                   L->stud.name.MI,
                   L->stud.name.LN);
            L = L->link;  // move to the next node
        }
    } else {
        printf("List is empty\n");
    }
}

LinkList createStud(char ID[], char FN[], char LN[], char MI, char course[], int yrlevel){
    LinkList newNode = malloc(sizeof(struct cell));
    if(newNode != NULL){
        newNode->link = NULL;
        strcpy(newNode->stud.name.FN, FN);
        strcpy(newNode->stud.name.LN, LN);
        strcpy(newNode->stud.name.MI, MI);
        strcpy(newNode->stud.course, course);
        strcpy(newNode->stud.ID, ID);
        newNode->stud.yrlevel = yrlevel;
    }
    return (newNode != NULL)? newNode: NULL;
}

//* Main Functions for ArrayList *//
void inserFirstLinkList(LinkList *L, studtype newStud){

}

void inserLastLinkList(LinkList *L, studtype newStud){

}
void insertLastUniqueLinkList(LinkList *L, studtype newStud){

}

void inserAtPositionLinkList(LinkList *L, studtype newStud, int pos){

}

studtype deleteElemLinkList(LinkList *L, char ID[]){

}

ArrayList separateCourseLinkList(LinkList *L, char course[]){
    
}