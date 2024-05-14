#include <stdio.h>
#include <math.h>
int main() {
   int i, j=0,k=0, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i)
    {        //1,2,3, 
      for (j=0; j < rows-i; j++)
      {
         printf(" ");
      }
      for (k = 0; k < (2*i) -1; k++)
      {
         printf("*");
      }
      printf("\n");
    } 
   return 0;
}
