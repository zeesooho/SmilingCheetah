#include "SinglyLinkedList.h"
#include "../util/error.h"

static ListNode* create_node(element e){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->e = e;
    node->link = NULL;
    return node;
}

SinglyLinkedList* create_singly_linked_list(){
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int insert_front(SinglyLinkedList* list, element e){
    insert(list, e, 0);
}

int insert_back(SinglyLinkedList* list, element e){
    insert(list, e, list->size - 1);
}

int insert(SinglyLinkedList* list, element e, int pos){
    if(pos > list->size || pos < 0) error("out of bounds");
    if(pos == 0){
        ListNode* newNode = create_node(e);
        newNode->link = list->head;
        list->head = newNode;
        list->size += 1;
        return 1;
    }
    ListNode* curr = list->head;
    ListNode* prev = NULL;
    for(int i=0; i<pos; i++){
        prev = curr;
        curr = curr->link;
    }
    ListNode* newNode = create_node(e);
    prev->link = newNode;
    newNode->link = curr;
    list->size += 1;
    return 1;
}

element get(SinglyLinkedList* list, int pos){
    if(pos >= list->size) return -1;
    ListNode* curr = list->head;
    for(int i=0; i<pos; i++){
        curr = curr->link;
    }
    return curr->e;
}

int remove_at(SinglyLinkedList* list, int pos){
    if(pos >= list->size || pos < 0) error("out of bounds");
    if(pos == 0){
        ListNode* temp = list->head;
        list->head = temp->link;
        free(temp);
        list->size -= 1;
        return 1;
    }
    ListNode* curr = list->head;
    ListNode* prev = NULL;
    for(int i=0; i<pos; i++){
        prev = curr;
        curr = curr->link;
    }
    prev->link = curr->link;
    free(curr);
    list->size -= 1;
    return 1;
}