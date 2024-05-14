#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coefficient;
    int power;
    struct Node*rlink;
};

struct Node*createnode(int coefficient,int power){
    struct Node*s = (struct Node*)malloc(sizeof(struct Node));
    s->coefficient=coefficient;
    s->power=power;
    s->rlink=NULL;
    return s;
}
void insert(struct Node**poly,int coefficient,int power){
    struct Node*s=createnode(coefficient,power);
    if(*poly==NULL){
        *poly=s;
    }else{
        struct Node*cur=*poly;
        while(cur->rlink!=NULL){
            cur=cur->rlink;
        }
        cur->rlink=s;
    }
}
void display(struct Node*poly){
    while(poly!=NULL){
        printf("%dx^%d",poly->coefficient,poly->power);
        poly=poly->rlink;
        if(poly!=NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node*addpolynomial(struct Node*t1,struct Node*t2){
    struct Node*t3=NULL;
    struct Node*cur=NULL;
    while (t1!=NULL||t2!=NULL){
        struct Node*s=createnode(0,0);
        if(t1==NULL){
            s->coefficient=t2->coefficient;
            s->power=t2->power;
            t2=t2->rlink;
        }else if(t2==NULL){
            s->coefficient=t1->coefficient;
            s->power=t1->power;
            t1=t1->rlink;
        }else{
            if(t1->power>t2->power){
                s->coefficient=t1->coefficient;
                s->power=t1->power;
                t1=t1->rlink;
            }else if(t2->power>t1->power){
                s->coefficient=t2->coefficient;
                s->power=t2->power;
                t2=t2->rlink;
            }else{
                s->coefficient=t1->coefficient+t2->coefficient;
                s->power=t1->power;
                t1=t1->rlink;
                t2=t2->rlink;
            }
        }
        if (t3==NULL) {
            t3=s;
            cur=t3;
        }else{
            cur->rlink=s;
            cur=cur->rlink;
        }
    }

    return t3;
}

int main(){
    struct Node*t1=NULL;
    struct Node*t2=NULL;

    insert(&t1,5,8);
    insert(&t1,15,6);
    insert(&t1,7,4);
    insert(&t1,22,2);
    insert(&t1,12,1);
    insert(&t1,29,0);
    insert(&t2,32,8);
    insert(&t2,13,7);
    insert(&t2,18,6);
    insert(&t2,16,5);
    insert(&t2,22,3);
    insert(&t2,45,0);

    printf("1st polynomial is ");
    display(t1);
    printf("2nd polynomial is ");
    display(t2);
    struct Node*result=addpolynomial(t1,t2);
    printf("relust is");
    display(result);
    return 0;
}