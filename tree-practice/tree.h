#if !defined(TREE_H)
#define TREE_H

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* insert(TreeNode* root, int value);
void inorderprint(TreeNode* root);

#endif