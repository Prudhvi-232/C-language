#include <stdio.h>
int addofnatuarlnumbers(int n);
int main(){
  int x;
  printf("enter a number to get sum:");
  scanf("%d",&x);
  printf("sum is %d",addofnatuarlnumbers(x));
  return 0;
}

int addofnatuarlnumbers(int n){
  if(n!=0){
    return n +addofnatuarlnumbers(n-1);
  }
  else return n;
}