#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    printf("1.创建链表\n");
    printf("2.打印链表\n");
    printf("请选择功能：\n");

    switch (1)
    {
    case 1:
        int n, m;
        printf("请输入链表节点个数：");
        scanf("%d", &n);
        printf("请输入链表节点保存的数字：");

        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            createNode(head, tail, m);
        }
        break;

    case 2:
        Node* temp = head;
        while(temp != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }
        break;
        
    default:
        break;
    }

    return 0;

}