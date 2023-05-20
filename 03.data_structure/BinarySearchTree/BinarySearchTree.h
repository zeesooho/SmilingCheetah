#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char birth[8];
    char name;
    int grade;
} Student;

Student *createStudent(char *birth, char name, int grade);

typedef struct{
    Student *element;
    struct BinarySearchTreeNode *child_left;
    struct BinarySearchTreeNode *child_right;
    struct BinarySearchTreeNode *next;
} BinarySearchTreeNode;

BinarySearchTreeNode *createBinarySearchNode(Student *element);
void insertBinarySearchNode(BinarySearchTreeNode *node, Student *element);
void findBinarySearchNode(BinarySearchTreeNode *node, Student *element);
int removeBinarySearchNode(BinarySearchTreeNode *node, Student *element);


#endif