#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10   // Maximum number of students allowed in the stack

/* ===================== DATA STRUCTURES ===================== */

// Structure to hold a student's name
typedef struct {
    char FName[24];   // First name
    char LName[16];   // Last name
    char MI;          // Middle Initial
} nameType;

// Structure to represent a student record
typedef struct {
    nameType studName;   // Student's name
    int id;              // Student ID
    char course[8];      // Course code (e.g., BSIT, BSCS)
} studType;

// Stack structure that holds student records
typedef struct {
    int top;                 // Index of the top element (-1 means empty)
    studType studRec[MAX];   // Array to store student records
} Stack;


/* ===================== FUNCTION PROTOTYPES ===================== */

// HELPER FUNCTIONS
void initList(Stack *S);           // Initialize the stack
bool isEmpty(Stack S);             // Check if stack is empty
bool isFull(Stack S);              // Check if stack is full
void makeNull(Stack *S);           // Reset stack to empty

// MAIN STACK FUNCTIONS
studType createStudent(nameType Name, int id, char course[]);   // Create and return a new student
bool push(Stack *S, studType student);                         // Push student onto the stack
bool pop(Stack *S);                                            // Pop (remove) the top element
studType popReturn(Stack *S);                                  // Pop & return the top element (with dummy if empty)
void top(Stack S);                                             // Print the top element


// NEVER TRAVERSE THE STACK!
// Display variations
void display1(Stack S);   // Top → Bottom (using pop, destroys copy)
void display2(Stack S);   // Bottom → Top (uses temp stack)
void display3(Stack S);   // Bottom → Top (array traversal)
void display4(Stack S);   // Top → Bottom (array traversal)


/* ===================== FUNCTION DEFINITIONS ===================== */

// Initialize stack (set top = -1 → empty stack)
void initList(Stack *S){
    S->top = -1;
}

// Return true if stack is empty
bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}

// Return true if stack is full
bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}

// Reset stack (clear contents by setting top = -1)
void makeNull(Stack *S){
    S->top = -1;
}

// Push (insert) a student into the stack
bool push(Stack *S, studType student){
    bool flag = false;
    if(!isFull(*S)){
        S->top++;
        S->studRec[S->top] = student;  // Store student at the top
        flag = true;
    }else{
        printf("The Stack is Full!.\n");
    }
    return flag;
}

// Pop (remove) the top student from the stack
bool pop(Stack *S){
    bool flag = false;
    if(!isEmpty(*S)){
        S->top--;   // Just move the top pointer down
        flag = true;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return flag;
}

// Pop the top student and return it (returns dummy if stack is empty)
studType popReturn(Stack *S){
    studType dummy = {{"XXXXX", "XXXXX", 'X'}, -1, "XXXXX"}; // Dummy value
    
    if(!isEmpty(*S)){
        dummy.studName = S->studRec[S->top].studName;
        strcpy(dummy.course, S->studRec[S->top].course);
        dummy.id = S->studRec[S->top].id;
        S->top--;   // Remove top element
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return dummy;
}

// Print the top student (peek operation)
void top(Stack S){
    if(!isEmpty(S)){
        printf("Name: %s %c %s, id: %d, course: %s\n",
            S.studRec[S.top].studName.FName,
            S.studRec[S.top].studName.MI,
            S.studRec[S.top].studName.LName,
            S.studRec[S.top].id,
            S.studRec[S.top].course);
    }else{
        printf("The Stack is empty!.\n");
    }
}

/* ===================== DISPLAY FUNCTIONS ===================== */

// Display (Top → Bottom) by repeatedly popping (works on a copy)
void display1(Stack S){
    if(!isEmpty(S)){
        while(!isEmpty(S)){
            top(S);     // Print current top
            pop(&S);    // Remove it (affects only copy)
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Bottom → Top) using an extra stack
void display2(Stack S){
    if(!isEmpty(S)){
        Stack temp;
        initList(&temp);

        // Move elements into temp (reverses order)
        while (!isEmpty(S)){
            push(&temp , popReturn(&S));
        }

        // Print elements from temp (bottom → top)
        while (!isEmpty(temp)){
            printf("Name: %s %c %s, id: %d, course: %s\n",
                temp.studRec[temp.top].studName.FName,
                temp.studRec[temp.top].studName.MI,
                temp.studRec[temp.top].studName.LName,
                temp.studRec[temp.top].id,
                temp.studRec[temp.top].course);
            pop(&temp); // Remove after printing
        }
        
    }else{
        printf("The Stack is empty!.\n");
    }
}

// NOTE: YOU SHOULD NEVER TRAVERSE THE STACK
// MY FRIENDS USE THIS FOR TESTING SO I MADE IT AS WELL

// Display (Bottom → Top) by traversing array
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

// Display (Top → Bottom) by traversing array backwards
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

// Create and return a new student record
studType createStudent(nameType Name, int id, char course[]){
    studType newStudent;
    newStudent.studName = Name;          // Assign name
    newStudent.id = id;                  // Assign ID
    strcpy(newStudent.course, course);   // Copy course string
    return newStudent;
}
