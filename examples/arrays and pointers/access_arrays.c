#include<stdio.h>
int main(){
  int data[5];
  printf("enter the elements:\n");
  for(int i=0;i<5;i++){
    scanf("%d",data+i);
  }
  for(int i=0;i<5;i++){
    printf("%d",*(data+i));
  }

  return 0;
}