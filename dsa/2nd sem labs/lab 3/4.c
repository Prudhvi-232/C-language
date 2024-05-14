#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*rnode;
    struct node*lnode;
};

struct linkedlist{
    struct node*h;
};
void append(struct linkedlist*list,int data){
    struct node*s=(struct node*)malloc(sizeof(struct node));
    s->data=data;
    s->rnode=NULL;
    s->lnode=NULL;
    if(!list->h){
        list->h=s;
    }else{
        struct node*cur=list->h;
        while(cur->rnode){
            cur=cur->rnode;
        }
        cur->rnode=s;
        s->lnode=cur;
    }
}
void display(struct linkedlist*list) {
    struct node*cur=list->h;
    while(cur){
        printf("%d ",cur->data);
        cur=cur->rnode;
    }
}
void insertatend(struct node**h,int data){    
    struct node*s=(struct node*)malloc(sizeof(struct node));
    s->data=data;
    s->lnode=NULL;
    s->rnode=NULL;
    if(*h==NULL){
        *h=s;
        return;
    }
    struct node*last=*h;
    while(last->rnode!=NULL){
        last=last->rnode;
    }
    last->rnode=s;
    s->lnode=last;
}
int main()
{
    struct linkedlist list={NULL};
    int n;
    printf("size of the linked list");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int data;
        printf("enter %d element: ", i + 1);
        scanf("%d",&data);
        append(&list,data);
    }
    printf("list has been created\n");
    display(&list);
    int a,b,c;
    printf("enter 3 numbers to insert at end of linkedlist\n");
    scanf("%d %d %d",&a,&b,&c);
    insertatend(&list.h,a);
    insertatend(&list.h,b);
    insertatend(&list.h,c);
    display(&list);
    return 0;
}