#include<stdio.h>
#include<stdlib.h>
#define size 5

int stack[size];
int top=-1;
void push(){
    if(top==size-1){
        printf("stack is full");
    }else {
        int value ;
        printf("enter value");
        scanf("%d",value);
        top++;
        stack[top]=value;
        printf("pushed successfully");        
    }

}
void pop(){
    if(top==-1){
        printf("stack is empty");
    }else{
        top--;
        printf("popped successfully");
    }
}
void peek(){
    if(top==-1){
        printf("stack is empty");
    }else {
        printf("peek value is %d",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("stack is empty");
    }else {
        int i=0;
        for(i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
    }
}



int main(){
    printf("stack implementation");
    while (1)
    {
        int option;
        printf("choose optio\n1 push\n2 pop\n 3 peek\n4 display\n5 exit");
        if(option==1){
            push();
        }
        else if(option==2){
            pop();
        }
        else if(option==3){
            peek();
        }
        else if(option==4){

        }
        else break;
    }
    


    return 0;
}