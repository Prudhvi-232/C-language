#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    printf("enter 1st coordinates:");
    scanf("%d%d",&a,&b);
    printf("enter 2nd coordinates:");
    scanf("%d%d",&c,&d);
    printf("enter 3rd coordinates:");
    scanf("%d%d",&e,&f);
    g=(d-b)/(c-a);
    h=(f-d)/(e-c);
    if (g == h){
        printf("you entered 3 collinear numbers");
    }
    else{
        printf("you entered non collinear numbers");
    }

      return 0 ;
