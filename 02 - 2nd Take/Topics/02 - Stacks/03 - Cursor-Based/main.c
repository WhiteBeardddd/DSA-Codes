#include <stdio.h>
#include "functions.c"

int main(){
    VirtualHeap VH;
    Stack S;

    initHeap(&VH);
    initList(&S);

    nameType n2 = {"Luke", "Cabahug", 'E'};

    studType s1 = createStudent((nameType){"Clarence","Diangco",'C'},101,"BSIT");
    studType s2 = {n2, 102, "BSIT"};
    studType s3 = {{"Alice", "Brown", 'C'}, 103, "BSCE"};

    printf("Pushing students...\n");
    push(&S, &VH, s1);
    push(&S, &VH, s2);
    push(&S, &VH, s3);

    printf("\nDisplaying stack (display1: Top → Bottom):\n");
    display1(S, VH);

    printf("\nTop element:\n");
    top(S, VH);

    printf("\nPop one element...\n");
    pop(&S, &VH);
    printf("After pop (display2: Bottom → Top):\n");
    display2(S, VH);

    printf("\nPop and return:\n");
    studType popped = popReturn(&S, &VH);
    printf("Popped -> %s %c %s, id: %d, course: %s\n",
           popped.studName.FName,
           popped.studName.MI,
           popped.studName.LName,
           popped.id,
           popped.course);

    printf("\nFinal stack (display3: Bottom → Top):\n");
    display3(S, VH);

    printf("\nClearing stack...\n");
    makeNull(&S, &VH);
    printf("After clear:\n");
    display4(S, VH);

    return 0;
}
