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
    return ((q->rear + 1) % MAX == q->front);
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Enqueue (Insert) operation
void Enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
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

    if (q->front == q->rear) {
        // Queue becomes empty after this dequeue
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
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
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
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
    Display(&q);

    Dequeue(&q);
    Dequeue(&q);
    Display(&q);

    Enqueue(&q, 60);  // Reuses freed space (wraps around)
    Enqueue(&q, 70);
    Display(&q);

    Peek(&q);

    return 0;
}
    