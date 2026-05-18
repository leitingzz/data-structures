#include <stdio.h>
#include <stdlib.h>

struct book 
{
    int price;
    struct book *next;
};

int main()
{
    struct book *head = NULL;

    struct book *p1 = (struct book *)malloc(sizeof(struct book));
    p1->price = 10;
    p1->next = head;
    head = p1;

    struct book *p2 = (struct book *)malloc(sizeof(struct book));
    p2->price = 20;
    p2->next = head;
    head = p2;

    struct book *p3 = (struct book *)malloc(sizeof(struct book));
    p3->price = 30;
    p3->next = head;
    head = p3;

    struct book *q = head;
    while (q != NULL)
    {
        printf("出栈顺序价格：%d\n",q->price);
        q = q->next;
    }
     
    return 0;
}