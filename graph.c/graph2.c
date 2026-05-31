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

void DFS(mygraph g, int vertex,int visited[]){
    
    visited[vertex] = 1;
    printf("%d",vertex);

    for(int i = 0; i < g->numVertices; i++){
        if(g->matrix[vertex][i] == 1 && visited[i] != 0){
            void DFS(mygraph g, int i, int visited[i]);
        }
    }
}

void startDFS(mygraph g){
    int visited[] = {0};
    int a = 0;
    void DFS(g, a, visited);
}