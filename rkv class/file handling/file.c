#include<stdio.h>  
int main( )  
{
  FILE *fptr;
  fptr = fopen("newfile.txt","w");
  // fclose(fptr);
  // char ch;
  // fscanf(fptr,"%c",&ch);
  // printf(" character is %c",ch);
  // fscanf(fptr,"%c",&ch);
  // printf(" character is %c",ch);
  // if(fptr==NULL)printf("not exist");
  // else fclose(fptr);
  printf("emter name:");
  char name[20];
  scanf("%s",name);
  fprintf(fptr,"%s",name);


  return 0;
}   