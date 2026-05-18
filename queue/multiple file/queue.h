// queue.h
#ifndef QUEUE_H  // 如果没有定义过 QUEUE_H
#define QUEUE_H  // 那么立刻定义它

// 1. 结构体声明放这里
struct book {
    int price;
    struct book *next;
};

struct Queue {
    struct book *head;
    struct book *tail;
};

// 2. 函数声明（只写外壳，不写大括号里的内容，以分号结尾）
void enqueue(struct Queue *q, int price);
int dequeue(struct Queue *q);

#endif // 结束保护