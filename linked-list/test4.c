
//删除节点

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

    struct book *prev = NULL;
    struct book *curr = head;

    int target;
    printf("输入删除书本价格：");
    scanf("%d",&target);

    while (curr != NULL && curr->price != target)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("无需要删除的书本");
    }
    else
    {
        if(curr == head)
        {
            head = head->next;
        }
        else
        {
            prev = curr->next;
        }
    }
    free(curr);
    return 0;
}