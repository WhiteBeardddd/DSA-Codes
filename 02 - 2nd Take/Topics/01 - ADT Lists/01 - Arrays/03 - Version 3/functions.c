#define MAX 10 

// VERSION 1 //
// all in stack //
typedef struct { 
    char data; 
    int link; 
}NodeType; 

typedef struct { 
    NodeType Elements[MAX]; 
    int Avail; 
}VirtualHeap; 

typedef int CurList;

#define MAX 10 

// VERSION 2 //
typedef struct { 
    char data; 
    int link; 
}NodeType; 


// inside HEap
typedef struct { 
    NodeType Elements[MAX]; 
    int Avail; 
}*VirtualHeap; 

typedef int CurList;