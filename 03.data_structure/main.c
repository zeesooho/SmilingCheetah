#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./SinglyLinkedList/SinglyLinkedList.h"
#include "./Stack/Stack.h"
#include "./Queue/Queue.h"

void removeDuplicate(SinglyLinkedList* list){
    SinglyLinkedList* newList = create_singly_linked_list();
    int size = list->size;
    for(int i = 0; i < size; i++){
        element e = pop_front(list);
        if(index_of(newList, e)==-1)
            insert_back(newList, e);
    }
    list->head = newList->head;
    list->size = newList->size;
    free(newList);
}

void sortListWithStack(element* list, int capacity, int desc){
    // Make empty stacks
    Stack* stack1 = create_stack(capacity); // Main
    Stack* stack2 = create_stack(capacity); // Temp
    push(stack1, list[0]);
    if(desc){
        for(int i=1; i<capacity; i++){
            while(stack_is_empty(stack1)){
                if(peek(stack1) > list[i])
                    push(stack2, pop(stack1));
                else
                    break;
            }
            push(stack1, list[i]);
            while(stack_is_empty(stack2)){
                push(stack1, pop(stack2));
            }
        }
        for(int i=0; i<capacity; i++){
            list[i] = pop(stack1);
        }
    }
    else{
        for(int i=1; i<capacity; i++){
            while(stack_is_empty(stack1)){
                if(peek(stack1) < list[i])
                    push(stack2, pop(stack1));
                else
                    break;
            }
            push(stack1, list[i]);
            while(stack_is_empty(stack2)){
                push(stack1, pop(stack2));
            }
        }
        for(int i=0; i<capacity; i++){
            list[i] = pop(stack1);
        }
    }
}

void sortListWithQueue(element* list, int capacity, int desc){
    // Make empty stacks
    Queue* queue1 = create_queue(capacity); // Main
    Queue* queue2 = create_queue(capacity); // Temp
    enqueue(queue1, list[0]);
    if(desc){
        for(int i=1; i<capacity; i++){
            while(queue_is_empty(queue1)){
                if(queue_peek(queue1) > list[i])
                    enqueue(queue2, dequeue(queue1));
                else
                    break;
            }
            enqueue(queue1, list[i]);
            while(queue_is_empty(queue2)){
                enqueue(queue1, dequeue(queue2));
            }
        }
        for(int i=0; i<capacity; i++){
            list[i] = dequeue(queue1);
        }
    }
    else{
        for(int i=1; i<capacity; i++){
            while(queue_is_empty(queue1)){
                if(queue_peek(queue1) < list[i])
                    enqueue(queue2, dequeue(queue1));
                else
                    break;
            }
            enqueue(queue1, list[i]);
            while(queue_is_empty(queue2)){
                enqueue(queue1, dequeue(queue2));
            }
        }
        for(int i=0; i<capacity; i++){
            list[i] = dequeue(queue1);
        }
    }
}

void printList(element* list, int size){
    printf("[");
    for(int i=0; i<size-1; i++)
        printf("%d, ", list[i]);
    printf("%d]\n", list[size-1]);
}

int main(int argc, char* argv[]){
    srand(time(NULL));

    if(argc == 1){
        // Hw1
        SinglyLinkedList* list = create_singly_linked_list();

        for(int i=0; i<100; i++)
            insert_front(list, rand()%100);

        print_elements(list);
        printf("\n");
        removeDuplicate(list);
        print_elements(list);
    }else{
        // Hw2
        int capacity = 10;
        int is_stack = 1;

        if(argc > 1)
            capacity = atoi(argv[1]);
        
        if(argc > 2)
            if((int)argv[2][0] == 's' || (int)argv[2][0] == 'S')
                is_stack = 1;
            else if((int)argv[2][0] == 'q' || (int)argv[2][0] == 'Q')
                is_stack = 0;

        element* list = (element*)malloc(capacity*sizeof(element));
        for(int i=0; i<capacity; i++)
            list[i] = rand()%1000;
        if(is_stack){
            printList(list, capacity);
            // Stack
            // asce
            sortListWithStack(list, capacity, 0);
            printList(list, capacity);
            // desc
            sortListWithStack(list, capacity, 1);
            printList(list, capacity);
        }else{
            printList(list, capacity);
            // Queue
            // asce
            sortListWithQueue(list, capacity, 0);
            printList(list, capacity);
            // desc
            sortListWithQueue(list, capacity, 1);
            printList(list, capacity);
        }
    }
    return 0;
}