#include <stdio.h>
#include <stdlib.h>
#include "MST.h"

void heapify(Edge* edges, int size){

}

void hsort(Edge* edges, int size){

}

Graph* create_graph(int size){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = 0;
    graph->capacity = size;
    graph->vertices = (int*)malloc(size*sizeof(int));
    graph->weights = (float*)malloc(size*size*sizeof(float));
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            graph->weights[size*i + j] = (i==j)? 0: INF;
    return graph; 
}

void insert_vertex(Graph* graph, int name){
    if(get_index(graph, name) != NOT_FOUND) return;
    graph->vertices[graph->size++] = name;
}

void insert_edge(Graph* graph, int src, int dst, float weight){
    if (src == dst) return;
    int i = get_index(graph, src);
    int j = get_index(graph, dst);
    if (i == NOT_FOUND || j == NOT_FOUND) return;
    if (graph->weights[graph->size*i + j] == INF)
        graph->weights[graph->size*i + j] = weight;
    else
        add_edge(graph, src, dst, weight);
}

void add_edge(Graph* graph, int src, int dst, float weight){
    if (src == dst) return;
    int i = get_index(graph, src);
    int j = get_index(graph, dst);
    if (i == NOT_FOUND || j == NOT_FOUND) return;
    graph->weights[graph->size*i + j] = (float)(graph->weights[graph->size*i + j] + weight)/2;
}

void initialize_edge(Graph* graph){
    for(int i = 0; i < graph->size; i++){
        for(int j = i+1; j < graph->size; j++){
            float weight = (float)(graph->weights[graph->size*i + j] + graph->weights[graph->size*j + i])/2;
            graph->weights[graph->size*i + j] = graph->weights[graph->size*j + i] = weight;
        }
    }
}

void delete_vertex(Graph* graph, int name){
    int i = get_index(graph, name);
    if (i == NOT_FOUND) return;
}

void delete_edge(Graph* graph, int src, int dst){
    if (src == dst) return;
    int i = get_index(graph, src);
    int j = get_index(graph, dst);
    if (i == NOT_FOUND || j == NOT_FOUND) return;
}

int is_graph_empty(Graph* graph){

}

int* get_adjacent(Graph* graph, int name){
    int* adj = (int*)malloc(graph->size*sizeof(int));
	for(int i=0; i<graph->size; i++){
        float weight = graph->weights[graph->size * get_index(graph, name) + i];
        if((int)weight == INF || (int)weight == 0){
		    adj[i] = NOT_FOUND;
        }else{
		    adj[i] = get_index(graph, i);
        }
	}
	return adj;
}

float* get_weight(Graph* graph, int name){
    float* weights = (float*)malloc(graph->size*sizeof(float));
	for(int i=0; i<graph->size; i++){
        float weight = graph->weights[graph->size * get_index(graph, name) + i];
        weights[i] = weight;
	}
	return weights;
}

int get_index(Graph* graph, int name){
	for(int i=0; i<graph->size; i++)
		if(graph->vertices[i] == name)
			return i;
	return NOT_FOUND;
}

void delete_graph(Graph* graph){
    free(graph->vertices);
    free(graph->weights);
    free(graph);
}