#include<stdio.h>
#include <stdlib.h>
int main()
{
  FILE *fptr;
  char ch;
  fptr = fopen("file2.txt", "r");
  if (fptr == NULL)
  {
    printf("failed to execute\n");
    return EXIT_FAILURE;
  }
  printf("file opened sucessfully\n");
  do
  {
    ch = fgetc(fptr);
    // putchar(ch);
  } while (ch != EOF);

  fclose(fptr);

  return 0;
}