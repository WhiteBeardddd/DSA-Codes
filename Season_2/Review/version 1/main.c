// Online C compiler to run C program online
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
        for(int i = 0; i < L->count; i++){ // to find x
            if(L->elem[i] == x){
                for(int j = i; j < L->count; j++){ // to shift starting from x
                    L->elem[j] = L->elem[j + 1]; // shifting
                }
                L->count--;
                break;
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
    charList list = {"Clarencz", 9};
    
    printf("Original List: ");
    display(list);
    
    printf("\n");
    printf("Delete First: ");
    delete(&list, 'C'); // deletes C if it exist
    display(list);
    
    printf("\n");
    printf("Delete Middle: ");
    delete(&list, 'e'); // deletes e if it exist
    display(list);
    
    printf("\n");
    printf("Delete Middle: ");
    delete(&list, 'z'); // deletes z if it exist
    display(list);
    
    
    return 0;
}