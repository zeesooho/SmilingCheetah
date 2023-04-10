#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./SinglyLinkedList/SinglyLinkedList.h"

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

int main(int argc, char* argv[]){
    srand(time(NULL));

    // Hw1
    SinglyLinkedList* list = create_singly_linked_list();

    for(int i=0; i<100; i++)
        insert_front(list, rand()%100);

    print_elements(list);
    printf("\n");
    removeDuplicate(list);
    print_elements(list);

    int element_size = 100;
    int rand_range = 100;

    if(argc > 1)
        element_size = atoi(argv[1]);

    return 0;
}