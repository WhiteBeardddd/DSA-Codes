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

NameType getAndDeleteLastElem(List *L) {
    NameType rdata = {"XXXXX", "XXXXX", 'X'};
    if (*L != NULL) {
        List *temp;
        for (temp = L; (*temp)->link != NULL; temp = &(*temp)->link);
        rdata = (*temp)->data;
        free(*temp);
        *temp = NULL;
    }
    return rdata;
}
