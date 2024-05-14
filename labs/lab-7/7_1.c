#include <stdio.h>
#include <ctype.h>
int main(){
    char inputstr[100];
    printf("enter string elements in lower case\n");
    fgets(inputstr,sizeof(inputstr), stdin);

    for(int i=0;inputstr[i] != '\0'; i++) {
        if(islower(inputstr[i])){
            inputstr[i]=toupper(inputstr[i]);
        }
    }
    printf("after changing str to uppercase \n%s",inputstr);

    return 0;
}