#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void Enqueue(Queue *q, int value);
void Dequeue(Queue *q);
void Peek(Queue q);
void Display(Queue q);

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;  // Front starts at index 0
    q->rear = 0;   // Rear also starts at index 0 (not -1)
}

// Check if queue is full
bool isFull(Queue *q) {
    return (q->rear == MAX); // Full when rear reaches MAX
}

// Check if queue is empty
bool isEmpty(Queue *q) {
    return (q->front == q->rear); // Empty when front and rear are equal
}

// Enqueue (Insert)
void Enqueue(Queue *q, int value) {
    if(!isFull(q)) { // If not full
        q->items[q->rear] = value; // Insert at rear
        q->rear++; // Move rear forward
        printf("Enqueued: %d\n", value);
    } else {
        printf("Queue is Full!, enqueue failed\n");
    }
}

// Dequeue (Remove)
void Dequeue(Queue *q) {
    if(!isEmpty(q)) { // If not empty
        int removed = q->items[q->front]; // Take front element
        q->front++; // Move front forward
        printf("Dequeued: %d\n", removed);
    } else {
        printf("Queue is Empty!, dequeue failed\n");
    }
}

// Peek (View front element)
void Peek(Queue q) {
    if(!isEmpty(&q)) { // If not empty
        printf("Front element: %d\n", q.items[q.front]);
    } else {
        printf("Queue is Empty!, nothing to see here\n");
    }
}

// Display all elements
void Display(Queue q) {
    if(!isEmpty(&q)) { // If not empty
        printf("Queue elements: ");
        for(int i = q.front; i < q.rear; i++) {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    } else {
        printf("Queue is Empty!, nothing to see here\n");
    }
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);  // Queue full after this
    Display(q);

    Dequeue(&q);
    Dequeue(&q);
    Display(q);

    // These will fail since linear queue doesn’t reuse freed space
    Enqueue(&q, 60);
    Enqueue(&q, 70);
    Display(q);

    Peek(q);

    return 0;
}
