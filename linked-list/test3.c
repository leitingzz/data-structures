
//链表的查找

#include <stdio.h>
#include <stdlib.h>

struct book
{
    int price;
    struct book *next;
};

struct book *find_book(struct book *head,int price)
{
    struct book *p = head;
    while (p != NULL)
    {
        if (p->price == price)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

int main()
{
    struct book *head = NULL;
    struct book *tail = NULL;

    int n;
    printf("创建书本数量:");
    scanf("%d",&n);

    for (int i = 1;i <= n;i++)
    {
        struct book *new_book = (struct book *)malloc(sizeof(struct book));
        new_book->price = i * 10;
        new_book->next = NULL;
        if (head == NULL)
        {
            head = new_book;
            tail = new_book;
        }
        else
        {
            tail->next = new_book;
            tail = new_book;
        }
    }

    int price;
    printf("输入想要查找书本的价格：");
    scanf("%d",&price);
    struct book *target = find_book(head,price);

    if(target != NULL)
    {
        printf("有此价格的书本");
    }
    else
    {
        printf("无此价格的书本");
    }

    return 0;
}