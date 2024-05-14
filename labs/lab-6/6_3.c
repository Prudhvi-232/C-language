#include <stdio.h>
int main() {
    char inputString[100];
    int charCount[256] = {0};  
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    int length = strlen(inputString);
    
    printf("\nCharacter Frequencies:\n");
    
    for (int i = 0; i < length; i++) {
        char c = inputString[i];
        if (isprint(c)) {
            charCount[(int)c]++;
        }
    }
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            printf("%c: ", (char)i);
            for (int j = 0; j < charCount[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }


    return 0;
}
