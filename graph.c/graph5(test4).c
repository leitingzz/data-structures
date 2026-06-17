void BFS(mygraph g, int startVertex){
    int visited[max] = {0};
    int quene[max];
    int front = 0;
    int rear = 0;

    quene[rear++] = startVertex;
    visited[startVertex] = 1;

    while(rear > front){
        int currenVertex = quene[front++];
        printf("%d",currenVertex);

        myNode temp = g->adjList[currenVertex];
        
        while(temp != NULL){
            int neighbor = temp->vertex;
            while(visited[neighbor] = 0){
                quene[rear++] = neighbor;
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}