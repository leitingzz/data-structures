#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int num = 0;
    printf("1.创建链表\n");
    printf("2.打印链表\n");
    printf("3.查找节点\n");
    printf("4.插入节点\n");
    printf("5.删除节点\n");
    printf("6.反转链表\n");
    printf("7.查找中间节点\n");
    printf("8.判断链表是否有环\n");
    printf("9.将链表链接成环\n");
    printf("10.将环断开\n");
    printf("0.退出程序\n");
    while(1){
        int choice;
        printf("请选择功能：");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int m;
            Node* newNode;
            printf("请输入链表节点个数：");
            scanf("%d", &num);
            printf("请输入链表节点保存的数字：");

            for(int i = 0; i < num; i++){
                scanf("%d", &m);
                newNode = createNode(m);
                if(head == NULL){
                    head = newNode;
                    tail = newNode; 
                }else{
                    tail->next = newNode;
                    tail = newNode;
                };
            }
            printf("创建完成！\n");
            break;

        case 2:
            Node* temp = head;
            while(temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
            
        case 3:
            int choice2;
            Node* target;
            printf("1.按值查找\n");
            printf("2.按位置查找\n");
            printf("请选择功能：");
            scanf("%d", &choice2);
            switch(choice2)
            {
                case 1:
                int value;
                printf("请输入所查找的值：");
                scanf("%d", &value);
                target = searchByValue(head, value);
                if(target != NULL){
                    printf("该节点存在！\n");
                }else{
                    printf("该节点不存在！\n");
                }
                break;
                
                case 2:
                searchByLocate(head, num);
                break;
                
                default:
                break;
            }
            break;

        case 4:
        head = insert(head, num, &tail);
        num++;
        printf("插入完成！\n");
        break;

        case 5:
        int a;
        printf("请输入删除值：");
        scanf("%d", &a);
        head = delete(head, a, &tail, &num);
        break;

        case 6:
        head = reverseList(head, &tail);
        break;

        case 7:
        Node* middle = fideMiddle(head, num);
        if(middle != NULL){
            printf("中间节点值为：%d\n", middle->data);
        }
        break;

        case 8:
        hasCycle(head);
        break;

        case 9:
        if(head == NULL){
            printf("该链表为空！\n");
        }else{
         tail->next = head;
         printf("链接完成！\n");
        }
        break;

        case 10:
        if(head == NULL){
            printf("链表为空！\n");
        }else{
            tail->next = NULL;
            printf("断开完成！\n");
        }
        break;
            
        case 0:
            freeList(head);
            printf("感谢使用，再见！\n");
            return 0;
            
            default:
            printf("指令无效，请重新输入！\n");
            break;
        }

    }
    
    return 0;

}