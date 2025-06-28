#define MAX 7

typedef struct{
    char data;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int L;

int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void initLIST(VirtualHeap *VH); 

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


// initLIST(). The function will initialize the List to be empty.
// insertFirst(). The function will insert element x at the first position of the List L.
// insertLast(). The function will insert element x at the last position of the List L.
// insertSorted(). The function will insert element x in its appropriate position in the sorted List L.
// delete(). The function will delete the element x from the List L if it exists. 