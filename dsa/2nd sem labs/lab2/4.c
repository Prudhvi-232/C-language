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
struct node* nodetodelete(struct node*head,int value) {
    struct node*current=head;
    struct node*prev=NULL;
    while(current!=NULL && current->d!=value){
        prev=current;
        current=current->next;
    }
    if(current!=NULL){
        if(prev==NULL){
            head=current->next;
        }else{
            prev->next=current->next;
        }
        free(current);
        printf("%d deleted\n", value);
    } else{
        printf("%d not found\n", value);
    }
    return head;
}
int main(){
    int N,i,k,x;
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
    printf("value to delete from the list: ");
    scanf("%d",&x);
    head=nodetodelete(head,x);
    printf("updated list: ");
    print(head);
    while(head!= NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}