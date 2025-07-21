#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int **arr;
    int front;
    int rear;
    int size;
}Queue;
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;

}
int isFull(Queue *queue) {
    if (queue->rear == queue->size - 1) {
        return 1;
    }
    return 0;
}
int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}
void enQueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;

}
void deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    queue->rear--;

}