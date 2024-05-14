#include<stdio.h>
int multiplynumbers(int n);
int main(){
  int i;
  printf("enter number :");
  scanf("%d",&i);
  printf("factorial is:%d",multiplynumbers(i));

  return 0;
}
int multiplynumbers(int n){
  if(n>1){
    return n* multiplynumbers(n-1);
  }
  else return n;
}