#include "BST.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Student *createStudent(char *birth, char name, int grade){
    Student *student = (Student*)malloc(sizeof(Student));
    strcpy(student->birth, birth);
    student->name = name;
    student->grade = grade;
    return student;
}

void printStudent(Student *element){
    printf("%s, %c, %d\n", element->birth, element->name, element->grade);
}

BSTNode *createBSTNode(char *birth, char name, int grade){
    BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));
    node->next = node->child_left = node->child_right = NULL;
    node->element = createStudent(birth, name, grade);
    return node;
}

void printNode(BSTNode *node){
    printf("Element: ");
    printStudent(node->element);
    char* left = (node->child_left != NULL)? getKey(node->child_left): "NULL";
    char* right = (node->child_right != NULL)? getKey(node->child_right): "NULL";
    char* next = (node->next != NULL)? getKey(node->next): "NULL";
    // printf("left: %s, right: %s, next: %s\n", left, right, next);
}

void printNodeElement(BSTNode *node){
    printStudent(node->element);
}

char* getKey(BSTNode *node){
    return node->element->birth;
}

int keycmp(BSTNode *a, BSTNode *b){
    return strcmp(getKey(a), getKey(b));
}

int isLeafNode(BSTNode *node){
    return (node->child_left == NULL && node->child_right == NULL);
}

int countChild(BSTNode *node){
    return (isLeafNode(node))? 0: ((node->child_left != NULL && node->child_right != NULL)? 2: 1);
}

BST *createBST(){
    BST *tree = (BST*)malloc(sizeof(BST));
    tree->head = NULL;
    tree->size = 0;
    return tree;
}

void printTreeByDepth(BSTNode *node, int depth, char* depth_str){
    if (node == NULL) {
        return;
    }
    printf("%s  %s, %c, %d\n", depth_str, node->element->birth, node->element->name, node->element->grade);
    char temp[100];
    sprintf(temp, "%s -> %c", depth_str, node->element->name);
    printTreeByDepth(node->child_left, depth + 1, temp);
    printTreeByDepth(node->child_right, depth + 1, temp);
}

void printTree(BST *tree){
    printTreeByDepth(tree->head, 0, "head");
}

void printTreeByPostorder(BSTNode *node){
    if (node == NULL) {
        return;
    }
    printTreeByPostorder(node->child_left);
    printf("%s, %c, %d\n", node->element->birth, node->element->name, node->element->grade);
    printTreeByPostorder(node->child_right);
}

void insertBSTNode(BST *tree, char *birth, char name, int grade){
    BSTNode *temp = createBSTNode(birth, name, grade);
    if (tree->head == NULL){
        tree->head = tree->front = tree->back = temp;
        tree->size++;
        return;
    }
    BSTNode *previous = NULL;
    BSTNode *current = tree->head;
    while (1){
        int cmp = keycmp(temp, current);
        if (cmp == 0) break;
        else if (cmp == 1) {
            if (current->child_right != NULL){
                previous = current;
                current = current->child_right;
            } else {
                temp->next = current->next;
                current->next = temp;
                if (temp->next == NULL) tree->back = temp;
                current->child_right = temp;
                tree->size++;
                break;
            }
        }else if (cmp == -1){
            if (current->child_left != NULL){
                previous = current;
                current = current->child_left;
            } else {
                BSTNode *i = tree->front;
                while (i->next != NULL){
                    if (keycmp(temp, i) == -1) break;
                    previous = i;
                    i = i->next;
                }
                if (i==tree->front) tree->front = temp; else previous->next = temp;
                temp->next = i;
                current->child_left = temp;
                tree->size++;
                break;
            }
        }
    }
}

void findBSTNode(BST *tree,  char *birth){
    BSTNode *current = tree->head;
    int cmp = 0;
    while(1){
        if (current)
        cmp = strcmp(birth, current->element->birth);
        if (cmp == 0){
            printNode(current);
            break;
        }else{
            if (isLeafNode(current))
                break;
            if (cmp == 1){
                current = current->child_right;
            }else if (cmp == -1){
                current = current->child_left;
            }
        }
    }
}

