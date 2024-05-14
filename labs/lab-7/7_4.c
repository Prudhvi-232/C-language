#include <stdio.h>
#include <stdbool.h>

int main() {
    char inputstr[100];
    int wordCount = 0;
    bool inWord = false;

    printf("Enter a string: ");
    fgets(inputstr, sizeof(inputstr), stdin);

    for (int i = 0; inputstr[i] != '\0'; i++) {
        if (isalnum(inputstr[i])) {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    printf("Number of words: %d\n", wordCount);

    return 0;
}
