#include <stdio.h>
#include "functions.c"

int main(){
    Stack S;
    initList(&S);

    nameType n2 = {"Luke","Cabahug",'E'};

    studType s1 = createStudent((nameType){"Clarence","Diangco",'C'},102,"BSIT");
    studType s2 = {n2, 102, "BSIT"};
    studType s3 = {{"Alice", "Brown", 'C'}, 103, "BSCE"};

    printf("Pushing students...\n");
    push(&S, s1);
    push(&S, s2);
    push(&S, s3);

    printf("\nDisplaying stack:\n");
    display1(S);

    printf("\nTop element:\n");
    top(S);

    printf("\nPop one element...\n");
    pop(&S);
    display2(S);

    printf("\nPop and return:\n");
    studType popped = popReturn(&S);
    printf("Popped -> %s %c %s, id: %d, course: %s\n",
           popped.studName.FName,
           popped.studName.MI,
           popped.studName.LName,
           popped.id,
           popped.course);

    printf("\nFinal stack:\n");
    display3(S);

    return 0;
}
