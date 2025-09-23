#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ARR_LENGHT 0XA

typedef struct {
    char FN[24];
    char LN[16];
    char MI;
}nametype;

typedef struct{
    char ID[9];
    nametype name;
    char course[10];
    int yrlevel;
}studtype;

typedef struct{
    studtype studs[ARR_LENGHT];
    int count;
}ArrayList;

typedef struct cell{
    studtype stud;
    struct cell *link;
}*LinkList;


//***  Array Implementation  ***//

//* Helper Functions for ArrayList *// 
void initAList(ArrayList *L);
void displayAList(ArrayList L);

//* Main Functions for ArrayList *//
void inserFirstArray(ArrayList *L, studtype newStud);
void insertLastArray(ArrayList *L, studtype newStud);
void insertLastUniqueArray(ArrayList *L, studtype newStud);
void inserAtPositionArray(ArrayList *L, studtype newStud, int pos);
studtype deleteElemArray(ArrayList *L, char ID[]);
ArrayList separateCourseArray(ArrayList *L, char course[]);

//***  LinkList Implementation  ***//

//* Helper Functions for ArrayList *//
void initLList(LinkList *l);
void makeNullLinkedList(LinkList *l);
void displayLList(LinkList L);

//* Main Functions for ArrayList *//
void inserFirstLinkList(LinkList *L, studtype newStud);
void inserLastLinkList(LinkList *L, studtype newStud);
void insertLastUniqueLinkList(LinkList *L, studtype newStud);
void inserAtPositionLinkList(LinkList *L, studtype newStud, int pos);
studtype deleteElemLinkList(LinkList *L, char ID[]);
LinkList separateCourseLinkList(LinkList *L, char course[]);

#endif