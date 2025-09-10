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

/* HELPER FUNCTIONS */

// initialize the Stack
void initList(Stack *S);

// display the entire Stack 
void display(Stack *S);

// check if stack is empty //
bool isEmpty(Stack S);

// check if stack is full //
bool isFull(Stack S);

// restarts the stack //
void makeNull(Stack *S);

/* MAIN STACK FUNCTIONS */

//insert at the Top of the Stack
bool push(Stack *S, studType student);

//delete at the Top of the Stack
bool pop(Stack *S);

// return the top of the Stack if no item in the stack return dummy//
studType popReturn(Stack *S);

// display the top of the Stack //
void top(Stack S);

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
    display(&S);

    printf("\nTop element:\n");
    top(S);

    printf("\nPop one element...\n");
    pop(&S);
    display(&S);

    printf("\nPop and return:\n");
    studType popped = popReturn(&S);
    printf("Popped -> %s %c %s, id: %d, course: %s\n",
           popped.studName.FName,
           popped.studName.MI,
           popped.studName.LName,
           popped.id,
           popped.course);

    printf("\nFinal stack:\n");
    display(&S);

    return 0;
}


void initList(Stack *S){
    S->top = -1;
}

bool isEmpty(Stack S){
    return(S.top == -1)? true : false;
}

bool isFull(Stack S){
    return(S.top == MAX - 1)? true : false;
}

void makeNull(Stack *S){
    S->top = -1;
}

bool push(Stack *S, studType student){
    bool flag = false;
    if(!isFull(*S)){
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
    if(!isEmpty(*S)){
        S->top--;
        flag = true;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }

    return flag;
}

studType popReturn(Stack *S){
    studType dummy = {{"XXXXX", "XXXXX", 'X'}, -1, "XXXXX"};
    
    if(!isEmpty(*S)){
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
    if(!isEmpty(S)){
        printf("Name: %s %c %s, id: %d, course: %s\n"
            ,S.studRec[S.top].studName.FName
            ,S.studRec[S.top].studName.MI
            ,S.studRec[S.top].studName.LName
            ,S.studRec[S.top].id
            ,S.studRec[S.top].course);
    }else{
        printf("The Stack is empty!.\n");
    }
}

// * display top to bottom * //
void display1(Stack S){
    if(!isEmpty(S)){
        while(!isEmpty(S)){
            top(S);
            pop(&S);
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

// * display bottom to top * //
void display2(Stack S){
    if(!isEmpty(S)){
        Stack temp;
        initList(&temp);

        while (!isEmpty(S))
        {
            push(&temp , popReturn(&S));
        }

        while (!isEmpty(temp))
        {
            printf("Name: %s %c %s, id: %d, course: %s\n"
            ,temp.studRec[temp.top].studName.FName
            ,temp.studRec[temp.top].studName.MI
            ,temp.studRec[temp.top].studName.LName
            ,temp.studRec[temp.top].id
            ,temp.studRec[temp.top].course);
            pop(&temp);
        }
        

    }else{
        printf("The Stack is empty!.\n");
    }
}

// * display using traversal (bottom to top) * //
void display3(Stack S){
    if(!isEmpty(S)){
        for(int i = 0; i <= S.top; i++){   
            printf("Name: %s %c %s, id: %d, course: %s\n",
                S.studRec[i].studName.FName,
                S.studRec[i].studName.MI,
                S.studRec[i].studName.LName,
                S.studRec[i].id,
                S.studRec[i].course
            );
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

// * display using traversal (top to bottom) * //
void display4(Stack S){
    if(!isEmpty(S)){
        for(int i = S.top; i > -1; i--){   
            printf("Name: %s %c %s, id: %d, course: %s\n",
                S.studRec[i].studName.FName,
                S.studRec[i].studName.MI,
                S.studRec[i].studName.LName,
                S.studRec[i].id,
                S.studRec[i].course
            );
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}
