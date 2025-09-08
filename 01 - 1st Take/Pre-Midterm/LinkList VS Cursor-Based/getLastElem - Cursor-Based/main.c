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

NameType getLastElem(VirtualHeap VH, CurList Clist){
    NameType dummy = {"XXXXX","XXXXX",'X'};
    for(;VH.Nodes[Clist].link != -1; Clist = VH.Nodes[Clist].link){}
    return (Clist != -1)? VH.Nodes[Clist].data : dummy;
}