#include <stdio.h>
#include <string.h>

void revwords(char*str) {
    int len=strlen(str);
    int s,e;
    for(s=0, e=len-1; s<e;s++,e--) {
        char temp=str[s];
        str[s]=str[e];
        str[e]=temp;
    }
    s=0;
    for (int i=0; i<len; i++) {
        if(str[i] == ' ') {
            e=i-1;
            while(s<e){
                char temp=str[s];
                str[s]=str[e];
                str[e]=temp;
                s++;
                e--;
            }
            s =i+1;
        }
    }
    e =len-1;
    while (s<e) {
        char temp =str[s];
        str[s] =str[e];
        str[e] =temp;
        s++;
        e--;
    }
}
int main() {
    char inputstr[500];
    printf("Enter a string: ");
    fgets(inputstr, sizeof(inputstr), stdin);
    if (inputstr[strlen(inputstr) - 1] == '\n') {
        inputstr[strlen(inputstr) - 1] = '\0';
    }
    revwords(inputstr);
    printf("Output: %s\n", inputstr);
    return 0;
}
