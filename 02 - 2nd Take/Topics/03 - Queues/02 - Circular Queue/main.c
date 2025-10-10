#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5  // Actual array size (1 slot is sacrificed to detect full/empty)

// Define a queue structure
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
    q->front = 0;
    q->rear = MAX - 1;  // Start rear at the end so first Enqueue puts it at index 0
}

// Check if queue is FULL (sacrificial slot technique)
// Queue is full if next-to-next position of rear == front
bool isFull(Queue *q) {
    return ((q->rear + 2) % MAX == q->front);
}

// Check if queue is EMPTY
// Queue is empty if next position of rear == front
bool isEmpty(Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Enqueue (Insert) operation
void Enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        // Move rear forward (with wrap-around)
        q->rear = (q->rear + 1) % MAX;

        // Store the value at the new rear
        q->items[q->rear] = value;

        printf("%d enqueued successfully! (front=%d, rear=%d)\n", value, q->front, q->rear);
    } else {
        printf("Queue is Full! Enqueue failed for %d\n", value);
    }
}

// Dequeue (Remove) operation
void Dequeue(Queue *q) {
    if (!isEmpty(q)) {
        // Print and remove front element
        printf("%d dequeued successfully! (front=%d, rear=%d)\n", q->items[q->front], q->front, q->rear);

        // Move front forward (with wrap-around)
        q->front = (q->front + 1) % MAX;
    } else {
        printf("Queue is Empty! Dequeue failed\n");
    }
}

// Peek (View front element)
void Peek(Queue q) {
    if (!isEmpty(&q)) {
        printf("Front element: %d\n", q.items[q.front]);
    } else {
        printf("Queue is Empty! Nothing to see here\n");
    }
}

// Display all elements in the queue
void Display(Queue q) {
    if (!isEmpty(&q)) {
        printf("Queue elements: ");
        int i = q.front;

        // Loop until we reach rear (consider wrap-around)
        while (i != (q.rear + 1) % MAX) {
            printf("%d ", q.items[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    } else {
        printf("Queue is Empty! Nothing to display\n");
    }
}

// Main function to test the queue
int main() {
    Queue q;
    initQueue(&q);

    // Enqueue operations
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);  // Queue full after this (one slot sacrificed)
    Display(q);

    // Dequeue operations
    Dequeue(&q);
    Dequeue(&q);
    Display(q);

    // Enqueue more to test wrap-around
    Enqueue(&q, 60);
    Enqueue(&q, 70);
    Display(q);

    // Peek front
    Peek(q);

    return 0;
}
