#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

// Inserts an element at the beginning of the list
void insertFirst(charList *L, char x){
    if(L->count == 0){ // If list is empty, just place element at 0
        L->elem[0] =  x;
        L->count++;
    }else if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        // Shift elements to the right to make space at the front
        for(int i = L->count; i > 0; i--){
            L->elem[i] = L->elem[i -1];
        }
        L->elem[0] = x; // Place new element at index 0
        L->count++;
    }else{
        printf("The Array is full");
    }
}