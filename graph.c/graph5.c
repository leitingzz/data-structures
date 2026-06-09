
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

