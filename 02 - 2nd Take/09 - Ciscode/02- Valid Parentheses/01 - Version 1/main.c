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
bool isFirstValid(char parentheses[]);
bool isSameBracket(char fb, char lb);
bool isValidIndex(char x);
bool isOpen(char x);
bool isClose(char x);

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

    if(!isFirstValid(parentheses)){
        return false;
    }

    for(int i = 0; parentheses[i] != '\0'; i++){
        char x = parentheses[i];

        if(isOpen(x)){
            push(&temp, x);
        } 
        else if(isClose(x)){
            if(isEmpty(temp)){
                return false; 
            }
            char open = top(temp);
            pop(&temp);

            if(!isSameBracket(open, x)){
                return false; 
            }
        }
    }

    return isEmpty(temp);
}


bool isOpen(char x){
    return(x == '{' || x == '[' || x == '(')? true : false;
}

bool isClose(char x){
    return(x == '}' || x == ']' || x == ')')? true : false;
}

bool isFirstValid(char parentheses[]){
    return (parentheses[0] == '(' || parentheses[0] == '[' || parentheses[0] == '{'); 
}

bool isSameBracket(char fb, char lb){
    return((fb == '{' && lb == '}') || (fb == '[' && lb == ']') || (fb == '(' && lb == ')'));
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