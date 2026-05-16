#include <stdio.h>
#include <stdlib.h>

struct book 
{
    int price;
    struct book *prev;
    struct book *next;
};

int main()
{
    int n;
    printf("输入书本数量：");
    scanf("%d",&n);

    struct book *head = NULL;
    struct book *tail = NULL;

    for (int i = 1;i <= n;i++)
    {
        struct book *new_book = (struct book *)malloc(sizeof(struct book));
        new_book->price = i * 10;
        new_book->next = NULL;
        new_book->prev = NULL;

        if (head == NULL)
        {
            head = new_book;
            tail = new_book;
        }
        else
        {
            new_book->prev = tail;
            tail->next = new_book;
            tail = new_book;
        }
    }

    struct book *p = head;
    while (p != NULL)
    {
        printf("书本价格：%d\n",p->price);
        p = p->next;
    }

    struct book *q = tail;
    while (q != NULL)
    {
        printf("书本价格：%d\n",q->price);
        q = q->prev;
    }

    struct book *temp1 = head;
    struct book *temp2 = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    
    return 0;
}