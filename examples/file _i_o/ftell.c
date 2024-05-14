#include <stdio.h>  
#include <conio.h>  
void main (){  
   FILE *fp;  
   int length; 
   char text[1000]; 
  //  clrscr();  
   fp = fopen("file.txt", "r");  
  //  fseek(fp, 0, SEEK_SET);  
   printf("%s\n",fgets(text,1,fp)); 
   fseek(fp, 0, SEEK_SET);  
   length = ftell(fp);  
  
   fclose(fp);  
   printf("Size of file: %d bytes", length);  
  //  getch();  
}  