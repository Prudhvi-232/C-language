#include <stdio.h>
#include <ctype.h>

int main() {
    char inputstr[100];
    
    printf("Enter a strin\n ");
    fgets(inputstr, sizeof(inputstr), stdin);

    for (int i = 0; inputstr[i] != '\0'; i++) {
        if (isupper(inputstr[i])) {
            inputstr[i] = tolower(inputstr[i]);
        } else if (islower(inputstr[i])) {
            inputstr[i] = toupper(inputstr[i]);
        }
    }

    printf("after changing string\n %s", inputstr);

    return 0;
}
