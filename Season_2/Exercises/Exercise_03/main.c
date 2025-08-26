#include <stdio.h>
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
    char course[8];
    int yrlevel;
}studtype;

// Array Implementation
typedef struct{
    studtype studs[ARR_LENGHT];
    int count;
}ArrayList;

// Linked List Implementation
typedef struct cell{
    studtype stud;
    struct cell *link;
}*LinkList;


// Array Implementation
void initAList(ArrayList *L);
void inserFirstArray(ArrayList *L, studtype newStud);
void inserLastArray(ArrayList *L, studtype newStud);
bool insertLastUniqueArray(ArrayList *L, studtype newStud);
void inserAtPositionArray(ArrayList *L, studtype newStud, int pos);
studtype deleteElemArray(ArrayList *L, char deleteStud[]);

int main() {
    ArrayList AList;
    initAList(&AList);

    // Create some students
    studtype s1 = {"23100750", {"Charles Benedict", "Boquecosa", 'G'}, "CIS-2201", 4};
    studtype s2 = {"23100751", {"Maria", "Santos", 'L'}, "CIS-2201", 3};
    studtype s3 = {"23100752", {"Juan", "Dela Cruz", 'M'}, "CIS-2202", 2};

    // Insert students (unique insert)
    insertLastUniqueArray(&AList, s1);
    insertLastUniqueArray(&AList, s2);
    insertLastUniqueArray(&AList, s3);

    printf("\nCurrent List (%d students):\n", AList.count);
    for (int i = 0; i < AList.count; i++) {
        printf("%s - %s %c. %s\n", 
               AList.studs[i].ID, 
               AList.studs[i].name.FN, 
               AList.studs[i].name.MI, 
               AList.studs[i].name.LN);
    }

    // Try deleting s2
    studtype deleted = deleteElemArray(&AList, "23100751");

    printf("\nDeleted: %s - %s %c. %s\n",
           deleted.ID,
           deleted.name.FN,
           deleted.name.MI,
           deleted.name.LN);

    printf("\nList after deletion (%d students):\n", AList.count);
    for (int i = 0; i < AList.count; i++) {
        printf("%s - %s %c. %s\n", 
               AList.studs[i].ID, 
               AList.studs[i].name.FN, 
               AList.studs[i].name.MI, 
               AList.studs[i].name.LN);
    }

    return 0;
}

// helper functions
void initAList(ArrayList *L){
    L->count = 0;
}

void inserFirstArray(ArrayList *L, studtype newStud){
    if(L->count == 0){
        L->studs[0] = newStud;
    }else if(L->count  < ARR_LENGHT){
        for(int i = L->count; i > 0; i--){
            L->studs[i] = L->studs[i - 1];
        }
        L->studs[0] = newStud;
        L->count++;
    }else{
        printf("The Array is full");
    }
}

void inserLastArray(ArrayList *L, studtype newStud){
    if(L->count != 0 && ARR_LENGHT){
        L->studs[L->count] = newStud;
        L->count++;
    }else{
        printf("The Array is full");
    }
}

bool insertLastUniqueArray(ArrayList *L, studtype newStud){
    if(L->count < ARR_LENGHT){
        bool flag = true;
        for(int i = 0; i < L->count; i++){
            if(strcmp(L->studs[i].ID, newStud.ID) == 0){
                printf("\nElement Exists!, Invalid insert\n");
                flag = false;
            }
        }
        L->studs[L->count] = newStud;
        L->count++;
        return flag;
    }else{
        printf("The Array is full");
    }
}

void inserAtPositionArray(ArrayList *L, studtype newStud, int pos){
    if(L->count == ARR_LENGHT){
        printf("The Array is full");
    }else if(pos < 0 || pos > L->count){
        printf("Invalid Position");
    }else{
        for(int i = L->count; i > pos; i--){
            L->studs[i] = L->studs[i - 1];
        }
        L->studs[pos] = newStud;
        L->count++;
    }
}

studtype deleteElemArray(ArrayList *L, char deleteStud[]){
    studtype dummy = {"XXXXX", {"XXXXX", "XXXXX", 'X'}, "XXXXX", 0};
    bool found = 0;
    if(L->count != 0){
        for(int i = 0; i < L->count; i++){
            if(strcmp(L->studs[i].ID, deleteStud) == 0){
                dummy = L->studs[i];
                L->count--;
                for(int j = i; j < L->count; j++){
                    L->studs[j] = L->studs[j + 1];
                }
                break; // breaks the loop so it wont check the rest since the ID is found
            }
        }
        if(found != 0){
            printf("ID not found");
        }
    }else{
        printf("List is empty");
    }
        return dummy;
}

void separateCourseArray();

// Linked List Implementation
void inserFirstLinkList();
void inserLastLinkList();
void insertLastUniqueLinkList();
void inserAtPositionLinkList();
void deleteElemLinkList();
void separateCourseLinkList();
