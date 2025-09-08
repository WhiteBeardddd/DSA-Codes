#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char FNAME[24];
    char LName[16];
    char MI;
}person;

typedef struct {
    person N;
    int ID;
    int year;
    char course[8];
}student;

typedef struct node {
    student data;
    struct node *link;
}*Nodetype;

typedef struct{
    Nodetype p;
    int cnt;
}LIST;

student deleteLast(LIST *A) {
    student S = {.ID = 0};  // Default return
    Nodetype *trav, temp;

    if (A->cnt > 0) {
        for (trav = &A->p; (*trav)->link != NULL; trav = &(*trav)->link) {}
        
        temp = *trav;         // Store the last node
        S = temp->data;       // Copy the data
        *trav = NULL;         // Unlink the last node
        free(temp);           // Free the memory

        A->cnt--;             // Update counter
    }

    return S;
}



//DELETE LAST USING PPN//

int main (){

}