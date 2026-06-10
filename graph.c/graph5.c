
//BFS广度优先搜索

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int vertex;
    Node* next;
}Node,*myNode;

typedef struct{
    int numVertices;
    myNode adjList[MAX_VERTICES];
}graph,*mygraph;

myNode creatNode(int vertex){
    myNode temp = (myNode)malloc(sizeof(Node));
    temp->vertex = vertex;
    temp->next = NULL;
    return temp;
}

void initGraph(mygraph g, int vertices){
    g->numVertices = vertices;
    for(int i = 0; i < vertices; i++){
        g->adjList[i] = NULL;
    }
}

void addEdge(mygraph g, int src, int dest){
    myNode temp = creatNode(dest);
    temp->next = g->adjList[src];
    g->adjList[src] = temp;

    temp = creatNode(src);
    temp->next = g->adjList[dest];
    g->adjList[dest] = temp;
}

