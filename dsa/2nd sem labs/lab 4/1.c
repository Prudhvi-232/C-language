#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coefficient;
    int power;
    struct Node*rlink;
};
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
struct Node*createnode(int coefficient,int power){
    struct Node*s= (struct Node*) malloc(sizeof(struct Node));
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

int main(){
    struct Node*t1=NULL;
    struct Node*t2=NULL;
    struct Node*t3=NULL;
    insert(&t1,5,8);
    insert(&t1,15,6);
    insert(&t1,7,4);
    insert(&t1,22,3);
    insert(&t1,12,1);
    insert(&t1,29,0);
    insert(&t2,5,8);
    insert(&t2,13,7);
    insert(&t2,15,6);
    insert(&t2,16,5);
    insert(&t2,22,3);
    insert(&t2,45,0);
    while (t1 != NULL && t2 != NULL) {
        if(t1->power>t2->power){
            t1=t1->rlink;
        }else if(t1->power<t2->power){
            t2=t2->rlink;
        }else if(t1->coefficient==t2->coefficient && t1->power==t2->power){
            insert(&t3,t2->coefficient,t2->power);
            t1=t1->rlink;
            t2=t2->rlink;
        }
        }
    display(t3);
}

