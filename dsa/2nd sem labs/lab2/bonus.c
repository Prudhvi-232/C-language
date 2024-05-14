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
    int N,i,k,m,num;
    printf("Enter the number of nodes\n");
    scanf("%d",&N);
    struct node*head=NULL;
    struct node*temp;
    for(i=0;i<N;i++){
        printf("Enter the %d value: ",i+1);
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
    printf("enter\n1 to insert a node\n2 to delete a node\n3 to display elements\n0 to exit\n");
    scanf("%d",&num);
    while(num!=0){
        if(num==1){
            printf("enter value to insert in list\n");
            scanf("%d",&m);
            temp=createnode(m);
            temp->next=head;
            head=temp;
            printf("updated list: ");
            print(head);
            printf("\n");
            printf("enter 1 to insert a node\n2 to delete a node\n3 to display elements\n0 to exit");
            scanf("%d",&num);
        }
        else if(num==2){
            printf("enter value to delete in list\n");
            scanf("%d",&m);
            head=nodetodelete(head,m);
            printf("updated list: ");
            print(head);
            printf("\n");
            printf("enter 1 to insert a node\n2 to delete a node\n3 to display elements\n0 to exit");
            scanf("%d",&num);
        }
        else if(num==3){
            printf("linked list elements are\n");
            print(head);
            printf("\n");
            printf("enter 1 to insert a node\n2 to delete a node\n3 to display elements\n0 to exit");
            scanf("%d",&num);
        }
        else {
            printf("enter 1 to insert a node\n2 to delete a node\n3 to display elements\n0 to exit");
            scanf("%d",&num);
        }
    }
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
