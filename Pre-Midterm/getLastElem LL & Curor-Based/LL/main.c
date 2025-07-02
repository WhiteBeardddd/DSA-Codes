#include <stdio.h>

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}NameType;

typedef struct node{
    NameType data;
    struct node *link;
}*List;

NameType getLastElem(List L, NameType data){
    NameType rdata = {"XXXXX","XXXXX",'X'};
    if(L != NULL){
        for(;L->link != NULL; L = L->link){}
        return (L != NULL) ? L->data: rdata;
    }    
}