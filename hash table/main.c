#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
    Node* hash_table[NUM];
    for(int i = 0; i < 10; i++){
        hash_table[i] = NULL;
    }

    printf("1.插入数据\n");
    printf("2.查找数据\n");
    printf("3.删除数据\n");
    printf("4.打印哈希表\n");

    while(1){ 
        int choice;
        printf("请选择功能：");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            insert(hash_table);
            printf("插入完成！\n");
            break;

            case 2:
            search(hash_table);
            break;

            case 3:
            delete(hash_table);
            break;

            case 4:
            printHashTable(hash_table);
            break;

            default:
            break;
        }
    }
}