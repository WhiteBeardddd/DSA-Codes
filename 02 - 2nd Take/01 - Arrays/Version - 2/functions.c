#include <stdio.h>
#include "functions.h"

void initList(charList *L){
    L->count = 0;
}

void makeNull(charList *L){
    L->count = 0;
}

void display(charList L){
    if(L.count != 0){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i]);
            {
                if(i < L.count - 1){
                    printf(",");
                }
            }
        }
    }else{
        printf("Nothing no display, List is empty!\n");
    }
}