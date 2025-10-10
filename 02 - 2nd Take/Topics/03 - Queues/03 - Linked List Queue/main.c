#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure for linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define Queue structure
typedef struct {
    Node *front;  // Points to the front node
    Node *rear;   // Points to the last node
} Queue;

// Function prototypes
void initQueue(Queue *q);
bool isEmpty(Queue *q);
Node *createNode(int value);
void Enqueue(Queue *q, int value);
void Dequeue(Queue *q);
void Peek(Queue q);
void Display(Queue q);

// Initialize the queue
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if queue is empty
bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Create a new node
Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    } else {
        printf("Memory allocation failed!\n");
    }
    return (newNode != NULL) ? newNode : NULL;
}

// Enqueue (Insert) operation
void Enqueue(Queue *q, int value) {
    Node *newNode = createNode(value);
    // If queue is empty, both front and rear are the same
    if (newNode != NULL) {
        if (isEmpty(q)) {
            q->front = q->rear = newNode; // First element
        } else {
            q->rear->next = newNode; // Link new node after rear
            q->rear = newNode;       // Move rear pointer
        }
        printf("Enqueued: %d\n", value);
    } else {
        printf("Enqueue failed!\n");
    } 
}

// Dequeue (Remove) operation
void Dequeue(Queue *q) {
    if (!isEmpty(q)) {
        Node *temp = q->front;        // Store front node
        printf("Dequeued: %d\n", temp->data);
        q->front = q->front->next;    // Move front to next node
        free(temp);                   // Free removed node
        if (q->front == NULL) q->rear = NULL; // If queue is now empty
    } else {
        printf("Queue is EMPTY! Dequeue failed.\n");
    }
}

// Peek (View front element)
void Peek(Queue q) {
    if (!isEmpty(&q)) {
        printf("Front element: %d\n", q.front->data);
    } else {
        printf("Queue is EMPTY! Nothing to peek.\n");
    }
}

// Display all elements
void Display(Queue q) {
    if (!isEmpty(&q)) {
        printf("Queue elements: ");
        Node *current = q.front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
        // call peek
        Peek(q);
    } else {
        printf("Queue is EMPTY! Nothing to display.\n");
    }
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Display(q);

    Dequeue(&q);
    Display(q);

    Enqueue(&q, 40);
    Enqueue(&q, 50);
    Display(q);

    Peek(q);

    Dequeue(&q);
    Dequeue(&q);
    Dequeue(&q);
    Display(q);

    return 0;
}
