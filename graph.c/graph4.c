
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