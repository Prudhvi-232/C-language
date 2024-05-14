#include<stdio.h>
int main()
{
    int i;
    float fact=1,sum=0;
    for(i=1;i<8;i++){
        fact=fact*i;
        sum=sum+(i/fact);
    }
    printf("%f", sum);
    return 0;
}