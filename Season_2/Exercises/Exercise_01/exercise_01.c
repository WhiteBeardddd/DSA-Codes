#include <stdio.h>
#include <stdbool.h>

// A.) appropriate definition
#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
}charList;

// Helper function prototypes
void initList(charList *L);
void display(charList L);

// Main Functions prototypes
// B - 1
bool findElem(charList list, char X);
// C - 1
void deleteELem(charList *list, char X);
// D - 1
void deleteAllOccur(charList *list, char X);

// B - 4
bool findElem(charList list, char X){
    int i;
    for(i = 0; i < list.count && list.elem[i] != X; i++){}
    // B - 5
    return(i < list.count)? true : false;
}

// C - 4
void deleteELem(charList *list, char X){
    if(list->count != 0){ // Checks if List is not Empty
        int i;
        // Search for the element x in the list
        for(i = 0; i < list->count && list->elem[i] != X; i++){}

        // If found, shift all elements after it one step left
        // C - a
        if(i < list->count){
            list->count--; // reduce list size
            
            //shifting logic
            for(; i < list->count; i++){
                list->elem[i] = list->elem[i + 1];
            }
        }else{
            printf("element does not exist!"); // C - b
        }
    }else{
        printf("List is empty"); // C - c
    }
}

// D - 4
void deleteAllOccur(charList *list, char X){
    
    // VERSION 1 //
    if(list->count != 0){ // Checks if List is not Empty
        bool found = false;

        for(int i = 0; i < list->count;){
            // D - a
            if(list->elem[i] == X){
                // marks that X is found inside the List
                found = true;
                // Shift elements left to overwrite the found element
                for(int j = i; j < list->count - 1; j++){
                    list->elem[j] = list->elem[j + 1];
                }
                list->count--; // reduce list size
            }else{
                i++;
            }
        }
        if(found == false){
            printf("Element '%c' does not exist in the list!\n", X); // D - b
        }
    }else{
        printf("List is empty"); // D - c
    }

    // VERSION 2
    // if(list->count != 0){
    //     int i, j;
    //     bool found = false;
    //     for(i = j = 0; i < list->count; i++){
    //         if(list->elem[i] != X){
    //             list->elem[j] = list->elem[i];
    //             j++;
    //         }
    //     }
    //     list->count = j;
    //     if(found == false){
    //         printf("Element '%c' does not exist in the list!\n", X); // D - b
    //     }
    // }else{
    //     printf("List is empty"); // D - c
    // }
}

// helper functions
void initList(charList *L){
    L->count = 0; 
}

void display(charList L){
    if(L.count != 0){
        for(int i = 0; i < L.count; i++){
            printf("%c", L.elem[i]); // Print each element
            if (i < L.count - 1 ){ // Print commas between elements
                printf(",");
            }
        }
        printf("\n");
    }else{
        printf("Nothing to display, List is empty");
    }
}

int main(){
    charList List = {"USCTC", 5};
    char X = 'C';
    
    printf("Original List:\n");
    display(List);
    // B - 2
    bool isElem = findElem(List, X);

    // printf("After deleteElem:\n");
    // // C - 2
    // deleteELem(&List, X);
    // display(List);

    printf("After deleteAllOccur:\n");
    // D - 2
    deleteAllOccur(&List, X);
    display(List);

    return 0;
}