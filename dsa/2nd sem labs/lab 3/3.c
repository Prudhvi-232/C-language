#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*rnode;
    struct node*lnode;
};
struct doublellinkedlist{
    struct node*h;
};
void append(struct doublellinkedlist*list,int data) {
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
void display(struct doublellinkedlist*list){
    struct node*cur=list->h;
    while(cur){
        printf("%d ",cur->data);
        cur=cur->rnode;
    }
}
int main(){
    struct doublellinkedlist list={NULL};
    int n;
    printf("size of the linked list");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int data;
        printf("enter %d element : ",i+1);
        scanf("%d",&data);
        append(&list,data);
    }
    printf("list has been created\n");
    display(&list);
    return 0;
}