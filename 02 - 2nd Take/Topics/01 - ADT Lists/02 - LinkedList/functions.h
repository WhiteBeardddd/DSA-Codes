#ifndef FUNCTIONS_H
#define FUNCTIONS_H
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
void makenull(charList *List);
charList createNode(char X);

#endif
