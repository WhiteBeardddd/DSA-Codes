<<<<<<< HEAD
#ifndef FUNCTIONS_H
#define FUNCTIONS_H 
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> 03894d1dd56a1c3bf92549bac1967ccf8bcba18c

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
<<<<<<< HEAD


#endif
=======
>>>>>>> 03894d1dd56a1c3bf92549bac1967ccf8bcba18c
