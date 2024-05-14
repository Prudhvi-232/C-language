#include<stdio.h>
int main(){
  char man[]="hello my name is prudhvi";
  int i;
  for(i=0;man[i]!='\0';i++);
  printf("length of string = %d",i);


  return 0;
}