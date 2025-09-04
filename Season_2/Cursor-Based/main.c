#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 7
typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}NameType;
typedef struct{
    NameType data;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int CurList;


int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void initLIST(VirtualHeap *VH, CurList *l); 
void displayList(VirtualHeap VH, CurList L);

void insertFirst(VirtualHeap *VH, CurList *L, NameType data);
void insertLast(VirtualHeap *VH, CurList *L, NameType data);
void delete(VirtualHeap *VH, CurList *L, NameType data);

int main(){

    return 0;
}

int allocSpace(VirtualHeap *VH){
    int temp = VH->Avail;
    if (temp != -1){
        VH->Avail = VH->Nodes[temp].link; // Updates Avail to point to the next free node that is != -1
    }
    return temp;
}

void deallocSpace(VirtualHeap *VH, int index){
    VH->Nodes[index].link = VH->Avail;
    VH->Avail = index;
}

void initLIST(VirtualHeap *VH, CurList *L){
    int i;
    VH->Avail = MAX - 1;
    for(i = 0; i < MAX; i++){
        VH->Nodes[i].link = i - 1;
    }
    *L = -1;
}

void displayList(VirtualHeap VH, CurList L) {
    CurList trav;
    for (trav = L; trav != -1; trav = VH.Nodes[trav].link) {
        printf("%s %s %c\n",
               VH.Nodes[trav].data.FName,
               VH.Nodes[trav].data.LName,
               VH.Nodes[trav].data.MI);
    }
    printf("\n");
}



void insertFirst(VirtualHeap *VH, CurList *L, NameType data){
    CurList temp = allocSpace(VH);
    if (temp != -1){
        VH->Nodes[temp].data = data;
        VH->Nodes[temp].link = *L;
        *L = temp;
    }else{
        printf("No available space!");
    }
}

void insertLast(VirtualHeap *VH, CurList *L, NameType data){
    int *trav, temp;
    for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
    temp = allocSpace(VH);

    if(temp != -1){
        VH->Nodes[temp].data = data;
        VH->Nodes[temp].link = -1;
        *trav = temp;
    }
}

void insertLastUnique(VirtualHeap *VH, CurList *L, NameType data){
    CurList *trav;
    
    for(trav = L; *trav != NULL && strcmp(VH->Nodes[*trav].data.FName, data.FName) != 0; trav = &VH->Nodes[*trav].link){}
    if(*trav != NULL){
        printf("Element Exist in the list, insert is invalid\n");
        deallocSpace(&VH, trav);
    }else{
        allocSpace(&VH);
        VH->Nodes[*trav].data = data;

    }
}


void deleteElem(VirtualHeap *VH, CurList *L, NameType data) {
    int *trav;
    for (trav = L; *trav != -1 && strcmp(VH->Nodes[*trav].data.FName, data.FName) != 0; trav = &VH->Nodes[*trav].link);

    if (*trav != -1) {
        int temp = *trav;
        *trav = VH->Nodes[temp].link;
        deallocSpace(VH, temp);
    } else {
        printf("Element not found\n");
    }
}

// initLIST(). The function will initialize the List to be empty.
// insertFirst(). The function will insert element x at the first position of the List L.
// insertLast(). The function will insert element x at the last position of the List L.
// insertSorted(). The function will insert element x in its appropriate position in the sorted List L.
// delete(). The function will delete the element x from the List L if it exists. 