#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

// Deletes the first occurrence of a given element x in the list
void deleteFirstOccurance(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        int i;
        // Search for the element x in the list
        for(i = 0; i < L->count && L->elem[i] != x; i++){}

        // If found, shift all elements after it one step left
        if(i < L->count){
            L->count--; // reduce list size
            
            //shifting logic
            for(; i < L->count; i++){
                L->elem[i] = L->elem[i + 1];
            }
        }else{
            printf("element does not exist!");
        }
    }else{
        printf("List is empty");
    }
}