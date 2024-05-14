#include<stdio.h>
#include<math.h>
int main(){
  int i,data[10];
  printf("enter a 10 elements");
  for(i=0;i<10;i++){
    scanf("%d",&data[i]);
  }

  return 0;
}
float sd(int data[]){
  float mean,sd;
  mean=0;
  for(int i=0;i<10;i++){
    mean=mean+data[i];
  }
  mean=mean/10;
  sd=0;
  for(int i=0;i<10;i++){
    sd=sd+(data[i]-mean)*(data[i]-mean);
  }
  sd=sqrt(sd/10);
  return sd;
}