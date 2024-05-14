#include <stdio.h>
int main (){
  char sen[200];
  FILE *fptr;
  fptr=fopen("program.txt","w");
  
  if(fptr==NULL){
    printf("Error! opening file");
    exit(1);
  }
  printf("\nEnter the sentence: ");
  fgets(sen,sizeof(sen),stdin);
  fprintf(fptr,"%s",sen);
  fclose(fptr);

  return 0;
}