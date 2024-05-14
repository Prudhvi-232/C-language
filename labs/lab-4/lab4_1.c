#include<stdio.h>
int main(){
    int num,num1=0,i;
    while (i=1)
     {
        printf("enter a number or to exit enter 0 : ");
        scanf("%d",&num);
        if (num==0)
        break;    
        if (num1<num)
           num1=num;
     }
     printf("the largest number among the following is:%d",num1);
    return 0;
}
