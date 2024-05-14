#include<stdio.h>
int main(){
    int a,b,num;
    printf("enter 1 for addition\nenter 2 for minus\nenter 3 for multiplication\nenter 4 for division");
    scanf("%d",&num);
    
    switch (num)
    {
    case /* constant-expression */1:
        printf("enter two values");
    scanf("%d %d",&a,&b);
    
        /* code */printf("%d",a+b);
        break;
    case 2:
    printf("enter two values");
    scanf("%d %d",&a,&b);
    
    printf("%d",&a-&a,b);
    
    printf("%d",a*b);
    break;
    case 4:
    printf("enter two values");
    scanf("%d %d",&a,&b);
    
    printf("%d",a/b);
    break;
    default:
        break;
    }




    return 0;
}