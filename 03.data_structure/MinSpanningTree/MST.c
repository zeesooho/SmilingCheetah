#include <stdio.h>
#include <stdlib.h>
#include "MST.h"

void heapify(Edge* edges, int size){

}

void hsort(Edge* edges, int size){

}

Graph* createGraph(int size){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = 0;
    graph->capacity = size;
    graph->vertices = (int*)malloc(size*sizeof(int));
    graph->weights = (float*)malloc(size*size*sizeof(float));
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            graph->weights[size*i + j] = INF;
    return graph; 
}

void insertVertex(Graph* graph, int name){
    graph->vertices[graph->size++] = name;
}

void insertEdge(Graph* graph, Edge edge){
    
}

void deleteVertex(Graph* graph, int name){

}

void deleteEdge(Graph* graph, Edge edge){

}

int isGraphEmpty(Graph* graph){

}

int* getAdjacent(Graph* graph, int name){
    int* adj = (int*)malloc(graph->size*sizeof(int));
	for(int i=0; i<graph->size; i){
		adj[i] = graph->weights[getIndex(graph, name)];
	}
	return adj;
}

int getIndex(Graph* graph, int name){
	for(int i=0; i<graph->size; i++)
		if(graph->vertices[i] == name)
			return i;
	return -1;
}

void deleteGraph(Graph* graph){

}