#include <stdio.h>
#include <string.h>
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

typedef int List;

// HELPER FUNCTIONS  PROTOTYPES //
void initLIST(VirtualHeap *VH, List *l); 
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void displayList(VirtualHeap VH, List L);

// CRUD FUNCTIONS & MORE //
void insertFirst(VirtualHeap *VH, List *L, NameType data);
void insertLast(VirtualHeap *VH, List *L, NameType data);
void insertLastUnique(VirtualHeap *VH, List *L, NameType data);
void deleteFirstOccurance(VirtualHeap *VH, List *L, NameType data);

// HELPER FUNCTIONS //
void initLIST(VirtualHeap *VH, List *L){
    VH->Avail = MAX - 1;
    for(int i = 0; i < MAX; i++){
        VH->Nodes[i].link =  i - 1;
    }
    *L = -1;
}

int allocSpace(VirtualHeap *VH){
    List temp = VH->Avail;
    if(temp != -1){
        VH->Avail = VH->Nodes[temp].link;
    }
    return temp;
}

void deallocSpace(VirtualHeap *VH, int index){
    VH->Nodes[index].link = VH->Avail;
    VH->Avail = index;
}

void displayList(VirtualHeap VH, List L){
    List trav;
    for(trav = L; trav != -1; trav = VH.Nodes[trav].link){
        printf("%s %c. %s\n", VH.Nodes[trav].data.FName, VH.Nodes[trav].data.MI, VH.Nodes[trav].data.LName);
  }
    printf("\n");
}

// CRUD FUNCTIONS & MORE //
void insertFirst(VirtualHeap *VH, List *L, NameType data){
    List newNode = allocSpace(VH);
    if(newNode != -1){
        VH->Nodes[newNode].data = data;
        VH->Nodes[newNode].link = *L;
        *L = newNode;
    }else{
        printf("no available space left.!\n");
    }
}

void insertLast(VirtualHeap *VH, List *L, NameType data){
    List newNode = allocSpace(VH);
    if(newNode != -1){
        List *trav;
        for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
        *trav = newNode; 
        VH->Nodes[newNode].data = data;
        VH->Nodes[newNode].link = -1;
    }else{
        printf("no available space left.!\n");
    }
}

void insertLastUnique(VirtualHeap *VH, List *L, NameType data){
    List newNode = allocSpace(VH);
    if(newNode != -1){
        List *trav;
        for(trav = L; *trav != -1 && strcmp(VH->Nodes[*trav].data.FName, data.FName) != 0; trav = &VH->Nodes[*trav].link){}
        
        if(*trav == -1){
            *trav = newNode; 
            VH->Nodes[newNode].data = data;
            VH->Nodes[newNode].link = -1;
        }else{
            printf("Element Exist in the List");
        }
    }else{
        printf("no available space left.!\n");
    }
}

void deleteFirstOccurance(VirtualHeap *VH, List *L, NameType data){
    List *trav;
    for(trav = L; *trav != - 1 && strcmp(VH->Nodes[*trav].data.FName, data.FName) != 0; trav = &VH->Nodes[*trav].link){}

    if(*trav != -1){
        List temp;
        *trav = VH->Nodes[temp].link;
        deallocSpace(VH, temp);
    }else{
        printf("Element does not exist");
    }

}

int main(){
    VirtualHeap VH;
    List L;
    
    NameType stud1 = {"John Mark", "Gerozaga", 'X'};

    initLIST(&VH, &L);
    insertFirst(&VH, &L, stud1);
    displayList(VH, L);
    

    return 0;
}