#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node*rnode;
};
int main(){
    int n,x,y;
    struct node *f,*t,*s,*cur,*pre;
    f=(struct node*)malloc(sizeof(struct node));
    printf("enter no of nodes");
    scanf("%d", &n);
    printf("enter data for 1 ");
    scanf("%d",&x);
    f->data=x;
    f->rnode=NULL;
    t=f;
    for (int i=1;i<n;i++){
        s=(struct node*)malloc(sizeof(struct node));
        printf("enter data for %d ",i+1);
        scanf("%d",&y);
        s->data=y;
        s->rnode=NULL;
        t->rnode=s;
        t=t->rnode;
    }
    t->rnode=f;
    t=f;
     while (t!=NULL) {
        cur=t->rnode;
        pre=t;
        while (cur!=f) {
            if (cur->data==t->data) {
                pre->rnode=cur->rnode;
                free(cur);
                cur=pre->rnode;
            } else {
                pre=cur;
                cur=cur->rnode;
            }
        }
        t=t->rnode;
        if (t==f) {
            break;
        }
    }
    t=f;
    while(t->rnode!=f){
    printf("%d->",t->data);
    t=t->rnode;
    }
    printf("%d",t->data);
}