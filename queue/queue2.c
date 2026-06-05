
//不用全局变量

#include <stdio.h>
#include <stdlib.h>

struct book 
{
    int price;
    struct book *next;
};

struct queue
{
    struct book *head;
    struct book *tail;
};

void enqueue(struct queue*p,int price)
{
    struct book *new_node = (struct book *)malloc(sizeof(struct book));
    new_node->next = NULL;
    new_node->price = price;

    if (p->tail == NULL)
    {
        p->head = new_node;
        p->tail = new_node;
    }
    else
    {
        p->tail->next = new_node;
        p->tail = new_node;
    }
}

int dequeue(struct queue*p)
{
    if (p->head == NULL)
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        int value;
        struct book *temp = p->head;
        value = temp->price;
        p->head = p->head->next;
        free(temp);
        return value;
    }

}

int main()
{
    struct queue *p;
    p->head = NULL;
    p->tail = NULL;

    enqueue(p,10);
    enqueue(p,20);
    enqueue(p,30);

    printf("出列书本价格：%d\n",dequeue(p));
    printf("出列书本价格：%d\n",dequeue(p));
    printf("出列书本价格：%d\n",dequeue(p));

    dequeue(p);

    return 0;
}