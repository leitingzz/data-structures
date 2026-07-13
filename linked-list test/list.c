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
    while(temp->data != value && temp != NULL){
        temp = temp->next;
    }
    return temp;
}

Node* searchByLocate(Node* head, int locate){
    Node*temp = head;
    if(locate == 1){
        return temp;
    }else{
        for(int i = 1; i < locate; i++){
            temp = temp->next;
        }
    }
    return temp;
}

Node* insert(Node* head, int num){
    int data, locate;
    printf("请输入插入数据：");
    scanf("%d", &data);
    printf("请输入插入位置：");
    scanf("%d", &locate);
    Node* newNode = createNode(data);
    Node* temp = NULL;
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

Node* delete(Node* head, int a){
    Node* temp = head;
    Node* prev = NULL;
    while(temp->data != a && temp != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = head->next;
        free(temp);
        printf("删除完成！\n");
        
    }else if(temp == NULL){
        printf("该值不存在！\n");
    }else{
        prev->next = temp->next;
        free(temp);
        printf("删除完成！\n");
    }
    return head;
}