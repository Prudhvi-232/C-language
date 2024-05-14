#include<stdio.h>
#include<math.h>
int main(){
    int i,j,space,b,rows,coef=1;
    printf("number of rows is required:");
    scanf("%d",&b);
    rows= b-1;
    for ( i = 0; i <= rows; i++)
    {
        for(space=0;space <=(rows-i) ;space++){
            printf(" ");
        }
        for(j=0; j <= i; j++)
        {
            if (j==0 || i==0)
            coef = 1;
            else
            coef = coef*(i-j+1)/j;

            printf(" %d", coef);
        }
        printf("\n");
    }
     return 0;
}
