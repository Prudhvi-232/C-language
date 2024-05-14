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
    int n;
    printf("enter the no of elements you want to enter: ");
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        int a;
        scanf("%d", &a);
        root=insertion(root, a);
    }
    printf("inorder traversal of entered elements in binary tree\n");
    In_order(root);
    return 0;
}
