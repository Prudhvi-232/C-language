#include <stdio.h>

struct node{
    int data;
    struct node *next;
};
struct node *head, *ptr;

void begininsert();
void lastinsert();

int main() {
    begininsert();
    begininsert();
    begininsert();
    lastinsert();
    display();

    return 0;
}

void begininsert(){
    ptr = (struct node *)malloc(sizeof(struct node *));
    int item;
    printf("enter a value");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
}
void lastinsert(){
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("enter a value");
    scanf("%d", &item);
    if(head==NULL){
        head = ptr;
        ptr->data = item;
        ptr->next = NULL;
    }
    else{
        ptr->data = item;
        ptr->next = NULL;
        struct node *temp;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }

}

void randominsert(){
    struct node *ptr,*temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int i, loc, item;
    printf("enter a element to insert");
    scanf("%d", &item);
    printf("enter loc to insert");
    scanf("%d", &loc);
    ptr->data = item;
    temp = head;
    for (int i = 0; i < loc;i++){
        temp = temp->next;
        if(temp->next==NULL){
            printf("not able to insert");
            return;
        }
        ptr->next = temp->next;
        temp->next = ptr;

    }
}

void randomdelete(){
    struct node *ptr, *temp;
    int loc, i;
    printf("enter the location of the element");
    scanf("%d", &loc);
    ptr = head;
    
}

void begindelete(){
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}
void lastdelete(){
    struct node *ptr,*ptr1;
    ptr = head;
    while(ptr->next != NULL){
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
}

void display(){
    struct node *ptr;
    // ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    if(ptr==NULL){
        printf("nothing to print");
    }
    else{
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}