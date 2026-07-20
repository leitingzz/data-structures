#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    TreeNode* root = NULL;

    printf("1.插入节点\n");

    while(1){
        int choice, value, num;

        printf("请选择功能：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入插入节点个数；");
            scanf("%d", &num);
            printf("请输入节点数据；");
            for(int i = 0; i < num; i++){
                scanf("%d", &value);              
                root = insert(root, value);
            }
            printf("插入完成！\n");
            break;
        
        case 2:
            inorderprint(root);
            break;

        default:
            break;
        }
    }

}