#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MST.h"

int main(int argc, char **argv){
    FILE *fp = fopen("students2.txt", "r");
    if (fp == NULL)
        exit(1);

    char line[1024];
    fgets(line, sizeof(line), fp);
    while (fgets(line, sizeof(line), fp) != NULL){
        int src = atoi(strtok(line, "\t"));
        int dist = atoi(strtok(NULL, "\t"));
        int weight = atoi(strtok(NULL, "\t"));
        // TODO insert students node
        printf("src = %d, dist = %d, weight = %d\n", src, dist, weight);
    }
    fclose(fp);
    
    return 0;
}