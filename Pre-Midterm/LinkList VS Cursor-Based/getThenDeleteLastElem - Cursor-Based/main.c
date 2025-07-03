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

NameType getAndDeleteLastElem(VirtualHeap *VH, CurList *L) {
    NameType dummy = {"XXXXX", "XXXXX", 'X'};
    if (*L != -1) {
        CurList *trav;
        for (trav = L; VH->Nodes[*trav].link != -1; trav = &VH->Nodes[*trav].link){}
        
        dummy = VH->Nodes[*trav].data;
                
        int temp = *trav;
        *trav = VH->Nodes[temp].link; 
        VH->Nodes[temp].link = VH->Avail;
        VH->Avail = temp;
    }
    return dummy;
}
