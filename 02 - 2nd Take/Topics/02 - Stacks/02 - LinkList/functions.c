#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// Node structure (used to build the linked list stack)
typedef struct node {
    studType studRec;        // Student data
    struct node *link;       // Pointer to next node
} *Stack;


/* ===================== FUNCTION PROTOTYPES ===================== */

// HELPER FUNCTIONS
Stack initList(Stack *S);           // Initialize the stack
bool isEmpty(Stack S);              // Check if stack is empty
bool isFull(Stack S);               // Always false for linked list
void makeNull(Stack *S);            // Reset stack (delete all nodes)

// MAIN STACK FUNCTIONS
studType createStudent(nameType Name, int id, char course[]);  // Create and return a new student
bool push(Stack *S, studType student);                        // Push student onto the stack
bool pop(Stack *S);                                           // Pop (remove) the top element
studType popReturn(Stack *S);                                 // Pop & return top element (dummy if empty)
void top(Stack S);                                            // Print the top element

// DISPLAY FUNCTIONS
void display1(Stack S);   // Top → Bottom (pop style, uses copy)
void display2(Stack S);   // Bottom → Top (uses recursion)
void display3(Stack S);   // Bottom → Top (traverse)
void display4(Stack S);   // Top → Bottom (traverse)


/* ===================== FUNCTION DEFINITIONS ===================== */

// Initialize stack (set pointer to NULL)
Stack initList(Stack *S){
    *S = NULL;
    return *S;
}

// Return true if stack is empty
bool isEmpty(Stack S){
    return (S == NULL) ? true : false;
}

// Return false (linked list stacks don't have a size limit)
bool isFull(Stack S){
    return false;   // Dynamic allocation, limited only by memory
}

// Delete all nodes (reset stack)
void makeNull(Stack *S){
    Stack temp;
    while(*S != NULL){
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

/* ===================== MAIN STACK FUNCTIONS ===================== */

// Push (insert) a new student on top of stack
bool push(Stack *S, studType student){
    bool flag = false;
    Stack newNode = (Stack)malloc(sizeof(struct node));

    if(newNode != NULL){
        newNode->studRec = student;
        newNode->link = *S;   // New node points to current top
        *S = newNode;         // New node becomes new top
        flag = true;
    } else {
        printf("Memory allocation failed!\n");
    }
    return flag;
}

// Pop (remove top student from stack)
bool pop(Stack *S){
    bool flag = false;
    if(!isEmpty(*S)){
        Stack temp = *S;
        *S = (*S)->link;
        free(temp);
        flag = true;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return flag;
}

// Pop & return the top student (returns dummy if empty)
studType popReturn(Stack *S){
    studType dummy = {{"XXXXX","XXXXX",'X'}, -1, "XXXXX"};
    if(!isEmpty(*S)){
        Stack temp = *S;
        dummy = temp->studRec;
        *S = (*S)->link;
        free(temp);
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return dummy;
}

// Print the top student (peek)
void top(Stack S){
    if(!isEmpty(S)){
        printf("Name: %s %c %s, id: %d, course: %s\n",
            S->studRec.studName.FName,
            S->studRec.studName.MI,
            S->studRec.studName.LName,
            S->studRec.id,
            S->studRec.course);
    }else{
        printf("The Stack is empty!.\n");
    }
}

/* ===================== DISPLAY FUNCTIONS ===================== */

// Display (Top → Bottom) by popping elements (uses a copy)
void display1(Stack S){
    if(!isEmpty(S)){
        Stack copy = NULL;
        // Copy stack nodes to a temp linked list
        for(Stack curr = S; curr != NULL; curr = curr->link){
            push(&copy, curr->studRec);
        }

        while(!isEmpty(copy)){
            top(copy);
            pop(&copy);
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Bottom → Top) using recursion
void display2(Stack S){
    if(isEmpty(S)){
        return;
    }
    display2(S->link);
    printf("Name: %s %c %s, id: %d, course: %s\n",
        S->studRec.studName.FName,
        S->studRec.studName.MI,
        S->studRec.studName.LName,
        S->studRec.id,
        S->studRec.course);
}

// Display (Bottom → Top) by traversing and using an array of pointers
void display3(Stack S){
    if(!isEmpty(S)){
        // Count nodes
        int count = 0;
        for(Stack curr = S; curr != NULL; curr = curr->link)
            count++;

        // Store pointers for reverse access
        Stack arr[count];
        Stack curr = S;
        for(int i = 0; i < count; i++){
            arr[i] = curr;
            curr = curr->link;
        }

        // Print from bottom → top
        for(int i = count - 1; i >= 0; i--){
            printf("Name: %s %c %s, id: %d, course: %s\n",
                arr[i]->studRec.studName.FName,
                arr[i]->studRec.studName.MI,
                arr[i]->studRec.studName.LName,
                arr[i]->studRec.id,
                arr[i]->studRec.course);
        }

    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Top → Bottom) by traversing the linked list
void display4(Stack S){
    if(!isEmpty(S)){
        for(Stack curr = S; curr != NULL; curr = curr->link){
            printf("Name: %s %c %s, id: %d, course: %s\n",
                curr->studRec.studName.FName,
                curr->studRec.studName.MI,
                curr->studRec.studName.LName,
                curr->studRec.id,
                curr->studRec.course);
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

/* ===================== STUDENT CREATION FUNCTION ===================== */

// Create and return a new student record
studType createStudent(nameType Name, int id, char course[]){
    studType newStudent;
    newStudent.studName = Name;          // Assign name
    newStudent.id = id;                  // Assign ID
    strcpy(newStudent.course, course);   // Copy course string
    return newStudent;
}
