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
    struct book *tail = NULL;
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
    {
        struct book *new_node = (struct book *)malloc(sizeof(struct book));
        new_node->price = i * 10;
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
    struct book *p =head;
    while (p != NULL)
    {
        printf("书本的价格为:%d\n",p->price);
        p = p->next;
    }
    return 0;

}