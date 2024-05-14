#include <stdio.h>
int main(){
  char line[200];
  int vowels,consonants,spaces,digits;
  vowels=consonants=spaces=digits=0;
  printf("print the array statement:");
  fgets(line,sizeof(line),stdin);
  for (int i=0;line[i]!=0;i++){
    line[i]= tolower(line[i]);
    if(line[i]=='a' || line[i]=='e'||line[i]=='i'||line[i]=='o'||line[i]=='u'){
      vowels++;
    }
    else if(line[i]>='a' && line[i]<='z'){
      consonants++;
    }
    else if(line[i]>='0' && line[i]<='9'){
      digits++;
    }

    else if(line[i]==' '){
      spaces++;
    }
  }
  printf("vowels %d",vowels);
  printf("consonants %d",consonants);
  printf("spaces %d",spaces);
  printf("integers %d",digits);

  return 0;
}