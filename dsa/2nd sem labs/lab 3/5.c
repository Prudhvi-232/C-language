#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *rnode;
    struct Node *lnode;
};
struct doublelinkedlist
{
    struct Node *head;
};
void deleteNode(struct Node **headRef, int key)
{
    struct Node *temp = *headRef, *lnode;
    while (temp != NULL && temp->data == key)
    {
        *headRef = temp->rnode;
        if (*headRef != NULL)
            (*headRef)->lnode = NULL;
        free(temp);
        temp = *headRef;
    }
    while (temp != NULL)
    {
        while (temp != NULL && temp->data != key)
        {
            lnode = temp;
            temp = temp->rnode;
        }
        if (temp == NULL)
            return;
        lnode->rnode = temp->rnode;
        if (temp->rnode != NULL)
            temp->rnode->lnode = lnode;
        free(temp);
        temp = lnode->rnode;
    }
}

void append(struct doublelinkedlist *list, int data)
{
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    s->data = data;
    s->rnode = NULL;
    s->lnode = NULL;
    if (!list->head)
    {
        list->head = s;
    }
    else
    {
        struct Node *current = list->head;
        while (current->rnode)
        {
            current = current->rnode;
        }
        current->rnode = s;
        s->lnode = current;
    }
}
void display(struct doublelinkedlist *list)
{
    struct Node *cur = list->head;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->rnode;
    }
}
int main()
{
    struct doublelinkedlist list = {NULL};
    int N;
    printf("Enter the size of the double linked list: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int data;
        printf("Enter the data element for node %d: ", i + 1);
        scanf("%d", &data);
        append(&list, data);
    }

    printf("Created double linked list:\n");
    display(&list);
    int a;
    printf("enter a element to delete");
    scanf("%d", &a);
    deleteNode(&list.head, a);
    display(&list);

    return 0;
}
