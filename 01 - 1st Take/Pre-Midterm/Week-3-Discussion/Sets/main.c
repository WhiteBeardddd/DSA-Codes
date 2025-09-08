#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int SET[MAX];

SET *UNION(SET A, SET B){
    SET *C = malloc(sizeof(SET));
    int i;
    for(i = 0; i < MAX; i++){
        (*C)[i] = A[i] || B[i];
    }
    return C;
}

void display(SET A){
    for(int i = 0; i < MAX; i++){
        printf("%d", A[i]);
    }
}

int main(){
    SET A, B;
    SET *C = UNION(A, B);

    display(A);
    return 0;
}