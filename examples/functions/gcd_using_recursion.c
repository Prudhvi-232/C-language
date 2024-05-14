#include<stdio.h>
int gcd(int,int);
int main(){
  int x,y;
  printf("enter two numbers to find gcd:");
  scanf("%d%d",&x,&y);
  // if(x<y){
  //   x=x+y;
  //   y=x-y;
  //   x=x-y;
  // }
  printf("gcd is %d",gcd(x,y));

  return 0;
}

int gcd(int n1,int n2){
  if(n2!=0){
    return gcd(n2,n1%n2);
  }
  else 
  return n1;
}