#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fptrin, *fptreven, *fptrodd, *fptrprime;
  int num, success;
  fptreven = fopen("even.txt", "w");
  fptrin =fopen("numbers.txt","r");
  fptrodd=fopen("odd.txt","w");
  fptrprime=fopen("prime.txt","w");
  if(fptreven==NULL || fptrin==NULL || fptrodd==NULL || fptrprime==NULL){
    printf("not exist");
    return EXIT_FAILURE;
  }

  printf("file opened successfully");
  while(fscanf(fptrin, "%d",&num) != -1){
    if(num>10){
      fprintf(fptreven,"%d\n",num);
    }
    else if(num>20){
      fprintf(fptrodd,"%d\n",num);
    }
    else {
      fprintf(fptrprime,"%d\n",num);
    }
  }
  fclose(fptreven);
  fclose(fptrin);
  fclose(fptrodd);
  fclose(fptrprime);

  return 0;
}