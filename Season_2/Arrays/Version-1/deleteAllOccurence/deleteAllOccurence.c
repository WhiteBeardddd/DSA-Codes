#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

// Deletes all occurrences of a given element x in the list
void deleteAllOccurence(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        for(int i = 0; i < L->count; i++){
            if(L->elem[i] == x){
                // Shift elements left to overwrite the found element
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--; // reduce list size
                i--; // recheck current index (since it has new value)
            }
        }
            // printf("element does not exist!");
    }else{
        printf("List is empty");
    }
}
