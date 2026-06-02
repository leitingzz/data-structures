
//邻接表（数组+链表）

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

//链表节点结构
typedef struct{
    int vertex;
    myNode next;
}Node,*myNode;

//图结构
typedef struct{
    int numVertex;
    //核心：是个指针数组，存的是每个顶点链表的头指针
    myNode adjList[MAX_VERTICES];
}graph,*myGraph;

