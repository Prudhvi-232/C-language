#include <stdio.h>
#include <math.h>
int main() {
    int num,num1,num2,a,i=1,sum=0;
    printf("enter a num:");
    scanf("%d",&num);
    num1 = num;
    num2 = num;
    while(num>9)
    {
        num=num/10;
        i=i+1;
    }
    while(num1>0)
    {
        a=num1%10;
        sum=sum + pow(a,i);
        num1=num1/10;       
    }
    if (sum==num2)
    {
        printf("you entered armstrong number");
    }
    else printf("your number is not a armstrong number");
        
    return 0;
}