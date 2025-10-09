// Given the definition:
#define MAX  10
typedef struct {
  int elem[MAX];
  int lastNdx;   //index of last element
}minHeap;

// Write the code of the function heapifySubtree(). Given the minHeap and the index of the root of the subtree, 
// the function will heapify the subtree (only). 

// Instructions:
// 1) Preformat your answer with font size 10 and Boldface(B).
// 2) Indent your answer

void heapifySubtree(minHeap *H, int root){
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;
    int smallest = root;
    int temp;

    if(left <= H->lastNdx && H->elem[left] < H->elem[smallest]){
        smallest = left;
    }

    if(right <= H->lastNdx && H->elem[right] < H->elem[smallest]){
        smallest = right;
    }

    if(smallest != root){
        temp = H->elem[root];
        H->elem[root] = H->elem[smallest];
        H->elem[smallest] = temp;
        heapifySubtree(H, smallest);
    }
}