#include <stdio.h>
#include <ctype.h>
int isValidPassword(const char *password) {
    int lower=0, upper=0, empty=0;
    while(*password !='\0'){
        if(islower(*password)){
            lower=1;
        }
        else if(isupper(*password)){
            upper=1;
        } 
        else if(!isalpha(*password)){
            empty=1;
        }
        password++;
    }
    if (lower && upper && empty) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    if(isValidPassword(password)){
        printf("your password is valid \n");
    }else{
        printf("your password is invalid \n");
    }
    return 0;
}
