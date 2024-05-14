#include <stdio.h>
#include <string.h>

void removeWord(char *str, const char *word) {
    int i, j, wordlen, len, found;
    wordlen = strlen(word);
    len = strlen(str);
    for (i = 0; i <= len - wordlen; ++i) {
        found = 1;
        for (j = 0; j < wordlen; ++j) {
            if (str[i + j] != word[j]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            for (j = i; j <= len - wordlen; ++j) {
                str[j] = str[j + wordlen];
            }
            len -= wordlen;
            i -= 1; 
        }
    }
    str[len] = '\0';
}

int main() {
    char inputstring[1000];
    char wordtoremove[100];

    printf("Enter the input string: ");
    fgets(inputstring, sizeof(inputstring), stdin);

    printf("Enter the word to remove: ");
    scanf("%s", wordtoremove);
    removeWord(inputstring, wordtoremove);
    printf("Output: %s\n", inputstring);
    return 0;
}