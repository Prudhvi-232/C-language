#include <stdio.h>
#include <stdlib.h>

struct Node{
    char dat;
    struct Node*rnode;
    struct Node*lnode;
};
struct Node*createnode(char dat){
    struct Node*s = (struct Node*)malloc(sizeof(struct Node));
    s->dat=dat;
    s->rnode=NULL;
    s->lnode=NULL;
    return s;
}
void insert(struct Node**head,char dat){
    struct Node*s=createnode(dat);
    if(*head==NULL){
        *head=s;
    }else{
        struct Node*current=*head;
        while(current->rnode!=NULL){
            current=current->rnode;
        }
        current->rnode=s;
        s->lnode=current;
    }
}

int palindromeornot(struct Node*head){
    struct Node*fr = head,*re=head;

    while(re&&re->rnode){
        re=re->rnode;
    }
    while(fr&&re){
        if (fr->dat!=re->dat){
            return 0; // Not a palindrome
        }
        fr=fr->rnode;
        re=re->lnode;
    }
    return 1; // It is a palindrome
}

void display(struct Node*head){
    while(head!=NULL){
        printf("%c",head->dat);
        head=head->rnode;
    }
    printf("\n");
}
int main(){
    struct Node*head=NULL;
    int n;printf("enter no of elements in the linked list:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char a;
        printf("enter %d character",i);
        scanf(" %c",&a);
        insert(&head,a);
    }
    printf("Doubly Linked List is ");
    display(head);
    if(palindromeornot(head)){
        printf("list is a palindrome.\n");
    }else{
        printf("list is not a palindrome.\n");
    }
    return 0;
}
