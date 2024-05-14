#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation not suuccesfull\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    int spaces = 5; 
    printTree(root->right, level + 1);
    printSpaces(level * spaces);
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->left->left=createNode(10);
    root->left->left->right=createNode(11);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Binary tree structure:\n");
    printTree(root, 0);

    free(root->left->right);
    free(root->left->left);
    free(root->right->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}