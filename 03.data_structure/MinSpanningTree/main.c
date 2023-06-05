#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MST.h"

int main(int argc, char **argv){
    Graph* graph = create_graph(100);

    FILE *fp = fopen("students2.txt", "r");
    if (fp == NULL)
        exit(1);

    char line[1024];
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL){
        int src = atoi(strtok(line, "\t"));
        int dst = atoi(strtok(NULL, "\t"));
        int weight = atoi(strtok(NULL, "\t"));
        insert_vertex(graph, src);
    }
    fclose(fp);

    fp = fopen("students2.txt", "r");
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL){
        int src = atoi(strtok(line, "\t"));
        int dst = atoi(strtok(NULL, "\t"));
        int weight = atoi(strtok(NULL, "\t"));
        insert_edge(graph, src, dst, weight);
    }
    fclose(fp);

    initialize_edge(graph);
    fp = fopen("outputs2.csv", "w");
    fprintf(fp, "src,dst,weights\n");
    Graph* mst_graph = prim(graph, 0);
    if(prim == NULL) exit(1);
    for(int i = 0; i < mst_graph->size; i++){
        int* adjacent = get_adjacent(mst_graph, mst_graph->vertices[i]);
        for(int j = 0; j < mst_graph->size; j++){
            if(adjacent[j] != NOT_FOUND){
                fprintf(fp, "%d,%d,%.1f\n", mst_graph->vertices[i], mst_graph->vertices[adjacent[j]], get_weight(mst_graph, i, adjacent[j]));
            }
        }
        free(adjacent);
    }
    fclose(fp);

    float weight_sum = 0.0;
    for(int i=0; i<mst_graph->size; i++){
        for(int j=i+1; j<mst_graph->size; j++){
            if(get_weight(mst_graph, i, j) != INF){
                weight_sum += get_weight(mst_graph, i, j);
            }
        }
    }

    printf("%f\n", weight_sum);
    delete_graph(graph);
    delete_graph(mst_graph);
    return 0;
}