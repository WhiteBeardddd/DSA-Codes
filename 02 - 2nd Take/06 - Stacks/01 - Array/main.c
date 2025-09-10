#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}nameType;

typedef struct{
    nameType studName;
    int id;
    char course[8];
}studType;

typedef struct{
    int top;
    studType studRec[MAX];
}Stack;


// initialize the Stack
void initList(Stack *S);

//insert at the Top of the Stack
bool push(Stack *S, studType student);

//delete at the Top of the Stack
bool pop(Stack *S);

// return the top of the Stack if no item in the stack return dummy//
studType popReturn(Stack *S);

// display the top of the Stack //
void top(Stack S);

// display the entire Stack 
void display(Stack S);

int main(){
    Stack S;
    initList(&S);

    studType s1 = {{"John", "Doe", 'A'}, 101, "BSCS"};
    studType s2 = {{"Jane", "Smith", 'B'}, 102, "BSIT"};
    studType s3 = {{"Alice", "Brown", 'C'}, 103, "BSCE"};

    printf("Pushing students...\n");
    push(&S, s1);
    push(&S, s2);
    push(&S, s3);

    printf("\nDisplaying stack:\n");
    display(S);

    printf("\nTop element:\n");
    top(S);

    printf("\nPop one element...\n");
    pop(&S);
    display(S);

    printf("\nPop and return:\n");
    studType popped = popReturn(&S);
    printf("Popped -> %s %c %s, id: %d, course: %s\n",
           popped.studName.FName,
           popped.studName.MI,
           popped.studName.LName,
           popped.id,
           popped.course);

    printf("\nFinal stack:\n");
    display(S);

    return 0;
}


void initList(Stack *S){
    S->top = -1;
}

bool push(Stack *S, studType student){
    bool flag = false;
    if(S->top != MAX - 1){
        S->top++;
        S->studRec[S->top] = student;
        flag = true;
    }else{
        printf("The Stack is Full!.\n");
    }
    return flag;
}

bool pop(Stack *S){
    bool flag = false;
    if(S->top != -1){
        S->top--;
        flag = true;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }

    return flag;
}

studType popReturn(Stack *S){
    studType dummy = {{"XXXXX", "XXXXX", 'X'}, -1, "XXXXX"};
    
    if(S->top != -1){
        dummy.studName = S->studRec[S->top].studName;
        strcpy(dummy.course, S->studRec[S->top].course);
        dummy.id = S->studRec[S->top].id;
        S->top--;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return dummy;
}

void top(Stack S){
    if(S.top != -1){
        printf("Name: %s %c %s, id: %d, course: %s"
            ,S.studRec[S.top].studName.FName
            ,S.studRec[S.top].studName.MI
            ,S.studRec[S.top].studName.LName
            ,S.studRec[S.top].id
            ,S.studRec[S.top].course
        );
    }else{
        printf("The Stack is empty!.\n");
    }
}

void display(Stack S){
    Stack temp;
    initList(&temp);

    if(S.top != -1){
        while(S.top != -1){
            studType stud = popReturn(&S);
            push(&temp, stud);
            
            printf("Name: %s %c %s, id: %d, course: %s\n"
                ,stud.studName.FName
                ,stud.studName.MI
                ,stud.studName.LName
                ,stud.id
                ,stud.course
            );
        }

        while(temp.top != -1){
            push(&S, popReturn(&temp));
        }

    }else{
        printf("Stack is empty");
    }
}