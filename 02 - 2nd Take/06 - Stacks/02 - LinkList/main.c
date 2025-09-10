#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}nameType;

typedef struct{
    nameType studName;
    int id;
    char course[8];
}studType;

typedef struct{
    int top;
    studType studRec[MAX];
}Stack;