#include "Stack.h"
#include "../util/error.h"

Stack* create_stack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->data = (element*)malloc((stack->capacity)*sizeof(element));
    stack->top = -1;
    return stack;
}

int is_full(Stack* stack){
    return (stack->top == stack->capacity-1)? 1 : 0;
}

int is_empty(Stack* stack){
    return (stack->top == -1)? 1 : 0;
}

void push(Stack* stack, element e){
    if(is_full(stack)){
        stack->capacity *= 2;
        realloc(stack->data, (stack->capacity)*sizeof(element));
    }
    stack->top += 1;
    (stack->data)[stack->top] = e;
}

element peek(Stack* stack){
    if(is_empty(stack)) error("Out of bounds");
    return (stack->data)[stack->top];
}

element pop(Stack* stack){
    if(is_empty(stack)) error("Out of bounds");
    element e = (stack->data)[stack->top];
    stack->top -= 1;
    return e;
}