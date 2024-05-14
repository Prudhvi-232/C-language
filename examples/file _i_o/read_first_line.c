#include<stdio.h>
#include<stdlib.h>
int main(){
  char c[1000];
  FILE*fptr;
  fptr=("file.txt","w");
  if(fptr==NULL){
    printf("error");
    return EXIT_FAILURE;
  }
  fscanf(fptr,"%[^\n]",c);
  printf("data is %s",c);

  fclose(fptr);


  return 0;
}