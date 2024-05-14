#include<stdio.h>
int main(){
    int a,b,num;
    printf("enter a number");
    scanf("%d",&num);
    a=num%10;
    while (num>0)
    {
         b=num%10;
         num=num/10;
    } 
    printf("sum of first and last digit of number is %d",a+b);
    return 0;
}