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

typedef int cList;

// HELPER FUNCTIONS  PROTOTYPES //
void initList(VirtualHeap *VH, cList *l); 
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void displayList(VirtualHeap VH, cList L);

// CRUD FUNCTIONS & MORE //
void insertFirst(VirtualHeap *VH, cList *L, NameType data);
void insertLast(VirtualHeap *VH, cList *L, NameType data);
void insertLastUnique(VirtualHeap *VH, cList *L, NameType data);
void deleteFirstOccurance(VirtualHeap *VH, cList *L, NameType data);

// HELPER FUNCTIONS //
void initList(VirtualHeap *VH, cList *L){
    VH->Avail = MAX - 1;
    for(int i = 0; i < MAX; i++){
        VH->Nodes[i].link =  i - 1;
    }
    *L = -1;
}   

int allocSpace(VirtualHeap *VH){
    cList temp = VH->Avail;
    if(temp != -1){
        VH->Avail = VH->Nodes[temp].link;
    }
    return temp;
}

void deallocSpace(VirtualHeap *VH, int index){
    VH->Nodes[index].link = VH->Avail;
    VH->Avail = index;
}

void displayList(VirtualHeap VH, cList L){
    cList trav;
    for(trav = L; trav != -1; trav = VH.Nodes[trav].link){
        printf("%s %c. %s\n", VH.Nodes[trav].data.FName, VH.Nodes[trav].data.MI, VH.Nodes[trav].data.LName);
  }
    printf("\n");
}

// CRUD FUNCTIONS & MORE //
void insertFirst(VirtualHeap *VH, cList *L, NameType data){
    cList newNode = allocSpace(VH);
    if(newNode != -1){
        VH->Nodes[newNode].data = data;
        VH->Nodes[newNode].link = *L;
        *L = newNode;
    }else{
        printf("no available space left.!\n");
    }
}

void insertLast(VirtualHeap *VH, cList *L, NameType data){
    cList newNode = allocSpace(VH);
    if(newNode != -1){
        cList *trav;
        for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
        *trav = newNode; 
        VH->Nodes[newNode].data = data;
        VH->Nodes[newNode].link = -1;
    }else{
        printf("no available space left.!\n");
    }
}

void insertLastUnique(VirtualHeap *VH, cList *L, NameType data){
    cList newNode = allocSpace(VH);
    if(newNode != -1){
        cList *trav;
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

void deleteFirstOccurance(VirtualHeap *VH, cList *L, NameType data){
    cList *trav;
    for(trav = L; *trav != - 1 && strcmp(VH->Nodes[*trav].data.FName, data.FName) != 0; trav = &VH->Nodes[*trav].link){}

    if(*trav != -1){
        cList temp = *trav;
        *trav = VH->Nodes[temp].link;
        deallocSpace(VH, temp);
    }else{
        printf("Element does not exist\n");
    }

}
int main(){
    VirtualHeap VH;
    cList List;
    
    // Sample data
    NameType stud1 = {"John Mark", "Gerozaga", 'X'};
    NameType stud2 = {"Alice", "Reyes", 'B'};
    NameType stud3 = {"Bob", "Dela Cruz", 'C'};
    NameType stud4 = {"Alice", "Reyes", 'B'}; // duplicate (for insertLastUnique)
    NameType stud5 = {"Eve", "Santos", 'D'};

    initLIST(&VH, &List);

    printf("=== INSERT FIRST ===\n");
    insertFirst(&VH, &List, stud1);
    displayList(VH, List);

    printf("=== INSERT LAST ===\n");
    insertLast(&VH, &List, stud2);
    insertLast(&VH, &List, stud3);
    displayList(VH, List);

    printf("=== INSERT LAST UNIQUE (duplicate attempt) ===\n");
    insertLastUnique(&VH, &List, stud4); // should say "Element Exist"
    displayList(VH, List);

    printf("=== INSERT LAST UNIQUE (new element) ===\n");
    insertLastUnique(&VH, &List, stud5);
    displayList(VH, List);

    printf("=== DELETE FIRST OCCURRENCE (Alice) ===\n");
    deleteFirstOccurance(&VH, &List, stud2); // stud2 is "Alice Reyes"
    displayList(VH, List);

    printf("=== DELETE FIRST OCCURRENCE (Not Found) ===\n");
    NameType ghost = {"Ghost", "Nobody", 'Z'};
    deleteFirstOccurance(&VH, &List, ghost);
    displayList(VH, List);

    return 0;
}
