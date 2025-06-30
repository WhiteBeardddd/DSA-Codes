#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct node{
    char data;
    struct node *link;
}*LinkList;

typedef struct{
    char data;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int CurList;

// void insertFirst(LinkList *L, char X){
//     LinkList temp = (LinkList)malloc(sizeof(struct node));
//     if(temp != NULL){
//         temp->data = X;
//         temp->link = *L;
//         *L = temp;
//     }
// }

int allocSpace(VirtualHeap *VH){
    int temp = VH->Avail;
    if (temp != -1){
        VH->Avail = VH->Nodes[temp].link; // Updates Avail to point to the next free node that is != -1
    }
    return temp;
}

void insertFirst(VirtualHeap *VH, CurList *x, char data){
    CurList temp = allocSpace(VH);
    if(temp != -1){
        VH->Nodes[temp].data = data;
        VH->Nodes[temp].link = *x;
        *x = temp;
    }
}
// void displayList(VirtualHeap VH, CurList X){
//     if(X != -1){
//         for( ; X != -1; X = VH.Nodes[X].link){
//             printf("%c", VH.Nodes[X].data);
//         }
//     }
// }
