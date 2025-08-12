#include <stdio.h>
#include <stdbool.h>
#define MAX 10 

typedef struct{
    char elem[MAX];
    char elemCount;
}List;

bool searchElement(List L, char ch);

int main(){
    List L = { "usc", 3};
    bool isfound = searchElement(L,'s');
    printf("%s", isfound? "true" : "false");
    return 0;
}

bool searchElement(List L, char ch){
    int i;
    for(i = 0; i < L.elemCount && ch != L.elem[i]; i++){}
    return (ch == L.elem[i])? true : false;
}