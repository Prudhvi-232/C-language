#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct{
  int items[MAX_SIZE];
  int start,end;
}cqueue;

int isfull(cqueue *q){
  return (q->end + 1)%MAX_SIZE==q->start;
}
int isempty(cqueue *q) {
  return q->start==-1&&q->end==-1;
}
int enq(cqueue *q,int val){
  if (isfull(q)){
    return 0;
  }
  if(isempty(q)){
    q->start = q->end = 0;
  }else{
    q->end=(q->end+1)%MAX_SIZE;
  }
  q->items[q->end]=val;
  return 1;
}
int deq(cqueue *q){
  if(isempty(q)){
    return -1;
  }
  int removed=q->items[q->start];
  if (q->start==q->end){
    q->start=q->end=-1;
  }else{
    q->start=(q->start+1)%MAX_SIZE;
  }
  return removed;
}

void print_elements(cqueue *q){
  if(isempty(q)){
    printf("queue is empty\n");
    return;
  }
  printf("queue elements: ");
  int i=q->start;
  do{
    printf("%d ",q->items[i]);
    i=(i+1)%MAX_SIZE;
  }while(i!=(q->end+1)%MAX_SIZE);
  printf("\n");
}
int main(){
  cqueue q={{0},-1,-1};
  int choicc,val;
  do{
    printf("\nMenu\n");
    printf("1.enq\n");
    printf("2.deq\n");
    printf("3.print elements\n");
    printf("4.exit\n");
    printf("enter your choice: ");
    scanf("%d",&choicc);
    switch(choicc){
      case 1:
        printf("enter val to enq: ");
        scanf("%d",&val);
        if(enq(&q,val)) {
          printf("%d added to queue.\n", val);
        }else{
          printf("queue is full.\n");
        }
        break;
      case 2:
        val=deq(&q);
        if(val!=-1){
          printf("%d removed from queue.\n", val);
        }else{
          printf("Queue is empty.\n");
        }
        break;
      case 3:
        print_elements(&q);
        break;
      case 4:
        printf("exiting...\n");
        break;
      default:
        printf("Invalid choicc. Please enter a number between 1 and 4.\n");
    }
  } while(choicc!=4);
  return 0;
}