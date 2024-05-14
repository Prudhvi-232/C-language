#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fptr;
    char str[1000];
    fptr=fopen("file.txt","w");
    if(fptr==NULL){
      printf("Error!");
      return EXIT_FAILURE;
    }
    printf("enter the numbers that you want to enter in the file");
    fgets(str,1000,stdin);
    fprintf(fptr, "%s", str);
    printf("sucessfully executed");
    fclose(fptr);
  return 0;
}