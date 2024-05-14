#include <stdio.h>
int main() {
    FILE *fp;
    int c;
    char ch[1000];
   
    // open the current input file
    fp = fopen(__FILE__,"r");

    do {
         c = getc(fp);   // read character 
         putchar(c);     // display character
    }
    while(c != EOF);  // loop until the end of file is reached
    // fgets(ch, 1000,stdin);
    printf("the matter is %s",ch);
    
    fclose(fp);
    return 0;
}