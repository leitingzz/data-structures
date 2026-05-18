// queue.c
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"  // 必须引入自己的头文件

// 实现入队
void enqueue(struct Queue *q, int price) {
    struct book *new_node = (struct book *)malloc(sizeof(struct book));
    new_node->price = price;
    new_node->next = NULL;

    if (q->tail == NULL) { 
        q->head = new_node;
        q->tail = new_node;
    } else {            
        q->tail->next = new_node;
        q->tail = new_node;
    }
    printf("成功入队一本书，价格：%d\n", price);
}

// 实现出队
int dequeue(struct Queue *q) {
    if (q->head == NULL) {
        printf("队列已空，无人排队！\n");
        return -1;
    }

    struct book *temp = q->head; 
    int value = q->head->price;
    
    q->head = q->head->next;
    if (q->head == NULL) {       
        q->tail = NULL;
    }

    free(temp);
    return value;
}