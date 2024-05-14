#include<stdio.h>
void SUM (int ,int );
int main() {{
    int a,b;
    printf("enter the values of a anb b\n");
    scanf("%d %d",&a,&b);
    SUM(a,b);
    printf("hello");
    return 0;
} 

void SUM (int c,int d);
    int sum,c,d;
    sum = c + d ;
    printf("The sum of the first and second is %d",sum);

}