#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dat;
    struct Node*rnode;
    struct Node*lnode;
};
struct Node*createnode(int dat){
    struct Node*s=(struct Node*)malloc(sizeof(struct Node));
    s->dat=dat;
    s->rnode=NULL;
    s->lnode=NULL;
    return s;
}
void insert(struct Node**hea,int dat){
    struct Node*s=createnode(dat);
    if(*hea==NULL){
        *hea=s;
        (*hea)->rnode=*hea;
        (*hea)->lnode=*hea;
    }else{
        struct Node*last=(*hea)->lnode;
        last->rnode=s;
        s->lnode=last;
        s->rnode=*hea;
        (*hea)->lnode=s;
    }
}
void delete(struct Node**hea,int x,int y){
    if(*hea==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node*cur=*hea;
    struct Node*tem=NULL;
    while (cur->rnode!=*hea){
        if(cur->dat>=x&&cur->dat<=y){
            if(cur==*hea){
                *hea=(*hea)->rnode;
            }
            tem=cur->lnode;
            tem->rnode=cur->rnode;
            cur->rnode->lnode=tem;
            free(cur);
            cur=tem->rnode;
        }else{
            cur=cur->rnode;
        }
    }
    if(cur->dat>=x&&cur->dat<=y){
        if(cur==*hea){
            *hea=NULL;
        }
        tem=cur->lnode;
        tem->rnode=cur->rnode;
        cur->rnode->lnode=tem;
        free(cur);
    }
}
void display(struct Node*hea){
    if(hea==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node*tem=hea;
    do {
        printf("%d",tem->dat);
        tem=tem->rnode;
    } while(tem!=hea);
    printf("\n");
}
int main(){
    struct Node*hea=NULL;
    int n,dat,x,y;
    printf("no of elements in the list");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter %d element",i);
        scanf("%d",&dat);
        insert(&hea,dat);
    }
    printf("range of x,y to delete elements from x to y");
    scanf("%d %d",&x,&y);
    printf("list before deleting ");
    display(hea);
    delete(&hea,x,y);
    printf("list after deleting ");
    display(hea);
    return 0;
}