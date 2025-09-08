#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

// Inserts an element at the end of the list
void insertLast(charList *L, char x){
    if(L->count < sizeof(L->elem) / sizeof(L->elem[0])){ // If not full
        L->elem[L->count] = x; // Place at the end
        L->count++;
    }else{
        printf("The Array is full");
    }
}