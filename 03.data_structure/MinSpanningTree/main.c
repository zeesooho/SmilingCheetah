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
        printf("src = %d, dst = %d, weight = %d\n", src, dst, weight);
    }
    fclose(fp);

    fp = fopen("students2.txt", "r");
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL){
        int src = atoi(strtok(line, "\t"));
        int dst = atoi(strtok(NULL, "\t"));
        int weight = atoi(strtok(NULL, "\t"));
        insert_edge(graph, src, dst, weight);
        printf("src = %d, dst = %d, weight = %d\n", src, dst, weight);
    }
    fclose(fp);

    initialize_edge(graph);
    fp = fopen("outputs.csv", "w");
    fprintf(fp, "src,dst,weights\n");
    if(fp == NULL) 
        exit(1);
    printf("adjacent %d x %d\n", graph->size, graph->size);
    for(int i = 0; i < graph->size; i++) {
        printf("%d: ", graph->vertices[i]);
        int* adjacent = get_adjacent(graph, graph->vertices[i]);
        for(int j = 0; j < graph->size; j++) {
            if (adjacent[j] != NOT_FOUND){
                printf("%4d\t", adjacent[j]);
                fprintf(fp, "%d,%d,%.1f\n", get_index(graph, i), adjacent[j], graph->weights[graph->size * get_index(graph, i) + adjacent[j]]);
            }
        }
        free(adjacent);
        printf("\n");
    }
    fclose(fp);
    
    delete_graph(graph);
    return 0;
}