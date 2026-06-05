
//微型链表

#include <stdio.h>
#include <stdlib.h>
struct book
{
    int price;
    struct book *next;
    
};
int main(){
    struct book *p = (struct book *)malloc(sizeof(struct book));
    struct book *q = (struct book *)malloc(sizeof(struct book));

    if (q == NULL)
    {
        return 2;
    }
    if (p == NULL)
    {
        return 1;
    }
    
    p->price = 50;
    p->next = q;
    q->price = 20;
    printf("书本p价格为%d\nq的价格为%d",p->price,p->next->price);
    free(p);
    free(q);
    return 0;
}
