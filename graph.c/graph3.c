
//邻接表（数组+链表）

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

//链表节点结构
typedef struct{
    int vertex;
    Node* next;
}Node,*myNode;

//图结构
typedef struct{
    int numVertex;
    //核心：是个指针数组，存的是每个顶点链表的头指针
    myNode adjList[MAX_VERTICES];
}graph,*myGraph;

myNode creatNode(int v){
    myNode newNode = (myNode)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(myGraph g, int src, int dest){
    myNode newNode = creatNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = creatNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}



