#include <stdio.h>
#include <stdlib.h>
#include "./SinglyLinkedList/SinglyLinkedList.h"

int main(){
    SinglyLinkedList* list = create_singly_linked_list();
    for(int i=0; i<10; i++){
        insert_front(list, i);
        print_elements(list);
    }

    for(int i=9; i>=0; i--){
        insert_back(list, i);
        print_elements(list);
    }
    
    while(list->size){
        remove_at(list, list->size-1);
        print_elements(list);
    }
    return 0;
}