#include<stdio.h>
int main(){
  int n,i;
  float num[100],sum =0.0,avg;
  printf("Enter the number of elements in the array: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("enter element %d :",i+1);
    scanf("%f",&num[i]);
    sum=sum+num[i];
  }
  avg=sum/n;
  printf("The average is %.2f",avg);
  return 0;
}