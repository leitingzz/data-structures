#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int hashFunc(int data){
    int a;
    a = data % 10;
    if(a < 0){
        a += NUM;
    }
    return a;
}

void insert(Node* hash_table[]){
    int data, a;
    printf("请输入插入数据；");
    scanf("%d", &data);
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode->data = data;
    a = hashFunc(data);
    newNode->next = hash_table[a];
    hash_table[a] = newNode;
    return;
}

void search(Node* hash_table[]){
    int data, a;
    printf("请输入查找数据：");
    scanf("%d", &data);
    a = hashFunc(data);
    Node* temp = hash_table[a];
    while(temp != NULL){
        if(data == temp->data){
            printf("该数据存在！\n");
            return;
        }else{
            temp = temp->next;
        }
    }
    printf("该数据不存在！\n");
    return;

}

void delete(Node* hash_table[]){
    int data, a;
    printf("请输入的删除数据：");
    scanf("%d", &data);
    a = hashFunc(data);
    Node* prev = NULL;
    Node* curr = hash_table[a];
    if(hash_table[a] == NULL){
        printf("该数据不存在！\n");
        return;
    }
    if(hash_table[a]->data == data){
        hash_table[a] = hash_table[a]->next;
        free(curr);
        printf("删除完成！\n");
        return;
    }
    while(curr != NULL){
        if(curr->data == data){
            prev->next = curr->next;
            free(curr);
            printf("删除完成！\n");
            return;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    printf("该数据不存在！\n");
    return;
}

void printHashTable(Node* hash_table[]){
    for(int i = 0; i < NUM; i++){
        printf("格子%d:", i);
        if (hash_table[i] == NULL){
            printf("空\n");
        }else{
            Node* temp = hash_table[i];
            while(temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    return;
}