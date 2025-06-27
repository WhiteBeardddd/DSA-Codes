#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char LName[16];
    char FName[24];
    char MI;
}person;

typedef struct {
    person name;
    unsigned int ID;
    int year;
    char course[8];
}studInfo;

typedef struct node{
    studInfo student;
    struct node *link;
}NodeType, *LIST;

person findElem(LIST L, unsigned int id);

person findElem(LIST L, unsigned int id){
    LIST trav;
    for(trav = L; trav != NULL && trav->student.ID != id; trav = trav->link){}
    person dname = {"Boquecosa", "Charles Benedict", 'G'};

}