void deleteBSTNode(BST *tree, char *birth){
    if (tree == NULL || tree->head == NULL) return;
    // find node
    BSTNode *previous = NULL;
    BSTNode *current = tree->head;
    int previous_cmp = 0;
    int cmp = strcmp(birth, current->element->birth);
    while (cmp){
        previous = current;
        if(cmp == -1){
            if(current->child_left == NULL) return;
            else current = current->child_left;
        }else{
            if(current->child_right == NULL) return;
            else current = current->child_right;
        }
        previous_cmp = cmp;
        cmp = strcmp(birth, current->element->birth);
    }

    // rewiring tree
    int cnt = countChild(current);
    if(current == tree->head){
        // 만약 삭제해야하는 노드가 헤드일 경우 헤드를 재설정해준다.
        if(cnt == 0) tree->head = NULL;
        else if(cnt == 1){
            tree->head = (current->child_left != NULL)? current->child_left: current->child_right;
        }else if(cnt == 2){
            tree->head = current->child_right;
            if(current->child_right->child_left != NULL){
                BSTNode *temp = current->child_left;
                while(temp->child_right != NULL) temp = temp->child_right;
                temp->child_right = current->child_right->child_left;
                }
            current->child_right->child_left = current->child_left;
        }
    }else{
        if(cnt == 0){ 
            // 만약 삭제해야할 노드가 리프노드라면 그냥 지운다
            if(previous_cmp == -1) previous->child_left = NULL;
            else previous->child_right = NULL;
        }else if(cnt == 1){ 
            // 만약 삭제해야할 노드가 자식을 하나 가진다면 그대로 이어준다
            if(previous_cmp == -1) previous->child_left = (current->child_left != NULL)? current->child_left: current->child_right;
            else previous->child_right = (current->child_left != NULL)? current->child_left: current->child_right;
        }else if(cnt == 2){
            // 만약 삭제해야할 노드가 자식을 둘 가진다면 오른쪽 자식을 해당 노드의 위치로 옮긴다.
            // 근데 오른쪽 자식에게 왼쪽 자식이 있다면 삭제해야할 노드의 왼쪽 자식의 서브트리에서 가장 큰 자리에 넣어준다.
            if(previous_cmp == -1) previous->child_left = current->child_right;
            else previous->child_right = current->child_right;
            if(current->child_right->child_left != NULL){
                BSTNode *temp = current->child_left;
                while(temp->child_right != NULL) temp = temp->child_right;
                temp->child_right = current->child_right->child_left;
            }
            current->child_right->child_left = current->child_left;
        }
    }

    previous = NULL;
    BSTNode *temp = tree->front;
    while(temp != current){
        previous = temp;
        temp = temp->next;
    }
    if(temp == tree->front) tree->front = temp->next;
    if(temp == tree->back){
        if (previous != NULL) tree->back = previous;
        else tree->back = NULL;
    }
    if(previous != NULL) previous->next = temp->next;
    printNode(current);

    // delete node    
    free(current->element);
    free(current);
    tree->size--;
}

void deleteTree(BST *tree){
    BSTNode *previous = NULL;
    BSTNode *current = tree->front;
    while (current != NULL){
        previous = current;
        current = current->next;
        free(previous->element);
        free(previous);
        tree->size--;
    }
    free(tree);
}


int main(int argc, char **argv){
    BST *tree = createBST();
    FILE *fp = fopen("student.txt", "r");

    if (fp == NULL)
        exit(1);

    char line[1024];
    fgets(line, sizeof(line), fp);
    while (fgets(line, sizeof(line), fp) != NULL){
        char *birth = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        int grade = atoi(strtok(NULL, "\t"));
        insertBSTNode(tree, birth, name[0], grade);
    }
    printf("Init Tree: %d\n", tree->size);
    printTree(tree);
    fclose(fp);

    printf("\n");
    printf("delete node\n");
    deleteBSTNode(tree, "20010703");
    deleteBSTNode(tree, "20040903");
    deleteBSTNode(tree, "20030108");
    deleteBSTNode(tree, "20050823");
    deleteBSTNode(tree, "20011105");

    printf("\n");
    printTreeByPostorder(tree->head);

    deleteTree(tree);
}