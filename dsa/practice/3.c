#include <stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void insertbegin(){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("enter the number to insert");
    scanf("%d", &item);
    if(head == NULL){
        head = ptr;
        ptr->next = head;
        ptr->data= item;
    }
    else{
        ptr->data = item;
        temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        ptr->next = head;
        temp->next=ptr;
        head = ptr;
    }
}

void begindelete(){
    struct node *ptr;   
    if(head->next==NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr->next!=head){
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
    }
}

void lastdelete(){
    struct node *ptr,*ptr1;
    ptr = head;
    if(head->next==NULL){
        head = NULL;
        free(head);
    }
    else {
        while(ptr->next!=NULL){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        // ptr=NULL;
        free(ptr);
    }

}
int main(){

}