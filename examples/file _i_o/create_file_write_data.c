#include <stdio.h>
#include <stdlib.h>

int main()
{
    char data[1000];
    FILE *fptr;
    fptr = fopen("file2.txt", "w");
    if(fptr == NULL){
      printf("failed to execute");
      return EXIT_FAILURE;
    } 
    printf("enter data in to the file ");
    fgets(data, 1000, stdin);
    fputs(data, fptr);
    fclose(fptr);

    return 0;
}