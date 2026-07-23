#if !defined(TREE_H)
#define TREE_H

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct queue{
    TreeNode* node;
    struct queue* next;
}queue;

TreeNode* insert(TreeNode* root, int value);
void inorderprint(TreeNode* root);
void preorderprint(TreeNode* root);
void postorderprint(TreeNode* root);
void enqueue(queue** head, queue** tail, TreeNode* node);
TreeNode* dequeue(queue** head, queue** tail);
void levelorderPrint(TreeNode* root);
int countNodes(TreeNode* root);
int getHeight(TreeNode* root);
TreeNode* search(TreeNode* root, int value);
#endif