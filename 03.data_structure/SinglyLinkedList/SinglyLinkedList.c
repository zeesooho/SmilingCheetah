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

void insert_front(SinglyLinkedList* list, element e){
    insert(list, e, 0);
}

void insert_back(SinglyLinkedList* list, element e){
    insert(list, e, list->size-1);
}

void insert(SinglyLinkedList* list, element e, int pos){
    if(e < 0) error("Illegal element");
    if(pos > list->size || pos < 0) error("Out of bounds");
    if(pos == 0){
        ListNode* newNode = create_node(e);
        newNode->link = list->head;
        list->head = newNode;
        list->size += 1;
        return;
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
    return;
}

element get(SinglyLinkedList* list, int pos){
    if(pos >= list->size) error("Out of bounds");
    ListNode* curr = list->head;
    for(int i=0; i<pos; i++){
        curr = curr->link;
        if(curr == NULL) error("Out of bounds");
    }
    return curr->e;
}

void remove_at(SinglyLinkedList* list, int pos){
    if(pos >= list->size || pos < 0) error("Out of bounds");
    if(pos == 0){
        ListNode* temp = list->head;
        list->head = temp->link;
        free(temp);
        list->size -= 1;
        return;
    }
    ListNode* curr = list->head;
    ListNode* prev = NULL;
    for(int i=0; i<pos; i++){
        prev = curr;
        curr = curr->link;
        if(curr == NULL) error("Out of bounds");
    }
    prev->link = curr->link;
    free(curr);
    list->size -= 1;
    return;
}

void print_elements(SinglyLinkedList* list){
    for(int i=0; i<=list->size; i++){
        if(get(list, i) >= 0)
            printf("%d -> ", get(list, i));
        else
            printf("NULL\n");
    }
}