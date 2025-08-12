#include <stdio.h>
#define SIZE 10

// version 2
typedef struct{
    char *elem;
    int count;
}charList;

void initList(charList *L);
void delete(charList *L, char x);
void display(charList L);

void initList(charList *L){
    L->elem = (char*)malloc(sizeof(char)*SIZE);
    L->count = 0;
}

void delete(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        for(int i = 0; i < L->count; i++){ // to find x
            if(L->elem[i] == x){
                for(int j = i; j < L->count; j++){ // to shift starting from x
                    L->elem[j] = L->elem[j + 1]; // shifting
                }
                L->count--;
            }
        }    
    }
}

void display(charList L){
    if(L.count != 0){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i]);
            if (i < L.count - 1 ){
                printf(",");
            }
        }
    }
}

int main() {
    charList list = {"Clarence", 8};
    display(list);
    printf("\n");
    delete(&list, 'C'); // deletes the character that is passed if it is found
    display(list);
    
    return 0;
}