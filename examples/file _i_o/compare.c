#include<stdio.h>
#include<stdlib.h>
int main (){
  FILE *fptr1,*fptr2;
  fptr1=fopen("file1.txt","r");
  fptr2=fopen("file2.txt","r");
  if(fptr1==NULL || fptr2==NULL){
    printf("not exist");
    return EXIT_FAILURE;
  }
   return 0;
}