
//DFS邻接表

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

typedef struct Node{
    int vertex;
    Node* next;
}Node,*myNode;

typedef struct{
    int numVertices;
    myNode adjList[MAX_VERTICES];
}graph,*mygraph;

myNode creatNode(int n){
    myNode newNode = (myNode)malloc(sizeof(Node));
    newNode->vertex = n;
    newNode->next = NULL;
    return newNode;
}

void initgraph(mygraph g){
    for (int i = 0; i < g->numVertices; i++){
            g->adjList[i] = NULL;
    }
}

void addEdge(mygraph g, int src, int dest){
    myNode temp = creatNode(dest);
    temp->next = g->adjList[src];
    g->adjList[src] = temp;

    myNode temp = creatNode(src);
    temp->next = g->adjList[dest];
    g->adjList[dest] = temp;
}

void FDS(mygraph g, int vertex, int visited[]){
    visited[vertex] = 1;
    printf("%d",vertex);

    myNode temp = g->adjList[vertex];
    while (temp != NULL){
        int neighbor = temp->vertex;
        if(visited[neighbor] == 0){
            FDS(g, neighbor, visited);
        }     
        temp = temp->next;
    }
}

void startFDS(mygraph g){
    int visited[] = {0};
    printf("邻接表 FDS 遍历轨迹：");
    FDS(g, 0, visited);
    printf("\n");
}