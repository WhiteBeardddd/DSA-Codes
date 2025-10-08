#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void Enqueue(Queue *q, int value);
void Dequeue(Queue *q);
void Peek(Queue *q);
void Display(Queue *q);

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue (Insert) operation
void Enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot enqueue %d.\n", value);
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Dequeue (Remove) operation
void Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", q->items[q->front]);
    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1; // Reset when queue becomes empty
}

// Peek (View front element)
void Peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! No elements to peek.\n");
        return;
    }

    printf("Front element is: %d\n", q->items[q->front]);
}

// Display all elements
void Display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Display(&q);
    Peek(&q);

    Dequeue(&q);
    Display(&q);
    Peek(&q);

    return 0;
}
