
//DFS邻接表+深度优先搜索

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

void initgraph(mygraph g, int vertices){
    g->numVertices = vertices;
    for (int i = 0; i < g->numVertices; i++){
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

void DFS(mygraph g, int vertex, int visited[]){
    visited[vertex] = 1;
    printf("%d",vertex);

    myNode temp = g->adjList[vertex];

    while (temp != NULL){
        int neighbor = temp->vertex;
        if(visited[neighbor] == 0){
            DFS(g, neighbor, visited);
        }     
        temp = temp->next;
    }
}

void startDFS(mygraph g){
    int visited[MAX_VERTICES] = {0};
    printf("邻接表 FDS 遍历轨迹：");
    DFS(g, 0, visited);
    printf("\n");
}

int main(){
    mygraph g;
    initgraph (g, 4);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    startDFS(g);

    return 0;
}