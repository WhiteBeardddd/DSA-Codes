#include <stdio.h>
#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

void deleteAllOccurance(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        int flag = L->count; // flag for checking if the element exist
        for(int i = 0; i < L->count; i++){
            if(L->elem[i] == x){
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--;
                i--;
            }
        }
        if(flag == L->count){
            printf("element does not exist");
        }
    }else{
        printf("List is empty");
    }
}
