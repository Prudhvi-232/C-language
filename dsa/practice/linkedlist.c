#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};
struct node *top = NULL;
void push(int value){
    struct node*temp = (struct node*)malloc(sizeof(struct node*));
    temp->data=value;
    temp->link=NULL;
    if(top==NULL){
        top=temp;
    }else{
        temp->link=top;
        top=temp;
    }
    printf("value pushed susseffully");
}

void pop(){
    if(top==NULL){
        printf("stack is empty");
    }else {
        struct node*p=top;
        top=top->link;
        p->link=NULL;
        printf("value popped sussfully");
    }
}
void peek(){
    if(top==NULL){
        printf("stack is empty");
    }else {
        printf("peek value is %d",top->data);
    }
}
void display(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        
    }
}
int main(){
    

    return 0;
}