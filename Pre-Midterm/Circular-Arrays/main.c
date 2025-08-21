#include <stdio.h>

#define MAX 8

typedef struct {
    char elem[MAX];
    int rear;
    int front;
}Queue;

void initQueue(Queue *Q){
    Q->rear = MAX - 1;
    Q->front = 0;
}

void enQueue(Queue *Q, char elem){
    if(Q->rear + 2 % MAX != Q->front){
        Q->elem[Q->rear] = elem;
    }
}

void deQueue(Queue *Q){
    if(Q->rear + 1 % MAX != Q->front){
        Q->front--;
    }
}