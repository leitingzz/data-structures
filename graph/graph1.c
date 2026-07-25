
//邻接矩阵 (Adjacency Matrix) —— 用二维数组存图

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int numVertice;  //当前图中有多少顶点
}graph,*mygraph;

//初始化图
void initGraph (mygraph g, int vertices){
    g->numVertice = vertices;
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j <vertices; j++){
            g->matrix[i][j] = 0;
        }
    }
}

//添加边（无向图）
void addEdge(mygraph g, int start, int end){
    g->matrix[start][end] = 1;
    g->matrix[end][start] = 1;
}

//打印邻接矩阵
void printfGraph(mygraph g){
    printf("当前邻接矩阵\n");
    for(int i = 0; i < g->numVertice; i++){
        for(int j = 0; j < g->numVertice; j++){
            printf("%d",g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    mygraph g;

    initGraph(g, 4);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    printfGraph(g);

    return 0;
}