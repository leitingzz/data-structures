#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    printf("1.创建链表\n");
    printf("2.打印链表\n");
    while(1){
        int choice;
        printf("请选择功能：");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int n, m;
            printf("请输入链表节点个数：");
            scanf("%d", &n);
            printf("请输入链表节点保存的数字：");

            for(int i = 0; i < n; i++){
                scanf("%d", &m);
                tail = createNode(tail, m);
                if(head == NULL){
                    head = tail;
                };
            }
            break;

        case 2:
            Node* temp = head;
            while(temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
            freeList(head);
            return 0;
            break;
            
        default:
            break;
        }

    }
    
    
    return 0;

}