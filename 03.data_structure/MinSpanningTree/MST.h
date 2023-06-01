#ifndef __MINIMUM_SPANNING_TREE_H__
#define __MINIMUM_SPANNING_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define INF 11
#define NOT_FOUND -1

typedef struct Student{
    int name;
    int size;
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

Graph* create_graph(int size);
void insert_vertex(Graph* graph, int name);
void insert_edge(Graph* graph, int src, int dst, float weight);
void add_edge(Graph* graph, int src, int dst, float weight);
void initialize_edge(Graph* graph);
void delete_vertex(Graph* graph, int name);
void delete_edge(Graph* graph, int src, int dst);
int is_graph_empty(Graph* graph);
int* get_adjacent(Graph* graph, int name);
float* get_weight(Graph* graph, int name);
int get_index(Graph* graph, int name);
void delete_graph(Graph* graph);

#endif