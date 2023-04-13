#include "Queue.h"
#include "../util/error.h"
#include <malloc.h>

Queue* create_queue(int capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->data = (element*)malloc(capacity*sizeof(element)+1);
    return queue;
}
int queue_is_full(Queue* queue){
    return ((queue->rear+1)%(queue->capacity+1) == queue->front)? 1 : 0;
}
int queue_is_empty(Queue* queue){
    return (queue->rear == queue->front)? 1 : 0;
}
int queue_is_not_empty(Queue* queue){
    return queue_is_empty(queue)? 0 : 1;
}
void enqueue(Queue* queue, element e){
    if(queue_is_full(queue)){
        queue->capacity *= 2;
        realloc(queue->data, queue->capacity*sizeof(element)+1);
    }
    queue->data[queue->rear%(queue->capacity+1)] = e;
    queue->rear = (queue->rear+1)%(queue->capacity+1);
}
element dequeue(Queue* queue){
    if(queue_is_empty(queue)) error("Out of bounds - dequeue");
    element e = queue->data[queue->front];
    queue->front = (queue->front+1)%(queue->capacity+1);
    return e;
}
element queue_peek(Queue* queue){
    if(queue_is_empty(queue)) error("Out of bounds - queue_peek");
    return queue->data[queue->front%(queue->capacity+1)];
}