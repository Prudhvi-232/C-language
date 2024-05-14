#include<stdio.h>
int main(){
    int a,f=0,s=1,i;
    printf("enter a number:");
    scanf("%d",&a);
    printf("%d,%d",f,s);
    int term = f +s;
    for(i=0;i<(a-2);i++){             
        printf(",%d",term);
        f=s;
        s=term;
        term = s +f;
        
        
    }






    return 0;
}