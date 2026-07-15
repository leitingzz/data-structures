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
        head = delete(head, a);
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