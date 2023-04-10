#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef int element;

typedef struct ListNode{
    element e;
    struct ListNode* link;
}ListNode;

static ListNode* create_node(element e);

typedef struct SinglyLinkedList{
    int size;
    struct ListNode* head;
}SinglyLinkedList;

SinglyLinkedList* create_singly_linked_list();

void insert_front(SinglyLinkedList* list, element e);
void insert_back(SinglyLinkedList* list, element e);
void insert(SinglyLinkedList* list, element e, int pos);

element get(SinglyLinkedList* list, int pos);
element pop_front(SinglyLinkedList* list);
element pop_back(SinglyLinkedList* list);

// int remove(SinglyLinkedList* list, element e);
void remove_at(SinglyLinkedList* list, int pos);

void index_of(SinglyLinkedList* list, element e);

void print_elements(SinglyLinkedList* list);

#endif