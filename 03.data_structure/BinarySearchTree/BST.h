#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Student{
    char birth[9];
    char name;
    int grade;
}Student;

Student *createStudent(char *birth, char name, int grade);
void printStudent(Student *element);

typedef struct BSTNode{
    Student *element;
    struct BSTNode *child_left;
    struct BSTNode *child_right;
    struct BSTNode *next;
}BSTNode;

BSTNode *createBSTNode(char *birth, char name, int grade);
void printNode(BSTNode *node);
void printNodeElement(BSTNode *node);
char* getKey(BSTNode *node);
int keycmp(BSTNode *a, BSTNode *b);
int isLeafNode(BSTNode *node);
int countChild(BSTNode *node);

typedef struct BST{
    BSTNode *head;
    BSTNode *front;
    BSTNode *back;
    int size;
}BST;

BST *createBST();

void printTreeByDepth(BSTNode *node, int depth, char* depth_str);
void printTreeByPostorder(BSTNode *node);
void printTree(BST *tree);

void insertBSTNode(BST *tree, char *birth, char name, int grade);
void findBSTNode(BST *tree,  char *birth);
void deleteBSTNode(BST *tree, char *birth);
void deleteTree(BST *tree);


#endif