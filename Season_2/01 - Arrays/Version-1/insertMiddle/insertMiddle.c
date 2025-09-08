#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

// Inserts an element in the middle of the list
void insertMiddle(charList *L, char x){
    if(L->count == 0){ // If empty, just put it at index 0
        L->elem[0] =  x;
        L->count++;
    }else if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        int middle = L->count / 2; // Compute middle index
        // Shift elements to the right starting from the middle
        for(int i = L->count; i > middle; i--){
            L->elem[i] = L->elem[i -1];
        }
        L->elem[middle] = x; // Insert element in middle
        L->count++;
    }else{
        printf("The Array is full");
    }
}
