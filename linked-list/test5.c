
//双向链表

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main ()
{

    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));
    struct node *p = c;

    a->data = 1;
    b->data = 2;
    c->data = 3;

    a->next = b;
    b->next = c;
    c->next = NULL;

    a->prev = NULL;
    b->prev = a;
    c->prev = b;

    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->prev;
    }

    free(a);
    free(b);
    free(c);
    
    return 0;
}