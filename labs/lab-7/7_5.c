#include <stdio.h>

int main() {
    char inputstr[100];
    char characterToRemove;
    char resultString[100];
    int inputLength = 0;
    int resultLength = 0;

    printf("Enter a string: ");
    fgets(inputstr, sizeof(inputstr), stdin);

    printf("Enter the character to be removed: ");
    scanf(" %c", &characterToRemove);

    while (inputstr[inputLength] != '\0') {
        inputLength++;
    }

    for (int i = 0; i < inputLength; i++) {
        if (inputstr[i] != characterToRemove) {
            resultString[resultLength] = inputstr[i];
            resultLength++;
        }
    }

    resultString[resultLength] = '\0';

    printf("Modified string: %s\n", resultString);

    return 0;
}
