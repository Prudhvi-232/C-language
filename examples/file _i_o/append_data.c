#include<stdio.h>
#include<stdlib.h>
int main(){
  char datatoappend[1000];
  FILE *fptr;
  fptr=fopen("file1.txt", "a");
  if(fptr==NULL){
    printf("failed to execute");
    return EXIT_FAILURE;
  }
  printf("enter a words to append ");
  // fflush(stdin);
  fgets(datatoappend, 1000, stdin);
  
  fputs(datatoappend, fptr);
  fptr=freopen("file1.txt","r",fptr);
  printf("Changed file contents:\n\n");
  readFile(fptr);
  fclose(fptr);
  return 0;
}