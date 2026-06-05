
//压栈（头插法）与弹栈

#include <stdio.h>
#include <stdlib.h>

struct book 
{
    int price;
    struct book *next;
};

struct book *push(struct book *head,int price)
{
    struct book *new_node = (struct book *)malloc(sizeof(struct book));
    new_node->price = price;
    new_node->next = head;
    return new_node;
}

struct book *pop(struct book *head,int *value)
{
    if (head == NULL)
    {
        printf("栈空，无法弹栈");
        return NULL;
    }
    else
    {
        struct book *temp = head;
        *value = head->price;
        head = head->next;
        return head;
    }
}

int main()
{
    struct book *head = NULL;
    int value;

    head = push(head,10);
    printf("压入:%d\n",head->price);
    head = push(head,20);
    printf("压入:%d\n",head->price);    
    head = push(head,30);
    printf("压入:%d\n",head->price);

    head = pop(head,&value);
    printf("弹出:%d\n",value);
    head = pop(head,&value);
    printf("弹出:%d\n",value);
    head = pop(head,&value);
    printf("弹出:%d\n",value);
    head = pop(head,&value);

    return 0;
}