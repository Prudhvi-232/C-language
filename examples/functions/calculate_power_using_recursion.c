#include <stdio.h>
int power(int ,int);
int main (){
  int base,powe;
  printf("enter base and power:");
  scanf("%d%d",&base,&powe);
  printf("power is %d",power(base,powe));

  return 0;
}

int power(int base,int p){
  if(p!=0){
    return base*power(base,p-1);
  }
  else return 1;
}