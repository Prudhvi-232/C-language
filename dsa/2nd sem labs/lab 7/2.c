#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lnode, *rnode;
};
struct Node* create(int item) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node != NULL) {
        node->data = item;
        node->lnode = node->rnode = NULL;
    }
    return node;
}

struct Node* insertion(struct Node* root, int item) {
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->lnode = insertion(root->lnode, item);
    else
        root->rnode = insertion(root->rnode, item);
    return root;
}
void In_order(struct Node *root) {
    if (root == NULL)
        return;
    In_order(root->lnode);
    printf("%d   ", root->data);
    In_order(root->rnode);
}


int main() {
    struct Node* root = NULL;
    root = insertion(root, 25);  
    root = insertion(root, 30);  
    root = insertion(root, 40);  
    root = insertion(root, 23);  
    root = insertion(root, 31);  
    root = insertion(root, 42);  
    In_order(root);
    int a;
    printf("\nenter a element to insert in BST: ");
    scanf("%d", &a);
    root=insertion(root, a);
    printf("inorder traversal of entered elements in binary tree\n");
    In_order(root);
    return 0;
}
