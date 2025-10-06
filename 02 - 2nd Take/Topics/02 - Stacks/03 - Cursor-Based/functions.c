#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10   // Maximum number of nodes in cursor space
#define NIL -1   // Indicates null / no link

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

// Node structure (for cursor-based linked list)
typedef struct {
    studType studRec;   // Student record
    int link;           // Link to next node (index in array)
} nodeType;

// Cursor space structure (simulates dynamic memory)
typedef struct {
    nodeType nodes[MAX];  // Array of nodes
    int avail;            // Index of first available (free) node
} VirtualHeap;

// Stack structure
typedef int Stack;        // Stack is represented by an index (top node index)


/* ===================== FUNCTION PROTOTYPES ===================== */

// MEMORY MANAGEMENT
void initHeap(VirtualHeap *VH);           // Initialize virtual heap
int allocSpace(VirtualHeap *VH);          // Allocate one node (returns index)
void deallocSpace(VirtualHeap *VH, int idx); // Deallocate a node (free it)

// STACK OPERATIONS
void initList(Stack *S);                  // Initialize the stack
bool isEmpty(Stack S);                    // Check if stack is empty
bool isFull(VirtualHeap VH);              // Check if virtual heap is full
void makeNull(Stack *S, VirtualHeap *VH); // Reset stack (delete all nodes)

studType createStudent(nameType Name, int id, char course[]); // Create and return new student

bool push(Stack *S, VirtualHeap *VH, studType student);       // Push student onto stack
bool pop(Stack *S, VirtualHeap *VH);                          // Pop top student
studType popReturn(Stack *S, VirtualHeap *VH);                // Pop & return top student
void top(Stack S, VirtualHeap VH);                            // Print top student

// DISPLAY FUNCTIONS
void display1(Stack S, VirtualHeap VH);   // Top → Bottom (copy & pop)
void display2(Stack S, VirtualHeap VH);   // Bottom → Top (recursive)
void display3(Stack S, VirtualHeap VH);   // Bottom → Top (array traversal)
void display4(Stack S, VirtualHeap VH);   // Top → Bottom (array traversal)


/* ===================== MEMORY MANAGEMENT ===================== */

// Initialize virtual heap (link all nodes into a free list)
void initHeap(VirtualHeap *VH){
    for(int i = 0; i < MAX - 1; i++){
        VH->nodes[i].link = i + 1;  // Point each node to the next
    }
    VH->nodes[MAX - 1].link = NIL;  // Last node points to NIL
    VH->avail = 0;                  // Start of free list
}

// Allocate space (simulate malloc)
int allocSpace(VirtualHeap *VH){
    int idx = VH->avail;
    if(idx != NIL){
        VH->avail = VH->nodes[idx].link;  // Move avail to next free
    }
    return idx;
}

// Deallocate space (simulate free)
void deallocSpace(VirtualHeap *VH, int idx){
    if(idx != NIL){
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}


/* ===================== STACK FUNCTIONS ===================== */

// Initialize stack (set top = NIL)
void initList(Stack *S){
    *S = NIL;
}

// Return true if stack is empty
bool isEmpty(Stack S){
    return (S == NIL) ? true : false;
}

// Return true if heap has no available nodes
bool isFull(VirtualHeap VH){
    return (VH.avail == NIL) ? true : false;
}

// Delete all nodes in stack (reset to empty)
void makeNull(Stack *S, VirtualHeap *VH){
    int temp;
    while(*S != NIL){
        temp = *S;
        *S = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}


/* ===================== MAIN STACK OPERATIONS ===================== */

// Push (insert) student into stack
bool push(Stack *S, VirtualHeap *VH, studType student){
    bool flag = false;
    int newNode = allocSpace(VH);

    if(newNode != NIL){
        VH->nodes[newNode].studRec = student;
        VH->nodes[newNode].link = *S;   // New node points to current top
        *S = newNode;                   // New node becomes new top
        flag = true;
    }else{
        printf("The Stack is Full!.\n");
    }
    return flag;
}

// Pop (remove) top element
bool pop(Stack *S, VirtualHeap *VH){
    bool flag = false;
    if(!isEmpty(*S)){
        int temp = *S;
        *S = VH->nodes[temp].link;
        deallocSpace(VH, temp);
        flag = true;
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return flag;
}

// Pop and return top element (dummy if empty)
studType popReturn(Stack *S, VirtualHeap *VH){
    studType dummy = {{"XXXXX","XXXXX",'X'}, -1, "XXXXX"};

    if(!isEmpty(*S)){
        int temp = *S;
        dummy = VH->nodes[temp].studRec;
        *S = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }else{
        printf("Nothing to delete!, Stack is Empty\n");
    }
    return dummy;
}

// Print top element (peek)
void top(Stack S, VirtualHeap VH){
    if(!isEmpty(S)){
        printf("Name: %s %c %s, id: %d, course: %s\n",
            VH.nodes[S].studRec.studName.FName,
            VH.nodes[S].studRec.studName.MI,
            VH.nodes[S].studRec.studName.LName,
            VH.nodes[S].studRec.id,
            VH.nodes[S].studRec.course);
    }else{
        printf("The Stack is empty!.\n");
    }
}


/* ===================== DISPLAY FUNCTIONS ===================== */

// Display (Top → Bottom) by repeatedly popping (copy stack)
void display1(Stack S, VirtualHeap VH){
    if(!isEmpty(S)){
        while(!isEmpty(S)){
            top(S, VH);
            S = VH.nodes[S].link;
        }
    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Bottom → Top) using recursion
void display2Helper(Stack S, VirtualHeap VH){
    if(S == NIL) return;
    display2Helper(VH.nodes[S].link, VH);
    printf("Name: %s %c %s, id: %d, course: %s\n",
        VH.nodes[S].studRec.studName.FName,
        VH.nodes[S].studRec.studName.MI,
        VH.nodes[S].studRec.studName.LName,
        VH.nodes[S].studRec.id,
        VH.nodes[S].studRec.course);
}
void display2(Stack S, VirtualHeap VH){
    if(!isEmpty(S)){
        display2Helper(S, VH);
    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Bottom → Top) by traversal
void display3(Stack S, VirtualHeap VH){
    if(!isEmpty(S)){
        int arr[MAX];
        int count = 0;

        for(int curr = S; curr != NIL; curr = VH.nodes[curr].link){
            arr[count++] = curr;
        }

        for(int i = count - 1; i >= 0; i--){
            printf("Name: %s %c %s, id: %d, course: %s\n",
                VH.nodes[arr[i]].studRec.studName.FName,
                VH.nodes[arr[i]].studRec.studName.MI,
                VH.nodes[arr[i]].studRec.studName.LName,
                VH.nodes[arr[i]].studRec.id,
                VH.nodes[arr[i]].studRec.course);
        }

    }else{
        printf("The Stack is empty!.\n");
    }
}

// Display (Top → Bottom) by traversal
void display4(Stack S, VirtualHeap VH){
    if(!isEmpty(S)){
        for(int curr = S; curr != NIL; curr = VH.nodes[curr].link){
            printf("Name: %s %c %s, id: %d, course: %s\n",
                VH.nodes[curr].studRec.studName.FName,
                VH.nodes[curr].studRec.studName.MI,
                VH.nodes[curr].studRec.studName.LName,
                VH.nodes[curr].studRec.id,
                VH.nodes[curr].studRec.course);
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


