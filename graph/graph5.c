
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

void BFS(mygraph g, int startvertex){
    
    int visited[MAX_VERTICES] = {0};

    //1.一个简易排队机
    int quene[MAX_VERTICES];
    int rear = 0;
    int front = 0;

    //2.起点入队并标记
    visited[startvertex] = 1;
    quene[rear++] = startvertex;
    printf("邻接表 BFS 遍历轨迹：");

    //3.排队机只要有人就继续抓
    while(front < rear){
        int currenVertex = quene[front++];//从队头拉出一个人
        printf("%d",currenVertex);
        
        //4.翻开这个人的朋友圈
        myNode temp = g->adjList[currenVertex];

        while(temp != NULL){
            int neighbor = temp->vertex;

            //检查邻居
            if(visited[neighbor] == 0){
                visited[neighbor] = 1;
                quene[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}