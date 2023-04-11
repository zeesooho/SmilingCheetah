#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <stdio.h>

typedef int element;

typedef struct Queue{
    element *data;
    int capacity;
    int front;
    int rear;
}Queue;

Queue* create_queue(int capacity);
int queue_is_full(Queue* queue);
int queue_is_empty(Queue* queue);
void enqueue(Queue* queue, element e);
element dequeue(Queue* queue);
element queue_peek(Queue* queue);

#endif