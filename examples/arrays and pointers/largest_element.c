#include<stdio.h>
int main(){
  int n,arr[100];
  printf("enter the no of the elements");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",arr+i);
  }
  for(int i=0;i<n;i++){
    if(arr[0]<arr[i]){
      arr[0]=arr[i];
    }
  }
  printf("the largest number is %d",arr[0]);


  return 0;
}