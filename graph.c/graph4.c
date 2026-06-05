
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

