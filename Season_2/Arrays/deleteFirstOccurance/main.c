#include <stdio.h>
#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
}charList;

void deleteFirstOccurance(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        int i;
        for(i = 0; i < L->count && L->elem[i] != x; i++){}
        if(i < L->count){
            L->count--;
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
