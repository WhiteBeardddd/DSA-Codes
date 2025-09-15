#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef struct {
    char elem[MAX];
    int top; //index of stack top
} Stack;

/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
char top(Stack s);
void pop(Stack *s);
void push(Stack *s, char data);

/*************************************/
/*            YOUR TASK              */
/*************************************/
bool isValidParentheses (char parentheses[]);
bool isLeftBracket (char x);
bool isRightBracket (char x, Stack S);

int main() {
    char parentheses[256];

    printf("Enter parentheses: ");
    scanf("%s", parentheses);

    printf("The parentheses is %s.", 
        (isValidParentheses(parentheses)) ? "VALID" : "NOT VALID");

    return 0;
}

bool isValidParentheses (char parentheses[]) {
    Stack temp;
    init(&temp);

    for(int i = 0; parentheses[i] != '\0'; i++){
        if(isLeftBracket(parentheses[i])){
            push(&temp, parentheses[i]);
        }else if(isRightBracket(parentheses[i], temp)){
            if(!isEmpty(temp)){
                pop(&temp);
            }
        }
    }

    return isEmpty(temp);
}

bool isLeftBracket (char x){
    return (x == '{' || x == '[' || x == '(' );
}

bool isRightBracket (char x, Stack S){
    return ((x == '}' && top(S) == '{')  || (x == ')' && top(S) == '(')  ||(x == ']' && top(S) == '['));
}

/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1) ? true : false; 
}

bool isFull(Stack s) {
    return (s.top == MAX - 1) ? true : false;
}

char top(Stack s) {
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

void push(Stack *s, char data) {
    if(!isFull(*s)) {
        s->top++;
        s->elem[s->top] = data; 
    }
}