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
    Stack temp;
    initStack(&temp);

    for(int i = 0; palindrome[i] != '\0'; i++){
        Push(&temp, palindrome[i]);
    }
<<<<<<<< HEAD:02 - 2nd Take/Practice/09 - Ciscode/03 - Palindrome Checker (Stack)/main.c
    
========

    for(int i = 0; !isEmpty(temp); i++){
        if(Top(temp) != palindrome[i]){
            return false;
        }else{
            Pop(&temp);
        }
    }

    return isEmpty(temp);
>>>>>>>> 4ca49b5708a2a774bcdf5ff9f1277e17e29dfd66:02 - 2nd Take/09 - Ciscode/03 - Palindrome Checker (Stack)/01 - Version 2/main.c
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

