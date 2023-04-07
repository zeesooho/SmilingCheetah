#include "./SinglyLinkedList/SinglyLinkedList.h"

int main(int argc, char **argv){
    SinglyLinkedList* list = create_singly_linked_list();
    insert(list, 1, 0);
    printf("%d", list->head->e);
    return 0;
}