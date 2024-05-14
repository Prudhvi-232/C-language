#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    printf("enter radius value:");
    scanf("%d",&a);
    printf("\nenter coordinates of center:");
    scanf("%d%d",&c,&d);
    printf("enter your coordinates:");
    scanf("%d%d",&e,&f);
    g = sqrt(pow((c-e),2)+pow((d-f),2));
    if(g>a)
        printf("point lies outside circle");
    
    else if(g == a)
        printf("point lies on the circle");
    
    else
        printf("point lies inside circle");
    
    return 0 ;
    }