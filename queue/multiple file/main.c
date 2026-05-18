// main.c
#include <stdio.h>
#include "queue.h"  // 只需要引入头文件，就能直接调用队列功能

int main() {
    struct Queue my_queue;
    my_queue.head = NULL;
    my_queue.tail = NULL;

    printf("--- 跨文件多模块队列测试 ---\n");
    enqueue(&my_queue, 10);
    enqueue(&my_queue, 20);
    enqueue(&my_queue, 30);

    printf("\n--- 开始出队 ---\n");
    printf("出队书本价格：%d\n", dequeue(&my_queue)); 
    printf("出队书本价格：%d\n", dequeue(&my_queue)); 

    return 0;
}

//