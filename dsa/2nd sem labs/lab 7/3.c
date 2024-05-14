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
struct Node* insert_element(struct Node* root, int item) {
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->lnode = insert_element(root->lnode, item);
    else
        root->rnode = insert_element(root->rnode, item);
    return root;
}

void In_order(struct Node *root) {
    if (root == NULL)
        return;
    In_order(root->lnode);
    printf("%d   ", root->data);
    In_order(root->rnode);
}

struct Node* min(struct Node* node) {
    struct Node* cur = node;
    while (cur && cur->lnode != NULL)
        cur = cur->lnode;
    return cur;
}

void delete_node(struct Node **root, int item) {
    struct Node *par = NULL;
    struct Node *cur = *root;
    while (cur != NULL && cur->data != item) {
        par = cur;
        if (item < cur->data)
            cur = cur->lnode;
        else
            cur = cur->rnode;
    }
    if (cur == NULL)
        return;
    if (cur->lnode == NULL && cur->rnode == NULL) {
        if (par != NULL) {
            if (par->lnode == cur)
                par->lnode = NULL;
            else
                par->rnode = NULL;
        } else {
            *root = NULL;
        }
        free(cur);
    }
    else if (cur->lnode && cur->rnode) {
        struct Node* suc = min(cur->rnode);
        cur->data = suc->data;
        delete_node(&cur->rnode, suc->data);
    }
    else {
        struct Node* children = (cur->lnode != NULL) ? cur->lnode : cur->rnode;
        if (par != NULL) {
            if (cur == par->lnode)
                par->lnode = children;
            else
                par->rnode = children;
        } else {
            *root = children;
        }
        free(cur);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert_element(root, 25);
    root = insert_element(root, 30);
    root = insert_element(root, 40);
    root = insert_element(root, 23);
    root = insert_element(root, 31);
    root = insert_element(root, 42);
    printf("BST before deletion\n");
    In_order(root);

    int d;
    printf("\nenter a element from above BST to delete: ");
    scanf("%d", &d);
    delete_node(&root, d);

    printf("\nBST after deleting number %d:\n", d);
    In_order(root);

    return 0;
}
