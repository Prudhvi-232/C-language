#include<stdio.h>
#include<stdlib.h>
struct node{
    int d;
    struct node*next;
};
struct node*createnode(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=value;
    newnode->next=NULL;
    return newnode;    
}
void print(struct node*a){
    struct node*b=a;
    while(b!=NULL){
        printf("%d ",b->d);
        b=b->next;
    }
    printf("\n");
}
struct node*insertend(struct node*head,int val){
    struct node*newnode=createnode(val);
    if(head==NULL){
        return newnode;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
int main(){
    int N,i,k,l,a,b,c;
    printf("number of nodes intially\n");
    scanf("%d",&N);
    struct node*head=NULL;
    struct node*temp;
    for(i=0;i<N;i++){
        printf("enter %d value: ",i+1);
        scanf("%d",&k);
        temp=createnode(k);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    printf("elements in linked list are\n");
    print(head);
    printf("enter 3 numbers to end\n");
    scanf("%d %d %d",&a,&b,&c);
    head=insertend(head,a);
    head=insertend(head,b);
    head=insertend(head,c);
    printf("updated list: ");
    print(head);
    while(head!= NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}