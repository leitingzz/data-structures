void BFS(mygraph g, int startVertex){
    int visited[max] = {0};

    int quene[max];
    int front = 0;
    int rear = 0;

    visited[startVertex] = 1;
    quene[rear++] = startVertex;

    while(front < rear){
        int currenVertex = quene[front++];
        printf("%d",currenVertex);

        myNode temp = g->adjList[currenVertex];

        while(temp != NULL){
            int neighbor = temp->vertex;
            if(visited[neighbor] = 0){
                visited[neighbor] = 1;
                quene[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}