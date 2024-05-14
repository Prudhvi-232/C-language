#include <stdio.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int start = -1, last = -1;

void enq(int value) {
    if (last ==MAX_SIZE-1){
        printf("queue is full\n");
    } else{
        if(start==-1){
            start=last=0;
        }else{
            last++;
        }
        queue[last]=value;
        printf("number %d added to the queue.\n",value);
    }
}
int deq(){
    if (start==-1||start>last) {
        printf("queue is empty!\n");
        return -1; 
    }else{
        int value=queue[start];
        start++;
        printf("Removed %d from the queue.\n", value);
        return value;
    }
}
void printq() {
    if (start==-1||start>last){
        printf("queue is empty!\n");
    }else{
        printf("queue contents: ");
        for (int i=start;i<=last;i++) {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int num_of_operations;
    printf("enter the number of operations: ");
    scanf("%d",&num_of_operations);
    int operations[num_of_operations];
    printf("choose the  option (1:enqueue, 2: dequeue, 3: print):\n");
    for(int i=0;i<num_of_operations;i++){
        scanf("%d",&operations[i]);
    }
    for (int i = 0; i < num_of_operations; i++) {
                int value;
        switch (operations[i]) {
            case 1:
                printf("enter value to enq: ");
                scanf("%d", &value);
                enq(value);
                break;
            case 2:
                deq();  
                break;
            case 3:
                printq();
                break;
            default:
                printf("operation is invalueid\n");
                break;
        }
    }
    printq();

    return 0;
}