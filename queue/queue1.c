
//简单链队列

#include <stdio.h>
#include <stdlib.h>

//全局变量
struct book *head = NULL;
struct book *tail = NULL;

struct book
{
    int price;
    struct book *next;
};


void enqueue(int price)
{
    struct book *new_node = (struct book *)malloc(sizeof(struct book));
    new_node->price = price;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

int dequeue()
{
    if (head == NULL)
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        struct book *temp = head;
        int value = head->price;
        head = head->next;
        return value;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("出队数价：%d\n",dequeue());
    printf("出队数价：%d\n",dequeue());
    printf("出队数价：%d\n",dequeue());

    dequeue();

    return 0;
}