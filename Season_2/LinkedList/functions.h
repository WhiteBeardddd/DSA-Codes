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
