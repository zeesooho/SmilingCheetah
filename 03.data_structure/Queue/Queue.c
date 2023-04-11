#include "Queue.h"
#include "../util/error.h"
#include <malloc.h>

Queue* create_queue(int capacity){
    return (Queue*)malloc(sizeof(Queue));
}
int queue_is_full(Queue* queue){
    return 1;
}
int queue_is_empty(Queue* queue){
    return 1;
}
void enqueue(Queue* queue, element e){
    
}
element dequeue(Queue* queue){
    return 1;
}
element queue_peek(Queue* queue){
    return 1;
}