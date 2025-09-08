#include <stdio.h>
#define MAX 10

// TREE PRIORITY QUEUE //

typedef struct{
    int elem[MAX];
    int lastndx;
}Heap;

void initHeap(Heap *H){
    H->lastndx = 0;
    for(int i = 0; i < MAX; i++){
        H->elem[i] = -1;
    }
}

void enqueueHeap(Heap *H, int elem){
    if(H->lastndx < MAX){ // if FULL //
        int i, lndx;
        for(lndx = H->lastndx, i = (lndx - 1) / 2; H->elem[i] < elem && lndx > 0 ; lndx = i, i = (lndx - 1) / 2){
            H->elem[lndx] = H->elem[i];
        }
        H->elem[lndx] = elem;
        H->lastndx++;
    }else{
        printf("List is full");
    }
}

int dequeueHeap(Heap *H){ // Delete and Return last ndx MIN HEAP //
    int temp = H->elem[H->lastndx--];
    if(temp != 0){ // Not EMTPY //
        int parent = 0;
        int LC = parent * 2 + 1;
        int RC = parent * 2 + 2;
        int child = (H->elem[LC] < H->elem[RC])? LC: RC;

        for(;LC != -1 && (LC != -1 || RC != -1);){

        }

    }else{
        printf("Nothing to Delete List is Empty");
    }
}