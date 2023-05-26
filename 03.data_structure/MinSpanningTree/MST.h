#ifndef __MINIMUM_SPANNING_TREE_H__
#define __MINIMUM_SPANNING_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define INF -1

typedef struct Student{
    int name;
    int* friends;
    int* weights;
}Student;

typedef struct Edge{
    int src;
    int dst;
    float weight;
}Edge;

void heapify(Edge* edges, int size);
void hsort(Edge* edges, int size);

typedef struct Graph{
    int size;
    int capacity;
    int* vertices;
    float* weights;
}Graph;

Graph* createGraph(int size);
void insertVertex(Graph* graph, int name);
void insertEdge(Graph* graph, Edge edge);
void deleteVertex(Graph* graph, int name);
void deleteEdge(Graph* graph, Edge edge);
int isGraphEmpty(Graph* graph);
int* getAdjacent(Graph* graph, int name);
int getIndex(Graph* graph, int name);
void deleteGraph(Graph* graph);

#endif