#include <stdio.h>
#include <stdlib.h> 
#define SIZE 100 
struct node{
    int top;
    int datacollection[SIZE];
};
void push(struct node*s,int data){
    if(s->top==SIZE-1){ 
        printf("stack is full\n");
        exit(1); 
    }else{
        s->top++;
        s->datacollection[s->top]=data;
    }
}
void pop(struct node*s){
    if(s->top==-1){ 
        printf("stack is empty\n");
        exit(1); 
    }else{
        int x=s->datacollection[s->top];
        printf("%d deleted\n",x);
        s->top--;
    }
}
int main()
{
    int n;
    printf("the no of operations you want");
    scanf("%d",&n);
    struct node stack;
    stack.top=-1;
    while (n--)
    {
        int ch,input;
        printf("Enter the operation (1 for push, 2 for pop, 3 for display): ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter a num to push");
            scanf("%d",&input);
            push(&stack,input);
        }
        else if(ch==2)
        {
            pop(&stack);
        }
        else if(ch==3)
        {
            for(int i=0;i<=stack.top;i++)
            {
                printf("%d ",stack.datacollection[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
