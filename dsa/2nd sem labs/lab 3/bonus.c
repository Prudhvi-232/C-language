#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*rnode;
    struct Node*lnode;
};
struct doublelinkedlist{
    struct Node*head;
};
void delete(struct Node**headRef,int key){
    struct Node*temp=*headRef,*lnode;
    while (temp!=NULL&&temp->data==key) {
        *headRef=temp->rnode; 
        if(*headRef!=NULL)
            (*headRef)->lnode=NULL;
        free(temp);               
        temp=*headRef;
    }
    while(temp!=NULL){
        while(temp!=NULL&&temp->data!=key){
            lnode=temp;
            temp=temp->rnode;
        }
        if(temp==NULL)return;
        lnode->rnode=temp->rnode;
        if(temp->rnode!=NULL)
            temp->rnode->lnode=lnode;

        free(temp); 
        temp=lnode->rnode;
    }
}

void append(struct doublelinkedlist*list,int data) {
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    s->data = data;
    s->rnode = NULL;
    s->lnode = NULL;

    if (!list->head) {
        list->head = s;
    } else {
        struct Node* cur = list->head;
        while (cur->rnode) {
            cur = cur->rnode;
        }
        cur->rnode = s;
        s->lnode = cur;
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

void insertatend(struct Node** head, int data) {
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    s->data = data;
    s->lnode = NULL;
    s->rnode = NULL;
    if (*head == NULL) {
        *head = s;
        return;
    }
    struct Node* last = *head;
    while (last->rnode != NULL) {
        last = last->rnode;
    }
    last->rnode = s;
    s->lnode = last;
}
int main()
{
    struct doublelinkedlist list = {NULL};
    int N;
    printf("size of linked list ");
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
    int a,z=1;
    while(z){
        printf("enter 1 for insert a element\n2 for delete\n3 for display elements\nenter anything for exit\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter a element to insert");
            int q;
            scanf("%d", &q);
            insertatend(&list, q);
        }
        else if (a == 2)
        {
            printf("enter a element to delete");
            int r;
            scanf("%d", &r);
            delete(&list, r);
        }
        else if (a == 3)
        {
            display(&list);
        }else{
            z=0;
        }
    }

    return 0;
}