#include<stdio.h>
int main(){
    int i,count;
    for ( i = 5; i >0; i--)
    {
        for (count = i; count<6; count++)
        {
            printf("%d ",i);
        }
        printf("\n");
        
    }
    return 0;
}