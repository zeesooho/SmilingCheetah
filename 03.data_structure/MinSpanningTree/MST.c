#include <stdio.h>
#include <stdlib.h>
#include "MST.h"

void heapify(Edge* edges, int size){

}

void hsort(Edge* edges, int size){

}

float get_weight_from_list(Edge* edge, int size, int src, int dst){
    for(int i=0; i<size; i++)
        if((edge[i].src == src && edge[i].dst == dst) || (edge[i].src == dst && edge[i].dst == src))
            return edge[i].weight;
    return INF;
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
    if(graph->capacity == graph->size) return;
    if(get_index(graph, name) != NOT_FOUND) return;
    graph->vertices[graph->size++] = name;
}

void insert_edge(Graph* graph, int src, int dst, float weight){
    if (src == dst) return;
    int i = get_index(graph, src);
    int j = get_index(graph, dst);
    if (i == NOT_FOUND || j == NOT_FOUND) return;
    graph->weights[graph->size*i + j] = weight;
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
            float weight = (float)(get_weight(graph, i, j) + get_weight(graph, j, i))/2;
            graph->weights[graph->size*i + j] = graph->weights[graph->size*j + i] = weight;
        }
    }
}

void delete_vertex(Graph* graph, int name){
    int i = get_index(graph, name);
    if (i == NOT_FOUND) return;
    graph->vertices[i] = -1;
    for(int j=0; j<graph->size; j++){
        graph->weights[graph->size*i + j] = INF;
        graph->weights[graph->size*j + i] = INF;
    }
}

void delete_edge(Graph* graph, int src, int dst){
    if (src == dst) return;
    int i = get_index(graph, src);
    int j = get_index(graph, dst);
    if (i == NOT_FOUND || j == NOT_FOUND) return;
    graph->weights[graph->size*i + j] = graph->weights[graph->size*j + i] = INF;
}

int is_graph_empty(Graph* graph){
    return (graph->size == 0)? 1 : 0;
}

int* get_adjacent(Graph* graph, int name){
    int* adj = (int*)malloc(graph->size*sizeof(int));
	for(int i=0; i<graph->size; i++){
        float weight = get_weight(graph, get_index(graph, name), i);
        if((int)weight == INF || (int)weight == 0){
		    adj[i] = NOT_FOUND;
        }else{
		    adj[i] = i;
        }
	}
	return adj;
}

float get_weight(Graph* graph, int src, int dst){
    return graph->weights[graph->size * src + dst];
}

float* get_weights(Graph* graph, int name){
    float* weights = (float*)malloc(graph->size*sizeof(float));
	for(int i=0; i<graph->size; i++){
        float weight = get_weight(graph, get_index(graph, name), i);
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

int get_min_vertex(int size, int* selected_vertex, float* distance){
    int min_vertex = -1;
    for(int i=0; i<size; i++)
        if(!selected_vertex[i]){
            min_vertex = i;
            break;
        }
    for(int i=0; i<size; i++)
        if(!selected_vertex[i]
         && (distance[i] < distance[min_vertex]))
          min_vertex = i;
    return min_vertex;
}

Graph* prim(Graph* graph, int start_vertex){
    // 새로운 mst_graph 생성
    Graph* mst_graph = create_graph(100);
    // 임시 edge 초기화
    Edge* edge = (Edge*)malloc(100 * sizeof(Edge));
    for(int i=0; i<graph->size; i++){
        edge[i].src = -1; //name of src
        edge[i].dst = -1; //name of dst
        edge[i].weight = INF;
    }
    // selected, distance 배열 초기화
    // 각각 이름이 곧 인덱스
    int* selected_vertex = (int*)calloc(graph->size, sizeof(int));
    float* distance = (float*)malloc(graph->size*sizeof(float));
    for(int i=0; i<graph->size; i++)
        distance[i] = INF;
    // 시작 
    distance[start_vertex] = 0;
    insert_vertex(mst_graph, start_vertex);
    for(int i=0; i<graph->size; i++){
        // min_vertex는 이름
        int min_vertex = get_min_vertex(graph->size, selected_vertex, distance);
        selected_vertex[min_vertex] = TRUE;
        insert_vertex(mst_graph, min_vertex);
        if(distance[min_vertex] == INF) return NULL;

        for(int v=0; v<graph->size; v++){
            if(get_weight(graph, get_index(graph, min_vertex), get_index(graph, v)) != INF 
                && !selected_vertex[v]
                && get_weight(graph, get_index(graph, min_vertex), get_index(graph, v)) < distance[v]){
                    edge[v].src = min_vertex;
                    edge[v].dst = v;
                    edge[v].weight = get_weight(graph, get_index(graph, min_vertex), get_index(graph, v));
                    distance[v] = get_weight(graph, get_index(graph, min_vertex), get_index(graph, v));
             }
        }
    }

    for(int i = 0; i < graph->size; i++){
        if(edge[i].weight != INF){
            insert_edge(mst_graph, edge[i].src, edge[i].dst, edge[i].weight);
            insert_edge(mst_graph, edge[i].dst, edge[i].src, edge[i].weight);
        }
    }
    free(selected_vertex);
    free(distance);
    return mst_graph;
}