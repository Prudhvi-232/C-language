#include <stdio.h>
#include<stdlib.h>

struct node {
    int coefficient;
    int power;
    struct node*link;
};
int main(){
    struct node *h1=NULL,*h2=NULL,*h3=NULL;
    struct node *t1,*t2,*t3,*s;
    int num1,num2;
    printf("enter the no of terms in 1st equation");
    scanf("%d",&num1);
    for(int i=1;i<=num1;i++){
        s=(struct node*)malloc(sizeof(struct node*));
        printf("Enter coeffient of %d\n",i);
        scanf("%d",&s->coefficient);

        printf("Enter power for %d\n",i);
        scanf("%d",&s->power);
        s->link = NULL;

        if(h1==NULL){
            h1 = s;
            t1 = s;
        }
        else{
            t1->link = s;
            t1 = s;
        }
    }
    printf("enter the no of terms in 2st equation");
    scanf("%d",&num2);
    for(int i=1;i<=num2;i++){
        s=(struct node*)malloc(sizeof(struct node*));
        printf("Enter coeffient of %d\n",i);
        scanf("%d",&s->coefficient);

        printf("Enter power for %d\n",i);
        scanf("%d",&s->power);
        s->link = NULL;

        if(h2==NULL){
            h2 = s;
            t2 = s;
        }
        else{
            t2->link = s;
            t2 = s;
        }
    }
    t1=h1;
    t2=h2;
    while(t1!=NULL && t2!=NULL){
        if(t1->power > t2->power){
            s=(struct node*)malloc(sizeof(struct node*));
            s->coefficient = t1->coefficient;
            s->power = t1->power;
            s->link = NULL;
            if(h3==NULL){
                h3 = s;
                s->link=NULL;
            }else{
                t3->link = s;
                s->link=NULL;
                t3 = s;
            }
            t1=t1->link;
        }
        else if(t1->power==t2->power){
            s=(struct node*)malloc(sizeof(struct node*));
            s->coefficient = t1->coefficient+t2->coefficient;
            s->power = t1->power;
            s->link = NULL;
            if(h3==NULL){
                h3 = s;
                s->link=NULL;
            }
            else{
                t3->link = s;
                s->link=NULL;
                t3 = s;
            }
            t1=t1->link;
            t2=t2->link;
        }
        else{
            s=(struct node*)malloc(sizeof(struct node*));
            s->coefficient = t2->coefficient;
            s->power = t2->power;
            s->link = NULL;
            if(h3==NULL){
                h3 = s;
                s->link=NULL;
            }
            else{
                t3->link = s;
                s->link=NULL;
                t3 = s;
            }
            t2=t2->link;
        }
    }
    t3=h3;
    while (t3!=NULL){
        printf("%d x %d+\n",t3->coefficient,t3->power);
        t3=t3->link;
    }
    









    return 0;
}