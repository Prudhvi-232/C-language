#include <stdio.h>
int main() {
    FILE *fp;
    int c;
   
    // open the current input file
    fp = fopen(__FILE__,"r");

    do{
      c=getc(fp);
      // putchar(c);
    }
    while(c!=EOF);
    fclose(fp);
    return 0;
}