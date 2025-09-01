#include <stdio.h>
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
void initLIST(VirtualHeap *VH); 
void displayList(VirtualHeap VH, CurList X);
void insertFirst(VirtualHeap *VH, CurList *X, NameType data);
void insertLast(VirtualHeap *VH, CurList *X, NameType data);
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

void initLIST(VirtualHeap *VH){
    int x, i;
    VH->Avail = MAX - 1;
    for(x = 0, i = -1; x < MAX; x++, i++){
        VH->Nodes[x].link = i;
    }
}

void displayList(VirtualHeap VH, CurList X){
    CurList trav;
    for(trav = X; trav != -1; VH.Nodes[trav].link){
        print("%c", VH.Nodes[trav].data);
    }
}

void insertFirst(VirtualHeap *VH, CurList *X, NameType data){
    CurList temp = allocSpace(VH);
    if (temp != -1){
        VH->Nodes[temp].data = data;
        VH->Nodes[temp].link = *X;
        *X = temp;
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

void deleteElem(VirtualHeap *VH, CurList *L, NameType data){
    
}

void deleteAt(VirtualHeap *VH, CurList *L, int pos){

}

void deleteLast(VirtualHeap *VH, CurList *L, NameType data){

}

// initLIST(). The function will initialize the List to be empty.
// insertFirst(). The function will insert element x at the first position of the List L.
// insertLast(). The function will insert element x at the last position of the List L.
// insertSorted(). The function will insert element x in its appropriate position in the sorted List L.
// delete(). The function will delete the element x from the List L if it exists. 