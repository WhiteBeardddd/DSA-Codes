#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack* S, char x);
void Pop(Stack* S);
char Top(Stack S);
void initStack(Stack* S);

bool isFull(Stack S);
bool isEmpty(Stack S);

// your task is this function!
bool isPalindrome(char palindrome[]);


int main(){
    char palindrome[MAX];
    printf("Enter string: ");
    scanf("%s", palindrome);

    printf("Palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No!");
}

bool isPalindrome(char palindrome[]){
 // implement here!!
    Stack temp, temp1, reverseStack;
    initStack(&temp);
    initStack(&temp1);
    initStack(&reverseStack);
    bool yes;

    for(int i = 0; palindrome[i] != '\0'; i++){
        Push(&temp, palindrome[i]);
        Push(&temp1, palindrome[i]);
    }

    while(temp.top != -1){
        char x = Top(temp);
        Pop(&temp);
        Push(&reverseStack, x);
    }

    while(!isEmpty(temp1) && !isEmpty(reverseStack)){
        char left = Top(temp1);
        char right = Top(reverseStack);
        if(left == right){
            Pop(&temp1);
            Pop(&reverseStack);
            yes = true;
        }else{
            return false;
        }

    }

    return yes;
}

void Push(Stack* S, char x){
    if(isFull(*S) != true){
        S->elem[++S->top] = x;
    }

}

void Pop(Stack* S){
    if(isEmpty(*S) != true){
        S->top--;
    }
}

char Top(Stack S){
    return (isEmpty(S) != true) ? S.elem[S.top] : '\0';
}

void initStack(Stack* S){
    S->top = -1;
}

bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}
bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}

