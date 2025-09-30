#include <stdio.h>
#define SIZE 10

// version 1
typedef struct{
    char elem[SIZE];
    int count;
}charList;

void initList(charList *L);
void delete(charList *L, char x);
void display(charList L);


void initList(charList *L){
    L->count = 0; // initializes List
}

void delete(charList *L, char x){
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

void deleteAllOccurance(charList *L, char x){
    if(L->count != 0){ // Checks if List is not Empty
        for(int i = 0; i < L->count; i++){
            if(L->elem[i] == x){
                for(int j = i; j < L->count - 1; j++){
                    L->elem[j] = L->elem[j + 1];
                }
                L->count--;
                i--;
            }
        }
            // printf("element does not exist!");
    }else{
        printf("List is empty");
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
    charList list = {"Nigger", 6};
    
    printf("Original List: ");
    display(list);
    
    printf("\n");
    printf("Delete First: ");
    deleteAllOccurance(&list, 'g'); // deletes C if it exist
    display(list);
    // printf("\n");
    // printf("Delete Middle: ");
    // delete(&list, 'e'); // deletes e if it exist
    // display(list);
    
    // printf("\n");
    // printf("Delete Last: ");
    // delete(&list, 'z'); // deletes z if it exist
    // display(list);
    
    // printf("\n");
    // printf("Does not Exist: ");
    // delete(&list, 'V'); // deletes z if it exist
    // printf("\n");
    // display(list);
    

    return 0;
}