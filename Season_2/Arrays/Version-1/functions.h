#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>
#define SIZE 10

// version 1
typedef struct {
    char elem[SIZE];
    int count;
} charList;

// Function prototypes
void initList(charList *L);
void deleteFirstOccurence(charList *L, char x);
void deleteAllOccurence(charList *L, char x);
void insertFirst(charList *L, char x);
void insertMiddle(charList *L, char x);
void insertLast(charList *L, char x);
bool isExist(charList L, char x);
char locate(charList L, char x);
void display(charList L);

#endif