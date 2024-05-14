#include <stdio.h>
int main(){
  char str[1000],ch;
  int count=0;
  printf("enter a string :");
  fgets(str,sizeof(str),stdin);
  printf("enter a character to find");
  scanf("%c",&ch);
  for(int i=0;str[i]!='\0';++i){
    if (ch == str[i])
    ++count;
  }
  printf("frequency of %c=%d",ch,count);

  return 0;
}