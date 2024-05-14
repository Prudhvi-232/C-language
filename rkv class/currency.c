#include<stdio.h>
int main(){
    int num;
    printf("enter a number:");
    scanf("%d",&num);
    int a,b,c,d,e,f,g,h,i,j;
    a =num/2000;
    b =num %2000;
    c =b / 500;
    d =b%500;
    e =d/100;
    f =d%100;
    g =f/10;
    h =f%10;
    i =h%1;
    j =h/1;    printf("you got this many notes\n%d 2000 notes\n%d 500 notes\n%d 100 notes\n%d 10 notes\n%d 1 rupee coins",a,c,e,g,j);

    



    

        return 0;
   }


    