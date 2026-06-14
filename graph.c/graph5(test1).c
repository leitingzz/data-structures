void BFS(mygraph g, int startVertex) {
    // 1. 准备工作：创建一个 visited 数组，一个排队机（队列变量）
    int visited[max] = {0};

    int quene[max];
    int front = 0;
    int rear = 0;
    
    // 2. 游戏开始：把起点标记为去过，并塞进排队机
    visited[startVertex] = 1;
    quene[rear++] = startVertex;

    // 3. 核心循环：只要排队机里还有人，就一直抓人
    while(rear > front){
        int currenVertex = quene[front++];
        printf("%d",currenVertex);

        // 4. 抓人动作：拉出一个队头，翻开他的朋友圈，把没去过的邻居全塞进队尾
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