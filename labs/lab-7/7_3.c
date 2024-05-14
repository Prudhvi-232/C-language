#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void alterUpper(char *str) {
    bool class = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (class) {
            str[i] = tolower(str[i]);
            } 
        else{
            str[i] = toupper(str[i]);
            }
            class = !class;        
    }
}
int main() {
    char inputString[100];
    printf("Enter a string in lowercase: ");
    fgets(inputString, sizeof(inputString), stdin);

    alterUpper(inputString);

    printf("Modified string: %s", inputString);

    return 0;
}
