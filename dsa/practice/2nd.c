#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *rnode;
    struct node *lnode;
};
void insertatbegin();
struct node *head,*temp;
int main(){
    insertatbegin();

    return 0;
}
void insertatbegin(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("enter the item");
    scanf("%d", &item);
    if(head == NULL){
        ptr->rnode = NULL;
        ptr->lnode = NULL;
        head = ptr;
        ptr->data = item;
    }
    else{
        ptr->lnode = NULL;
        ptr->rnode = head;
        ptr->data = item;
        head->lnode = ptr;
        head = ptr;
    }
}

void insertatend(){
    struct node *temp,*ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("enter the element");
    scanf("%d", &item);
    temp = head;
    while(temp->rnode != NULL){
        temp = temp->rnode;
    }
    if(head==NULL){
        ptr->data = item;
        ptr->rnode = NULL;
        ptr->lnode = NULL;
        head = ptr; 
    }else{
        ptr->data = item;
        ptr->rnode = NULL;
        ptr->lnode = temp;
        temp->rnode = ptr;
    }
}
void insertatmiddile(){
    struct node *ptr, *temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    int pos, item;
    printf("enter the item to insert");
    scanf("%d", &item);
    printf("enter position to insert");
    scanf("%d", &pos);
    temp = head;
    for (int i = 0; i < pos;i++){
        temp = temp->rnode;

    }
    ptr->data = item;
    ptr->rnode = temp->rnode;
    ptr->lnode = temp;
    temp->rnode = ptr;
    temp->rnode->lnode = ptr;

}

void firstdelete(){
    struct node *ptr;
    if(head->rnode==NULL){
        head = NULL;
        free(head);

    }   
    else{
        ptr = head;
        head = head->rnode;
        head->lnode = NULL;
        free(ptr);
    } 
}
void deletelast(){
    struct node *temp,*ptr;
    if(head->rnode==NULL){
        temp = head;
        head = NULL;
        free(temp);
    }
    else{
        ptr = head;
        while(ptr->rnode!=NULL){
            ptr = ptr->rnode;

        }
        ptr->lnode->rnode=NULL;
        free(ptr);
    }
}
void display(){
    struct node *ptr;
    // ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    while(ptr!=NULL){
        printf("%d", ptr->data);
        ptr = ptr->rnode;
    }
}