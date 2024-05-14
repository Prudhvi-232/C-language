#include <stdio.h>
#include <stdlib.h>

struct Node{
    int va;
    struct Node*next;
    struct Node*prev;
};
struct Node*insert(struct Node*ta,int va){
    struct Node*s=(struct Node*)malloc(sizeof(struct Node));
    s->va=va;
    if(ta==NULL){
        s->next=s;
        s->prev=s;
        ta=s;
    }else{
        s->next=ta->next;
        s->prev=ta;
        ta->next->prev=s;
        ta->next=s;
    }
    return s;
}
void display(struct Node*ta){
    struct Node*cur;
    if(ta==NULL){
        printf("List is empty.\n");
        return;
    }
    cur=ta->next;
    do{
        printf("%d ",cur->va);
        cur=cur->next;
    } while(cur!=ta->next);
}
int main(){
    struct Node*ta=NULL;
    int va,size;
    printf("entersize of the linked list  ");
    scanf("%d",&size);
    for(int i=0;i<size;++i){
        printf("Enter value %d ",i + 1);
        scanf("%d",&va);
        ta=insert(ta,va);
    }
    printf("circular linked list is ");
    display(ta);
    return 0;
}