#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct{
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
}graph,*mygraph;

void initgraph(mygraph g,int vertices){

    g->numVertices = vertices;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            g->matrix[i][j] = 0;
        }
    }
}

void addEdge(mygraph g,int a,int b){
    g->matrix[a][b] = 1;
    g->matrix[b][a] = 1;
}

