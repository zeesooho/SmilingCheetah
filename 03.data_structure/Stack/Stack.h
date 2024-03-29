#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>

typedef int element;

typedef struct Stack{
    element *data;
    int capacity;
    int top;
}Stack;

Stack* create_stack(int capacity);
int stack_is_full(Stack* stack);
int stack_is_empty(Stack* stack);
int stack_is_not_empty(Stack* stack);
void push(Stack* stack, element e);
element peek(Stack* stack);
element pop(Stack* stack);

#endif