#include<stdio.h>
int main(){
  int a[100][100],b[100][100],sum[100][100],r,c;
  printf("num of rows and columns");
  scanf("%d",&r);
  scanf("%d",&c);
  printf("enter the elments in the matrices :");
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("enter the elments in the matrices :");
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&b[i][j]);
    }
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      sum[i][j]=a[i][j]+b[i][j];
    }
  }
  printf("the sum ofthe two matrices is:\n");
  for(int i=0;i<r;i++){
    for( int j=0;j<c;j++){
      printf("%d ",sum[i][j]);
    }
    printf("\n");
  }


  return 0;
}