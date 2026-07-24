#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    TreeNode* root = NULL;

    printf("1.插入节点\n");
    printf("2.前序遍历打印\n");
    printf("3.中序遍历打印\n");
    printf("4.后序遍历打印\n");
    printf("5.层序遍历打印\n");
    printf("6.统计节点总数\n");
    printf("7.求树的高度\n");
    printf("8.查找值是否存在\n");
    printf("9.判断该树是否为合法二叉搜索树\n");
    while(1){
        int choice, value, num, data;

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
            preorderprint(root);
            printf("\n");
            break;

        case 3:
            inorderprint(root);
            printf("\n");
            break;

        case 4:
            postorderprint(root);
            printf("\n");
            break;

        case 5:
            levelorderPrint(root);
            printf("\n");
            break;

        case 6:
            printf("节点总数为：%d\n", countNodes(root));
            break;

        case 7:
            printf("树的高度为；%d\n", getHeight(root));
            break;
            
        case 8:
            printf("请输入查找值：");
            scanf("%d", &data);
            if(search(root, data) == NULL){
                printf("该值不存在！\n");
            }else{
                printf("该值存在！\n");
            }
            break;

        case 9:
            isValidBST(root);
            break;

        default:
            break;
        }
    }

    return 0;
}