#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;   
    return newNode;
}

void freeList(Node* head){
    Node* temp = head;
    Node* next;
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
}

Node* searchByValue(Node* head, int value){
    Node* temp = head;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }
    return temp;
}

void searchByLocate(Node* head, int num){
    if(head == NULL){
        printf("链表为空，请先建立链表！\n");
        return;
    }
    Node*temp = head;
    int locate;
    printf("请输入查询节点位置：");
    scanf("%d", &locate);
    while(locate > num || locate < 1){
        printf("该位置超出链表范围，请重新输入！\n");
        scanf("%d", &locate);
    }
    if(locate == 1){
        printf("%d\n", head->data);
    }else{
        for(int i = 1; i < locate; i++){
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

Node* insert(Node* head, int num, Node** tail){
    int data, locate;
    printf("请输入插入数据：");
    scanf("%d", &data);
    printf("请输入插入位置：");
    scanf("%d", &locate);
    Node* newNode = createNode(data);
    Node* temp = NULL;
    
    while(locate < 1 || locate > (num + 1)){
        printf("该位置超出范围,请重新输入！\n");
        scanf("%d", &locate);
    }
    
    if(locate == (num + 1)){
        *tail = newNode;
    }

    if(locate == 1){
        newNode->next = head;
        return newNode;
    }else{
        temp = head;
        for(int i = 2; i < locate; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

}

Node* delete(Node* head, int a, Node** tail, int*num){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL && temp->data != a){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
    printf("该值不存在！\n");
    }else if(temp == head){
        head = head->next;
        free(temp);
        printf("删除完成！\n");
        (*num)--;
        if(*num == 0){
            *tail = NULL;
        }
        
    }else if(temp == *tail){
        *tail = prev;
     
        free(temp);
        temp = NULL;
        printf("删除完成！\n");
        (*num)--;
    }else{
        prev->next = temp->next;
        free(temp);
        printf("删除完成！\n");
        (*num)--;
    }
    return head;
}   

Node* reverseList(Node* head){
    if(head == NULL){
        printf("链表为空！\n");
        return head;
    }else{
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head->next;
        curr->next = prev;
        while(next != NULL){
            prev = curr;
            curr = next;
            next = curr->next;
            curr->next = prev;
        }
        printf("链表完成反转！\n");
        return curr;
    }
}