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
    printf("%d ",vertex);

    for(int i = 0; i < g->numVertices; i++){
        if(g->matrix[vertex][i] == 1 && visited[i] == 0){
            DFS(g, i, visited);
        }
    }
}

void startDFS(mygraph g){
    int visited[MAX_VERTICES] = {0};
    int a = 0;
    DFS(g, a, visited);
}

int main(){

    mygraph g;
    initgraph(g,4);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    startDFS(g);

    return 0;
}